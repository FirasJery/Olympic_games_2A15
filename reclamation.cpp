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
QSqlQueryModel * Reclamation::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reclamation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rec"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("catrgorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id_j"));

    return model;
}
bool Reclamation::ajouter()
{
    QSqlQuery query;
    //QString res = QString::number(id_rec);
    query.prepare("INSERT INTO reclamation(categorie,etat,contenu,date_a,mail,id_j)""VALUES (:categorie,:etat,:contenu,:date_a,:mail,:id_j)");
    //query.bindValue(":id_rec",res);
    query.bindValue(":categorie",categorie);
    query.bindValue(":etat",etat);
    query.bindValue(":contenu",contenu);
    query.bindValue(":date_a",date_a);
    query.bindValue(":mail",mail);
    query.bindValue(":id_j",id_j);
    return query.exec();
}
bool Reclamation::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM reclamation WHERE id_rec= :id");
    query.bindValue(":id",res);
    return query.exec();
}
