#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <QIntValidator>
#include "exportexcelobject.h"
#include "joueur.h"
#include "sponsors.h"
#include "reclamation.h"
#include "spectateur.h"
#include "reportage.h"
#include <competition.h>
#include "smtp.h"


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

    void on_pb_ajouterReportage_clicked();

    void on_pushButton_modifierReportage_clicked();

    void on_pushButton_suppReportage_clicked();

    void on_pushButton_pdfReportage_clicked();

    void on_lineEdit_rechReportage_textChanged(const QString &arg1);

    void on_pushButton_trierReportage_clicked();

    void on_supp_tout_clicked();

    void on_pushajouto_clicked();

    void on_pushmodifo_clicked();

    void on_tableViewo_clicked(const QModelIndex &index);

    void on_pushsuppo_clicked();

    void on_pushtrio_clicked();

    void PrintWidget(QWidget* widget);

    void on_pushpdfo_clicked();

    void on_recho_textChanged(const QString &arg1);

    void on_pushsendO_clicked();

    void on_pushdeco_clicked();

private:
    Ui::MainWindow *ui;
    joueur ptmp;
    SPONSORS Stmp;
    Reclamation rmp;
    Spectateur S;
    Reportage R;
    competition ajtmp;
    Smtp* smtp;
    QString msg;
    QString mail;
    Smtp* smtpo;
    QString msgo;
    QString mailo;
};

#endif // MAINWINDOW_H
