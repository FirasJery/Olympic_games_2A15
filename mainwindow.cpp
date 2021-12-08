#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <joueur.h>
#include "exportexcelobject.h"
#include <QIntValidator>
#include <QString>
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
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
QString *res;


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
void MainWindow::update_label()
{
    data=A.read_from_arduino();
QString DataAsString = QString(data);
                qInfo() << DataAsString;



if(DataAsString=="5")
{
                A.write_to_arduino("1");
            }else{
                A.write_to_arduino("0");
            }

}
