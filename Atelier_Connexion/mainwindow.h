#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reportage.h"
#include "QMainWindow"
#include <QSqlDatabase>

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

    void on_pushButton_supp_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Reportage R;
};

#endif // MAINWINDOW_H
