#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "joueur.h"
#include "sponsors.h"
#include <QMainWindow>
#include "reclamation.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include "spectateur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_tri_id_clicked();

    void on_tri_age_clicked();

    void on_nationallite_2_clicked();

    void on_pushButton_7_clicked();

    void on_chercher_id_clicked();

    void on_chercher_num_clicked();

    void on_pushButton_4_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_export_2_clicked();

    void on_pushconnect_clicked();

    void on_pushButtonmodif_clicked();

    void on_pushButtonajout_clicked();

    void on_pushButtonsupp_clicked();

    void on_push_trig_clicked();

    void on_push_exportg_clicked();

    void on_push_alerteg_clicked();

    void on_push_impressiong_clicked();

    void on_linerechg_textChanged(const QString &arg1);

    void on_push_ajoutf_clicked();

    void on_push_modifierf_clicked();

    void on_push_afficherf_clicked();

    void on_push_supprimerf_clicked();

    void on_pushtrif_clicked();

    void on_line_rechf_textChanged(const QString &arg1);

    void on_push_sendf_clicked();

    void on_tableViewf_doubleClicked(const QModelIndex &index);

    void on_tabWidgetf_currentChanged(int index);

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_ID_clicked();

    void on_pb_tri_AGE_clicked();

    void on_pb_tri_nbr_ticket_clicked();

    void on_pb_recherche_ID_clicked();

    void on_pb_recherche_age_clicked();

    void on_pb_recherche_nbr_ticket_clicked();

    void on_pb_mail_clicked();

    void on_tabWidget_i_currentChanged(int index);

    void on_pb_spectateurfidele_clicked();

private:
    Ui::MainWindow *ui;
   joueur ptmp;
   SPONSORS Stmp;
   Reclamation rmp;
   Smtp* smtp;
   QString msg;
   QString mail;
   Spectateur S;
};

#endif // MAINWINDOW_H
