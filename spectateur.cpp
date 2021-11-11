#include "spectateur.h"
#include <QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Spectateur::Spectateur()
{
id=0;
age=0;
capacite=0;
horaire_e=0;
horaire_s=0;
nbr_ticket=0;
adresse=" ";
type_classe=" ";
}
Spectateur::Spectateur(int id,int age,int capacite,int horaire_e,int horaire_s,int nbr_ticket,QString adresse,QString type_classe){
    this->id=id;
    this->age=age;
    this->capacite=capacite;
    this->horaire_e=horaire_e;
    this->horaire_s=horaire_s;
    this->nbr_ticket=nbr_ticket;
    this->adresse=adresse;
    this->type_classe=type_classe;

}
int Spectateur::getid(){return id;}
int Spectateur::getage(){return age;}
int Spectateur::getcapacite(){return capacite;}
int Spectateur::gethoraire_e(){return horaire_e;}
int Spectateur::gethoraire_s(){return horaire_s;}
int Spectateur::getnbr_ticket(){return nbr_ticket;}
QString Spectateur::getadresse(){return adresse;}
QString Spectateur::gettype_classe(){return type_classe;}

void Spectateur:: setid(int id){this->id=id;}
void Spectateur:: setage(int age){this->age=age;}
void Spectateur:: setcapacite(int capacite){this->capacite=capacite;}
void Spectateur:: sethoraire_e(int horaire_e){this->horaire_e=horaire_e;}
void Spectateur:: sethoraire_s(int horaire_s ){this->horaire_s=horaire_s;}
void Spectateur:: setnbr_ticket(int nbr_ticket){this->nbr_ticket=nbr_ticket;}
void Spectateur:: setadresse(QString adresse){this->adresse=adresse;}
void Spectateur:: settype_classe(QString type_classe){this->type_classe=type_classe;}
bool Spectateur::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("INSERT INTO spectateur (id, age,adresse,capacite, type_classe,horaire_e,horaire_s,nbr_ticket) "
                  "VALUES (:id, :age,: adresse, :capacite, :type_classe, :horaire_e, :horaire_s, :nbr_ticket)");
    query.bindValue(0, id_string);
    query.bindValue(1, age);
    query.bindValue(2, adresse);
    query.bindValue(3, capacite);
    query.bindValue(4, type_classe);
    query.bindValue(5, horaire_e);
    query.bindValue(6, horaire_s);
    query.bindValue(7, nbr_ticket);
    query.exec();
return query.exec();
}
bool Spectateur::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from spectateur where id=:id ");

    query.bindValue(0, id);

return query.exec();
}
QSqlQueryModel* Spectateur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM spectateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horaire_e"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("horaire_s"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("nbr_ticket"));
    return model;
}
bool Spectateur::modifier()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
     QString type_classe_string=QString(type_classe);
        query.prepare("UPDATE GestionSpectateurs SET nom=:nom,prenom=:prenom,Adresse_mail=:Adresse_mail,Age=:Age WHERE idC=:idC ");
        query.bindValue(":id",id_string );
        query.bindValue(":Age", age_string);
        query.bindValue(":capacite",capacite );
        query.bindValue(":type_classe", type_classe_string);
        query.bindValue(":horaire_e",horaire_e );
        query.bindValue(":horaire_s",horaire_s );
        query.bindValue(":nbr_ticket",nbr_ticket );

        return query.exec();

}


