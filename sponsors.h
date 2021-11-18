#ifndef SPONSORS_H
#define SPONSORS_H
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>

class SPONSORS
{
    int ID_SPONSOR;
    QString NOM_SPONSOR;
    QString TYPE;
    int CODE_COMPETITION;
    int BUDGET;
    int ETAT;
public:
    SPONSORS();
    SPONSORS(int, QString, QString, int, int, int);
    bool Ajouter();
    QSqlQueryModel * Afficher();
    bool Modifier(int);
    bool Supprimer(int);
    QSqlQueryModel * Triparnom(QString tst);
        QSqlQueryModel * TriEtat(QString tst);
        QSqlQueryModel * TriBudget(QString tst);
        QSqlQueryModel * recherche(QString tst);

   int alerte();

     bool Export(QString tst);
};

#endif // SPONSORS_H
