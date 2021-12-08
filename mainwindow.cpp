#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <joueur.h>
#include "exportexcelobject.h"
#include <QIntValidator>
#include "reclamation.h"
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex(0);// use this to change the page in the stacked widget

//partierania
  ui->tableView->setModel(ptmp.afficher());
  //controle saisir
  ui->id->setValidator(new QIntValidator(1,99,this));
  ui->num->setValidator(new QIntValidator(10000000,99999999,this));
  QSqlQueryModel *modell=new QSqlQueryModel();
  modell->setQuery("select NOM from COMPETITIONS order by NOM");
  ui->comboBox->setModel(modell);
  /////////////////////////////////////////////////////////////////////////

//partie ghassen
    ui->tableViewg->setModel(Stmp.Afficher());
    ///////////////////////////////////////////////////////////////

//partie firas
    ui->tabWidgetf->setCurrentIndex(0);
    ui->tableViewf->setModel(rmp.afficher());

///////////////////////////////////////////////////////////////
//partie ines
        ui->tabWidget_i->setCurrentIndex(0);
       ui->le_id->setValidator(new QIntValidator(0,9999999,this)); //controle de saisie
       ui->le_age->setValidator(new QIntValidator(1,100,this));
       ui->tab_spectateur->setModel(S.afficher());
//////////////////////////////////////////////////////////////////


}

MainWindow::~MainWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////rania
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
              ui->plot_2->setBackground(QBrush(gradient));

              QCPBars *amande = new QCPBars(ui->plot_2->xAxis, ui->plot_2->yAxis);
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
              ui->plot_2->xAxis->setTicker(textTicker);
              ui->plot_2->xAxis->setTickLabelRotation(60);
              ui->plot_2->xAxis->setSubTicks(false);
              ui->plot_2->xAxis->setTickLength(0, 4);
              ui->plot_2->xAxis->setRange(0, 8);
              ui->plot_2->xAxis->setBasePen(QPen(Qt::white));
              ui->plot_2->xAxis->setTickPen(QPen(Qt::white));
              ui->plot_2->xAxis->grid()->setVisible(true);
              ui->plot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot_2->xAxis->setTickLabelColor(Qt::white);
              ui->plot_2->xAxis->setLabelColor(Qt::white);

              // axe des ordonnées
              ui->plot_2->yAxis->setRange(0,10);
              ui->plot_2->yAxis->setPadding(5);
              ui->plot_2->yAxis->setLabel("Statistiques");
              ui->plot_2->yAxis->setBasePen(QPen(Qt::white));
              ui->plot_2->yAxis->setTickPen(QPen(Qt::white));
              ui->plot_2->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot_2->yAxis->grid()->setSubGridVisible(true);
              ui->plot_2->yAxis->setTickLabelColor(Qt::white);
              ui->plot_2->yAxis->setLabelColor(Qt::white);
              ui->plot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // ajout des données  (statistiques de la quantité)//

              QVector<double> PlaceData;
              QSqlQuery q1("select AGE from JOUEUR");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);

              ui->plot_2->legend->setVisible(true);
              ui->plot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot_2->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot_2->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);
              ui->plot_2->legend->setFont(legendFont);
              ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
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
/////////////////////////////////////////////////////////////////////////////stackedwidget
void MainWindow::on_pushconnect_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    if(ui->stackedWidget->currentIndex()==3){
    QSqlQueryModel *model=new QSqlQueryModel();
    model = rmp.afficher();
    QDate d;
    int count=0;
    for (int i = 0; i < model->rowCount(); i++) {
        QDate k=model->data(model->index(i,4)).toDate();
        if ((k.addDays(3) < d.currentDate()) && (model->data(model->index(i,2)).toString() != "done"))
        {
            count++;
        }
    }
        if (count != 0){
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            QString res=QString::number(count);
            notifyIcon->show();
            notifyIcon->showMessage("warning ! ","you have "+res+" reclamation not done",QSystemTrayIcon::Information,15000);
        }}
}
/////////////////////////////////////////////////////////////////////////////ghassen
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
/////////////////////////////////////////////////////////////////////////firas
void MainWindow::on_push_ajoutf_clicked()
{
        QString categorie=ui->line_categorief->text();
        QString contenu=ui->line_contenuf->text();
        QDate d=ui->datef->date();
        QString mail=ui->line_mailf->text();
        int id_j=ui->line_idjf->text().toInt();



        Reclamation R(1,categorie,"just added",contenu,d,mail,id_j);

        bool test=R.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(rmp.afficher());
            QSqlQueryModel *model=new QSqlQueryModel();
            model = rmp.afficher();
            int id = model->data(model->index(model->rowCount()-1,0)).toInt();
            test=R.ajouter_mod(id,"ajout",QDateTime::currentDateTime());

    }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("ajout failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_push_modifierf_clicked()
{
    int id_upt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
        QString categorie=ui->line_categorief->text();
        QString contenu=ui->line_contenuf->text();
        QString etat=ui->line_etatf->text();
        QDate d=ui->datef->date();
        QString mail=ui->line_mailf->text();
        int id_j=ui->line_idjf->text().toInt();
        Reclamation R(id_upt,categorie,etat,contenu,d,mail,id_j);



        bool test=R.modifier(id_upt);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("update successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(rmp.afficher());
            test=R.ajouter_mod(id_upt,"modification",QDateTime::currentDateTime());

        }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_push_afficherf_clicked()
{
    ui->tableView->setModel(rmp.afficher());
}

void MainWindow::on_push_supprimerf_clicked()
{
    bool i;
        int id_del;
        id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();

        i=rmp.supprimer(id_del);
        if(i)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("delete successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(rmp.afficher());
            rmp.ajouter_mod(id_del,"suppression",QDateTime::currentDateTime());

        }
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("delete failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushtrif_clicked()
{
    QString cls;
        if (ui->radio_trif->isChecked()) cls="ASC";
        else if (ui->radio_trif2->isChecked()) cls="DESC";

        switch (ui->comboBox->currentIndex()) {
        case 0:
            ui->tableView->setModel(rmp.TriCategorie(cls));
            break;
        case 1:
            ui->tableView->setModel(rmp.TriDate(cls));
            break;
        case 2:
            ui->tableView->setModel(rmp.TriEtat(cls));
            break;
        }
}

void MainWindow::on_line_rechf_textChanged(const QString &arg1)
{
    ui->tableView->setModel(rmp.recherche(arg1));
}

void MainWindow::on_push_sendf_clicked()
{
    smtp = new Smtp("gestion.recs@gmail.com" , "gestiongestion", "smtp.gmail.com",465);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        msg=ui->message_mailf->toPlainText();

        smtp->sendMail("firas_test",ui->a_mailf->text(),ui->objet_mailf->text(),msg);

        QMessageBox::information(nullptr, QObject::tr("SENT"),
                                 QObject::tr("Email Sent Successfully.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableViewf_doubleClicked(const QModelIndex &index)
{
    if (index.data().toString() == ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString()){
           ui->tabWidget->setCurrentIndex(1);
           ui->a_mailf->setText(index.data().toString());
       }
}

void MainWindow::on_tabWidgetf_currentChanged(int index)
{
    if(index==2)
            ui->tableView_historiquef->setModel(rmp.afficher_mod());
}
//////////////////////ines///



void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int age=ui->le_age->text().toInt();
    int nbr_ticket=ui->le_nbr_ticket->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString type_classe=ui->le_type_classe->text();

    Spectateur S(id,age,nbr_ticket,adresse,type_classe);
    bool test=S.ajouter();
    QMessageBox msgBox;
    if(test){
         ui->tab_spectateur->setModel(S.afficher()); //remplir tab
        msgBox.setText("Ajout avec succes.");

    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Spectateur S1;
       S1.setid(ui->le_id_2->text().toInt());
       bool test=S1.supprimer(S1.getid());
       QMessageBox msgBox;
       if(test)
          { msgBox.setText("Suppression avec succes.");
           ui->tab_spectateur->setModel(S.afficher());
       }
       else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id_2->text().toInt();
        int age=ui->le_age_2->text().toInt();
        int nbr_ticket=ui->le_nbr_ticket_2->text().toInt();
       QString adresse=ui->le_adresse_2->text();
       QString type_classe=ui->le_type_classe_2->text();

        Spectateur S(id,age,nbr_ticket,adresse,type_classe);
            bool test=S.modifier();

                QMessageBox msgBox;
                    if(test)
                    {
                        ui->tab_spectateur->setModel(S.afficher());
                        msgBox.setText("modification avec succes");
                    }
                        else
                        msgBox.setText(("echec de modification"));

                        msgBox.exec();
}

void MainWindow::on_pb_tri_ID_clicked()
{
     ui->tab_spectateur->setModel(S.trinom());
}

void MainWindow::on_pb_tri_AGE_clicked()
{
     ui->tab_spectateur->setModel(S.triage());
}

void MainWindow::on_pb_tri_nbr_ticket_clicked()
{
    ui->tab_spectateur->setModel(S.trinbrticket());
}

void MainWindow::on_pb_recherche_ID_clicked()
{
    int id=ui->lineEdit->text().toInt();
            if (id==0) {
                QMessageBox::information(this, tr("Empty Field"),
                    tr("Please enter a Number."));
                return;
            } else {
            ui->tab_spectateur->setModel(S.recherche_ID(id));
            }
}

void MainWindow::on_pb_recherche_age_clicked()
{
    int age=ui->lineEdit_2->text().toInt();
            if (age==0) {
                QMessageBox::information(this, tr("Empty Field"),
                    tr("Please enter a Number."));
                return;
            } else {
            ui->tab_spectateur->setModel(S.recherche_age(age));
            }
}

void MainWindow::on_pb_recherche_nbr_ticket_clicked()
{
    int nbr_ticket=ui->lineEdit_3->text().toInt();
           if (nbr_ticket==0) {
               QMessageBox::information(this, tr("Empty Field"),
                   tr("Please enter a Number."));
               return;
           } else {
           ui->tab_spectateur->setModel(S.recherche_nbr_ticket(nbr_ticket));
           }
}

void MainWindow::on_pb_mail_clicked()
{
    Smtp* smtp = new Smtp("ines.mabrouk@esprit.tn", "201JFT3246", "smtp.gmail.com", 465);
         connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
         QString a=ui->Linemail->text();
         QString b=ui->Lineobjet->text();
         QString c=ui->plaincontenu->toPlainText();

         smtp->sendMail("ines.mabrouk@esprit.tn", a , b,c);
}

void MainWindow::on_tabWidget_i_currentChanged(int index)
{
    // set dark background gradient:
                     QLinearGradient gradient(0, 0, 0, 400);
                     gradient.setColorAt(0, QColor(90, 90, 90));
                     gradient.setColorAt(0.38, QColor(105, 105, 105));
                     gradient.setColorAt(1, QColor(70, 70, 70));
                     ui->plot_2->setBackground(QBrush(gradient));


                     // create empty bar chart objects:
                     QCPBars *amande = new QCPBars(ui->plot_2->xAxis, ui->plot_2->yAxis);
                     amande->setAntialiased(false);
                     amande->setStackingGap(1);
                      //set names and colors:
                     amande->setName("Repartition des spectateurs selon age ");
                     amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                     amande->setBrush(QColor(0, 168, 140));
                     // stack bars on top of each other:

                     // prepare x axis with country labels:
                     QVector<double> ticks;
                     QVector<QString> labels;
                     ticks << 1 << 2 << 3 << 4 << 5;
                     labels << "[5..15]" << "[15..25]" << "[25..35]" << "[35..45]" << "[45...]" ;

                     QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                     textTicker->addTicks(ticks, labels);
                     ui->plot_2->xAxis->setTicker(textTicker);
                     ui->plot_2->xAxis->setTickLabelRotation(60);
                     ui->plot_2->xAxis->setSubTicks(false);
                     ui->plot_2->xAxis->setTickLength(0, 4);
                     ui->plot_2->xAxis->setRange(0, 8);
                     ui->plot_2->xAxis->setBasePen(QPen(Qt::white));
                     ui->plot_2->xAxis->setTickPen(QPen(Qt::white));
                     ui->plot_2->xAxis->grid()->setVisible(true);
                     ui->plot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                     ui->plot_2->xAxis->setTickLabelColor(Qt::white);
                     ui->plot_2->xAxis->setLabelColor(Qt::white);
                     ui->plot_2->xAxis->setLabel("Age");
                     // prepare y axis:
                     ui->plot_2->yAxis->setRange(0,10);
                     ui->plot_2->yAxis->setPadding(5); // a bit more space to the left border
                     ui->plot_2->yAxis->setLabel("Statistiques");
                     ui->plot_2->yAxis->setBasePen(QPen(Qt::white));
                     ui->plot_2->yAxis->setTickPen(QPen(Qt::white));
                     ui->plot_2->yAxis->setSubTickPen(QPen(Qt::white));
                     ui->plot_2->yAxis->grid()->setSubGridVisible(true);
                     ui->plot_2->yAxis->setTickLabelColor(Qt::white);
                     ui->plot_2->yAxis->setLabelColor(Qt::white);
                     ui->plot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                     ui->plot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                     // Add data:

                     QVector<double> PlaceData;
                     QSqlQuery q1("select Age from spectateur");
                     S.statistique(&PlaceData);
                     S.statistique_1(&PlaceData);
                     S.statistique_2(&PlaceData);
                     S.statistique_3(&PlaceData);
                     S.statistique_4(&PlaceData);
                     amande->setData(ticks, PlaceData);
                     // setup legend:
                     ui->plot_2->legend->setVisible(true);
                     ui->plot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                     ui->plot_2->legend->setBrush(QColor(255, 255, 255, 100));
                     ui->plot_2->legend->setBorderPen(Qt::NoPen);
                     QFont legendFont = font();
                     legendFont.setPointSize(5);//888//
                     ui->plot_2->legend->setFont(legendFont);
                     ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_pb_spectateurfidele_clicked()
{
    ui->tab_spectateur->setModel(S.spectf());
}
