#ifndef REPORTAGE_H
#define REPORTAGE_H
#include <QString>
#include <QSqlQueryModel>

class Reportage
{
private:
    int codeReportage;
    QString source;
    QString contenuReport;
    QString date;
    QString editeur;
public:
    Reportage();
    Reportage(int, QString, QString, QString, QString);
    int getcode();
    QString getediteur();
    QString getsource();
    QString getsdate();
    QString getcont();
    void setcode(int);
    void setsource(QString);
    void setdate(QString);
    void setcont(QString);
    void setediteur(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool recherche(int);
    bool modifier();
};

#endif // REPORTAGE_H
