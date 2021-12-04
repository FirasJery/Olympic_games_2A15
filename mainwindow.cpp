#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <joueur.h>
#include "exportexcelobject.h"
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
    ui->tableView->setModel(ptmp.afficher());
    //controle saisir
    ui->id->setValidator(new QIntValidator(1,99,this));
    ui->num->setValidator(new QIntValidator(10000000,99999999,this));
    QSqlQueryModel *modell=new QSqlQueryModel();
            modell->setQuery("select NOM from COMPETITIONS order by NOM");
    ui->comboBox->setModel(modell);




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString nationallite=ui->nationallite->text();
    int age=ui->age->text().toInt();
    int num=ui->num->text().toInt();
    joueur j(nom ,prenom,nationallite,id ,num,age );
    bool test=j.ajouter();
    if (test)
    {

        ui->tableView->setModel(ptmp.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("Ajout effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
  int id=ui->id->text().toInt();
     bool test=ptmp.supprimer(id);
     if (test)
     {
         ui->tableView->setModel(ptmp.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                      QObject ::tr("suppression effectué\n"
                                   "click cancel to exit"),
                 QMessageBox:: Cancel);

    }
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("try again.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
     }
}

void MainWindow::on_modifier_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString nationallite=ui->nationallite->text();
    int age=ui->age->text().toInt();
    int num=ui->num->text().toInt();

              joueur j(nom ,prenom,nationallite,id ,num,age );
           bool test=j.modifier(id);

           if (test)

           {

                  ui->tableView->setModel(ptmp.afficher());

               QMessageBox :: information (nullptr, QObject ::tr("OK"),

                            QObject ::tr("modifier effectué\n"

                                         "click cancel to exit"),

                       QMessageBox:: Cancel);



       }

           else

           {

               QMessageBox::critical(nullptr,QObject::tr("not ok"),

                                    QObject::tr("try again.\n"

                                                "click cancel to exit."),QMessageBox::Cancel);

           }
}

void MainWindow::on_tri_id_clicked()
{
            ui->tableView->setModel(ptmp.tri());
}

void MainWindow::on_tri_age_clicked()
{
            ui->tableView->setModel(ptmp.triage());
}



void MainWindow::on_nationallite_2_clicked()
{
    ui->tableView->setModel(ptmp.triNationallite());
}


void MainWindow::on_pushButton_7_clicked()
{
    QString nom=ui->cherche_nom->text();
      if (nom.isEmpty()) {
          QMessageBox::information(this, tr("Empty Field"),
              tr("Please enter a Name."));
          return;
      } else {
      ui->tableView->setModel(ptmp.cherche_nom(nom));
      }
}








void MainWindow::on_chercher_id_clicked()
{
    int id=ui->cherche_nom->text().toInt() ;
      if (id == NULL) {
          QMessageBox::information(this, tr("Empty Field"),
              tr("Please enter a Name."));
          return;
      } else {
      ui->tableView->setModel(ptmp.cherche_id(id));
      }

}

void MainWindow::on_chercher_num_clicked()
{
    int num=ui->cherche_nom->text().toInt() ;
      if (num == NULL) {
          QMessageBox::information(this, tr("Empty Field"),
              tr("Please enter a Name."));
          return;
      } else {
      ui->tableView->setModel(ptmp.cherche_num(num));
      }
}

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->id_2->text().toInt();
    QString competition=ui->comboBox->currentText();
    int id_competition;
    qInfo() << competition;
    QSqlQuery q;

            q.exec("select CODE_COMPETITION from COMPETITIONS where NOM ='"+competition+"'");
            while(q.next()){

                id_competition = q.value(0).toInt();
                qInfo() << id_competition;
            }
            bool test=ptmp.affecter(id,id_competition);
            if (test)

            {

                   ui->tableView->setModel(ptmp.afficher());

                QMessageBox :: information (nullptr, QObject ::tr("OK"),

                             QObject ::tr("Affectation effectué\n"

                                          "click cancel to exit"),

                        QMessageBox:: Cancel);



        }

            else

            {

                QMessageBox::critical(nullptr,QObject::tr("not ok"),

                                     QObject::tr("try again.\n"

                                                 "click cancel to exit."),QMessageBox::Cancel);

            }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // background //
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));

              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //couleurs
              amande->setName("par Age ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));

               //axe des abscisses
              QVector<double> ticks;
              QVector<QString> labels;
              ptmp.statistique(&ticks,&labels);

              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // axe des ordonnées
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5);
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // ajout des données  (statistiques de la quantité)//

              QVector<double> PlaceData;
              QSqlQuery q1("select AGE from JOUEUR");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);

              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_export_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
            QString sheetName="test";
    ExportExcelObject obj(fileName, sheetName, ui->tableView);
    obj.addField(0, tr("ID_JOUEUR"), "int");
    obj.addField(1, tr("NOM"), "char(20)");
    obj.addField(2, tr("PRENOM"), "char(20)");
    obj.addField(3, tr("AGE"), "int");
    obj.addField(4, tr("NATIONALLITE"), "char(20)");
    obj.addField(5, tr("NUMERO"), "int");
    obj.export2Excel();

}

void MainWindow::on_pushconnect_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonmodif_clicked()
{
    int id = ui->lineidg->text().toInt();
        QString nom= ui->linenomg->text();
        int budget = ui->linebudgetg->text().toInt();
        QString type;
        if (budget >= 10000)
         type= "Gold";
        else type ="Normal";
        int etat = ui->lineetatg->text().toInt();
        int codec = ui->linecompg->text().toInt();
        SPONSORS S(id,nom,type,codec,budget,etat);
        bool test=S.Modifier(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("modif successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("modif failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->tableViewg->setModel(Stmp.Afficher());

}

void MainWindow::on_pushButtonajout_clicked()
{
    bool test;
        int id = ui->lineidg->text().toInt();
        QString nom= ui->linenomg->text();
        int budget = ui->linebudgetg->text().toInt();
        QString type;
        if (budget >= 10000)
         type= "Gold";
        else type ="Normal";
        int etat = ui->lineetatg->text().toInt();
        int codec = ui->linecompg->text().toInt();
        SPONSORS S(id,nom,type,codec,budget,etat);
        test=S.Ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("ajout failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->tableViewg->setModel(Stmp.Afficher());

}

void MainWindow::on_pushButtonsupp_clicked()
{
    int id = ui->lineidg->text().toInt();
        bool test=Stmp.Supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("supp successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("supp failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->tableViewg->setModel(Stmp.Afficher());
}

void MainWindow::on_push_trig_clicked()
{
    QString tst;
           if (ui->radioButtong->isChecked()) tst="ASC";
           else if (ui->radioButton2g->isChecked()) tst="DESC";

           switch (ui->comboBox->currentIndex()) {
           case 0:
               ui->tableViewg->setModel(Stmp.Triparnom(tst));
               break;
           case 1:
               ui->tableViewg->setModel(Stmp.TriEtat(tst));
               break;
           case 2:
               ui->tableViewg->setModel(Stmp.TriBudget(tst));
               break;
           }
}


void MainWindow::on_push_exportg_clicked()
{
    bool test =Stmp.Export(ui->lineexportg->text());

        if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Export effectué\n""Click Ok to exit."), QMessageBox::Ok);
            }
            else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Export non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_push_alerteg_clicked()
{
    if (Stmp.alerte()>0)
                {
                    QString notif=QString::number(Stmp.alerte())+" Frais non encore deposés.\n""Click Ok to exit.";
                    QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
                }
        else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Tous les frais sont deposés\n""Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_push_impressiong_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tableViewg->model()->rowCount();
                        const int columnCount = ui->tableViewg->model()->columnCount();
                        QString TT = QDate::currentDate().toString("dd/MM/yyyy");
                        out <<"<html>\n"
                              "<head>\n"
                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            << "<title>SPONSORS<title>\n "
                            << "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<h1 style=\"text-align: center;\"><strong>  SPONSORS  "+TT+"</strong></h1>"
                            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                              "</br> </br>";

                        out << "<thead><tr bgcolor=#d6e5ff>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableViewg->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableViewg->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";


                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tableViewg->isColumnHidden(column)) {
                                    QString data =ui->tableViewg->model()->data(ui->tableViewg->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table>\n"
                            "</body>\n"
                            "</html>\n";

                        QTextDocument *document = new QTextDocument();
                        document->setHtml(strStream);

                        QPrinter printer;

                        QPrintDialog *test = new QPrintDialog(&printer, NULL);
                        if (test->exec() == QDialog::Accepted) {
                            document->print(&printer);
                        }

                        delete document;
}

void MainWindow::on_linerechg_textChanged(const QString &arg1)
{
    ui->tableViewg->setModel(Stmp.recherche(arg1));
}
