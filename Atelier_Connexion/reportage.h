#ifndef REPORTAGE_H
#define REPORTAGE_H
#include <QString>
#include <QSqlQueryModel>

class Reportage
{
private:
    QString codeReportage;
    QString source;
    QString contenuReport;
    QString date;
    QString editeur;
public:
    Reportage();
    Reportage(QString, QString, QString, QString);
    QString getcode();
    QString getediteur();
    QString getsource();
    QString getsdate();
    QString getcont();
    void setcode(QString);
    void setsource(QString);
    void setdate(QString);
    void setcont(QString);
    void setediteur(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
};

#endif // REPORTAGE_H
