#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sponsors.h"

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
    void on_pushButtonajout_clicked();

    void on_pushButtonsupp_clicked();

    void on_pushButtonmodif_clicked();

    void on_pushButtonmodif_3_clicked();

    void on_linebudget_2_textChanged(const QString &arg1);

    void on_pushButtonmodif_2_clicked();

    void on_pushButton_clicked();

    void on_pushButtonmodif_4_clicked();

private:
    Ui::MainWindow *ui;
    SPONSORS Stmp;
};

#endif // MAINWINDOW_H
