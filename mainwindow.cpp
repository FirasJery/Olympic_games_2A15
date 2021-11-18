#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "connection.h"
#include <QMessageBox>
#include <QSystemTrayIcon>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
     ui->tableView->setModel(rmp.afficher());
    QSqlQueryModel *model=new QSqlQueryModel();
    model = rmp.afficher();
    int count=0;
    for (int i = 0; i < model->rowCount(); i++) {
        if ((model->data(model->index(i,4)).toDate().addDays(3) < QDate::currentDate()) && (model->data(model->index(i,2)).toString() != "done"))
        {
            count++;
        }}
        if (count != 0){
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            QString res=QString::number(count);
            notifyIcon->show();
            notifyIcon->showMessage("warning ! ","you have "+res+" reclamation not done",QSystemTrayIcon::Information,15000);
        }




 /*        QSqlQuery query;
         QDate current=current.currentDate();
         int i=0;
         int nb=0;
         do
         {
             query.exec("SELECT date_a FROM competition WHERE etat!='done'");
             QDate d=query.value(i).toDate();
             QDate compare=d.addDays(3);
             if (current>compare)
                 nb++;
          }while (query.next());
         QString res=QString::number(nb);*/



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
        ui->tableView->setModel(rmp.afficher());

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

void MainWindow::on_pushButton_2_clicked()
{
    bool i;
    int id_del;
    id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();

    i=rmp.supprimer(id_del);
    if(i)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(rmp.afficher());

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }

}

void MainWindow::on_pushButton_4_clicked()
{
    int id_upt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    QString categorie=ui->line_categorie->text();
    QString contenu=ui->line_contenu->text();
    QString etat=ui->line_etat->text();
    QDate d=ui->date->date();
    QString mail=ui->line_mail->text();
    int id_j=ui->line_idj->text().toInt();
    Reclamation R(id_upt,categorie,etat,contenu,d,mail,id_j);



    bool test=R.modifier(id_upt);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(rmp.afficher());

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString cls;
    if (ui->radioButton->isChecked()) cls="ASC";
    else if (ui->radioButton_2->isChecked()) cls="DESC";

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

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(rmp.recherche(arg1));
}

void MainWindow::on_pushButton_6_clicked()
{
    smtp = new Smtp("gestion.recs@gmail.com" , "gestiongestion", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("firas_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (index.data().toString() == ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString()){
        ui->tabWidget->setCurrentIndex(1);
        ui->a_mail->setText(index.data().toString());
    }

}
