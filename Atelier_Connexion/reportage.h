#ifndef REPORTAGE_H
#define REPORTAGE_H
#include <QString>
#include <QSqlQueryModel>

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
    Reportage(int, int, QString, QString, QString, QString);
    int getcode();
    int getcodeCmp();
    QString getediteur();
    QString getsource();
    QString getsdate();
    QString getcont();
    void setcode(int);
    void setcodeCmp(int);
    void setsource(QString);
    void setdate(QString);
    void setcont(QString);
    void setediteur(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
};

#endif // REPORTAGE_H
