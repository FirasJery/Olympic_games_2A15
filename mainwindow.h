#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reclamation.h"
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

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_textChanged(const QString &arg1);



    void on_pushButton_6_clicked();


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Reclamation rmp;
    Smtp* smtp;
    QString msg;
    QString mail;
};

#endif // MAINWINDOW_H
