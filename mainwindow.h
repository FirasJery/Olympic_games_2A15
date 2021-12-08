#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<competition.h>
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void PrintWidget(QWidget* widget) ;

    void on_rech_textChanged(const QString &arg1);

    void on_pushsendO_clicked();

private:
    Ui::MainWindow *ui;
    competition ajtmp;
    Smtp* smtpo;
    QString msgo;
    QString mailo;

};
#endif // MAINWINDOW_H
