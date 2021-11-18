#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <QString>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include<qsqlquerymodel.h>

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
     void statistique(QVector<double>* ticks,QVector<QString> *labels);
private:

    int id,age,nbr_ticket;
    QString adresse,type_classe;


};

#endif // SPECTATEUR_H
