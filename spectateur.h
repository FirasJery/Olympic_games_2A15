#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <qsqlquerymodel.h>
#include<vector>

class Spectateur
{
public:
    Spectateur();
    Spectateur(int,int,int,QString,QString);
    int getid();
    int getage();



    int getnbr_ticket();
    QString getadresse();
    QString gettype_classe();
    void setid(int);
    void setage (int);


    void sethoraire_s(int);
    void setnbr_ticket(int);
    void setadresse(QString);
    void settype_classe(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *trinom();
    QSqlQueryModel *triage();
    QSqlQueryModel *trinbrticket();
    QSqlQueryModel *recherche_ID(int id);
    QSqlQueryModel *recherche_age(int age);
    QSqlQueryModel *recherche_nbr_ticket(int nbr_ticket);
     void statistique(QVector<double>* ticks);
     void statistique_1(QVector<double>* PlaceData);
     void statistique_2(QVector<double>* PlaceData);
     void statistique_3(QVector<double>* PlaceData);
     void statistique_4(QVector<double>* PlaceData);
private:

    int id,age,nbr_ticket;
    QString adresse,type_classe;


};

#endif // SPECTATEUR_H
