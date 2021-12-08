#ifndef REPORTAGE_H
#define REPORTAGE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QVector>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

class Reportage
{
private:
    int codeReportage;
    int codeCompetition;
    QString source;
    QString contenuReport;
    QString date;
    QString editeur;
public:
    Reportage();
    Reportage(int,int, QString, QString, QString, QString);

    int getcode();
    int getcodeC();
    QString getediteur();
    QString getsource();
    QString getsdate();
    QString getcont();

    void setcode(int);
    void setcodeC(int);
    void setsource(QString);
    void setdate(QString);
    void setcont(QString);
    void setediteur(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* recherche(QString);
    bool modifier();
    QSqlQueryModel* trier (int);
    bool supprimerTout();
    QChart* statistique();
};

#endif // REPORTAGE_H
