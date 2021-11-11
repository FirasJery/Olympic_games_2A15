#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spectateur.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
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
    int capacite=ui->le_capacite->text().toInt();
    int horaire_e=ui->le_horaire_e->text().toInt();
    int horaire_s=ui->le_horaire_s->text().toInt();
    int nbr_ticket=ui->le_nbr_ticket->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString type_classe=ui->le_type_classe->text();
    Spectateur S(id,age,capacite,horaire_e,horaire_s,nbr_ticket,adresse,type_classe);
    bool test=S.ajouter();
    QMessageBox msgBox;
    if(test){
        msgBox.setText("Ajout avec succes.");
     ui->tab_spectateur->setModel(S.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}
;

void MainWindow::on_pb_supprimer_clicked()
{
    Spectateur S1; S1.setid(ui->le_id_supp->text().toInt());
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

     int capacite=ui->le_capacite_2->text().toInt();
     QString type_classe=ui->le_type_classe_2->text();
     int horaire_e=ui->le_horaire_e_2->text().toInt();
      int horaire_s=ui->le_horaire_s_2->text().toInt();
      int nbr_ticket=ui->le_nbr_ticket_2->text().toInt();
      QString adresse=ui->le_adresse_2->text();







    Spectateur S(id,age,capacite,horaire_e,horaire_s,nbr_ticket, adresse,type_classe);
    bool test=S.modifier();

        QMessageBox msgBox;
            if(test)
                msgBox.setText("modification avec succes");
                else
                msgBox.setText(("echec de modification"));

                msgBox.exec();

}
