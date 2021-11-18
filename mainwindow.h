#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "spectateur.h"
#include <QMainWindow>
#include <smtp.h>

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
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_tri_ID_clicked();
    void on_pb_tri_AGE_clicked();
    void on_pb_tri_nbr_ticket_clicked();
    void on_pb_recherche_ID_clicked();
    void on_pb_recherche_age_clicked();
    void on_pb_recherche_nbr_ticket_clicked();
    void on_tabWidget_currentChanged(int index);


    void on_pb_mail_clicked();

private:
    Ui::MainWindow *ui;
    Spectateur S;
};

#endif // MAINWINDOW_H
