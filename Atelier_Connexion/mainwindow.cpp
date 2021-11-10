#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reportage.h"
#include <qmessagebox.h>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->tableView_reportA->setModel(R.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int cd = ui->lineEdit_codeR->text().toInt();
    int cdC = ui->lineEdit_codeC->text().toInt();
    QString ed = ui->lineEdit_editeur->text();
    QString s =ui->lineEdit_source->text();
    QString cnt=ui->lineEdit_report->text();
    QString d = ui->lineEdit_date->text();
    Reportage R(cd, cdC, ed, s, d, cnt);
    bool test = R.ajouter();
    QMessageBox msgBox;

    if(test)
       {
           msgBox.setText("Ajout avec succes.");
           ui->tableView_reportA->setModel(R.afficher());
       }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pushButton_supp_clicked()
{
    Reportage R1; R1.setcode(ui->lineEdit_codeRA->text().toInt());
    bool test = R1.supprimer(R1.getcode());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes.");
    ui->tableView_reportA->setModel(R.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}


void MainWindow::on_pushButton_modifier_clicked()
{
    Reportage R;
    R.setcode(ui->lineEdit_codeMod->text().toInt());
    bool test = R.recherche(R.getcode());
    QMessageBox msgBox;

    if(test)
    {
                if(ui->pushButton_modifier->isChecked())
                {
                      ui->pushButton_modifier->setText("Modifiable");
                      QSqlTableModel *TableModel= new QSqlTableModel();
                      TableModel->setTable("gestion_place_parking");
                      TableModel->select();
                      ui->tableView_reportA->setModel(TableModel);
                }
                 else
                {
                      ui->pushButton_modifier->setText("Modifier");
                      ui->tableView_reportA->setModel(R.afficher());
                }
    }
    else
        msgBox.setText("identifiant incorrect");
    msgBox.exec();
}
