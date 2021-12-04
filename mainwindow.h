#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "joueur.h"
#include "sponsors.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
   joueur ptmp;
   SPONSORS Stmp;
};

#endif // MAINWINDOW_H
