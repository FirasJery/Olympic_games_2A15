#ifndef REPORTAGE_H
#define REPORTAGE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>

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
    bool recherche(int);
    bool modifier();
    QSqlQueryModel* trier (int);
    bool supprimerTout();
};

#endif // REPORTAGE_H
