#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spectateur.h"
#include "qcustomplot.h"
#include <QTableView>
#include <QAbstractItemView>
#include <QIntValidator>
#include <QLineEdit>
#include <QMessageBox>
#include <QSqlQuery>
#include<qcustomplot.h>
#include <smtp.h>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //pointeur sur l'interface
    ui->tabWidget->setCurrentIndex(0);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this)); //controle de saisie
    ui->le_age->setValidator(new QIntValidator(1,100,this));
    ui->tab_spectateur->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

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


void MainWindow::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
                  QLinearGradient gradient(0, 0, 0, 400);
                  gradient.setColorAt(0, QColor(90, 90, 90));
                  gradient.setColorAt(0.38, QColor(105, 105, 105));
                  gradient.setColorAt(1, QColor(70, 70, 70));
                  ui->plot->setBackground(QBrush(gradient));


                  // create empty bar chart objects:
                  QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
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
                  ui->plot->xAxis->setLabel("Age");
                  // prepare y axis:
                  ui->plot->yAxis->setRange(0,10);
                  ui->plot->yAxis->setPadding(5); // a bit more space to the left border
                  ui->plot->yAxis->setLabel("Statistiques");
                  ui->plot->yAxis->setBasePen(QPen(Qt::white));
                  ui->plot->yAxis->setTickPen(QPen(Qt::white));
                  ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                  ui->plot->yAxis->grid()->setSubGridVisible(true);
                  ui->plot->yAxis->setTickLabelColor(Qt::white);
                  ui->plot->yAxis->setLabelColor(Qt::white);
                  ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                  ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

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
                  ui->plot->legend->setVisible(true);
                  ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                  ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                  ui->plot->legend->setBorderPen(Qt::NoPen);
                  QFont legendFont = font();
                  legendFont.setPointSize(5);//888//
                  ui->plot->legend->setFont(legendFont);
                  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}


