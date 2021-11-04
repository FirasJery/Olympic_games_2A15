#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reportage.h"

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
    QString cd = ui->lineEdit_code->text();
    QString ed = ui->lineEdit_editeur->text();
    QString s =ui->lineEdit_source->text();
    QString cnt=ui->lineEdit_report->text();
    //affectattion de la date
    Reportage R(cd, ed, s,cnt);
    R.ajouter();
}
