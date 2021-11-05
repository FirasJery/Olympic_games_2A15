#include "reclamation.h"

Reclamation::Reclamation()
{

}
Reclamation::Reclamation(int a, QString b,QString c,QString d,QDate e,QString f,int g)
{
    id_rec=a;
    categorie=b;
    etat=c;
    contenu=d;
    date_a=e;
    mail=f;
    id_j=g;
}
void Reclamation::afficher()
{

}
bool Reclamation::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_rec);
    query.prepare("INSERT INTO reclamation(id_rec,categorie,etat,contenu,date_a,mail,id_j)""VALUES (:id_rec,:categorie,:etat,:contenu,:date_a,:mail,:id_j)");
    query.bindValue(":id_rec",res);
    query.bindValue(":categorie",categorie);
    query.bindValue(":etat",etat);
    query.bindValue(":contenu",contenu);
    query.bindValue(":date_a",date_a);
    query.bindValue(":mail",mail);
    query.bindValue(":id_j",id_j);
    return query.exec();
}
bool Reclamation::supprimer(int)
{

}
