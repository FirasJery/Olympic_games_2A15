#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <joueur.h>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
    ui->tableView->setModel(ptmp.afficher());


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
    int id =ui->Id_Supp->text().toInt();
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
    int id=ui->Id_Supp->text().toInt();

       QString nom =ui->nomm->text();

       QString prenom=ui->prenomm->text();

       QString nationallite=ui->nationallitem->text();

       int num=ui->numm->text().toInt();

       int age=ui->agem->text().toInt();

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
