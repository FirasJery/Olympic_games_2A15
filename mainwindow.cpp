#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "connection.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString categorie=ui->line_categorie->text();
    QString contenu=ui->line_contenu->text();
    QDate d=ui->date->date();
    QString mail=ui->line_mail->text();



    Reclamation R(1,categorie,"just added",contenu,d,mail,1);

    bool test=R.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->tableView->setModel(rmp.afficher());
}
