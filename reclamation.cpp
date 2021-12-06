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
    model->setQuery("SELECT * FROM reclamation ORDER by id_rec ASC");
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
bool Reclamation::modifier(int id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("UPDATE reclamation SET categorie=:categorie,etat=:etat,contenu=:contenu,date_a=:date_a,mail=:mail,id_j=:id_j WHERE id_rec=:id");
    query.bindValue(":categorie",categorie);
    query.bindValue(":etat",etat);
    query.bindValue(":contenu",contenu);
    query.bindValue(":date_a",date_a);
    query.bindValue(":mail",mail);
    query.bindValue(":id_j",id_j);
    query.bindValue(":id",id);

    return query.exec();
}

QSqlQueryModel * Reclamation::TriCategorie(QString cls)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reclamation ORDER BY categorie "+cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rec"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("catrgorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id_j"));

    return model;
}


QSqlQueryModel * Reclamation::TriDate(QString cls)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reclamation ORDER BY date_a "+cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rec"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("catrgorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id_j"));

    return model;
}


QSqlQueryModel * Reclamation::TriEtat(QString cls)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reclamation ORDER BY etat "+cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rec"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("catrgorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id_j"));

    return model;
}


QSqlQueryModel * Reclamation::recherche(QString a)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reclamation WHERE ( categorie LIKE '%"+a+"%' OR etat LIKE '%"+a+"%' OR mail LIKE '%"+a+"%' OR id_j LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rec"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("catrgorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id_j"));

    return model;
}
bool Reclamation::ajouter_mod(int id,QString a,QDateTime d)
{
    QSqlQuery query;
    QString res = QString::number(id);
    //QString res1=d.toString();
    query.prepare("INSERT INTO mod(id_rec,type,date_mod)""VALUES (:id_rec,:type,:date_mod)");
    query.bindValue(":id_rec",id);
    query.bindValue(":type",a);
    query.bindValue(":date_mod",d);
    return query.exec();
}
QSqlQueryModel * Reclamation::afficher_mod()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM mod");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Reclamation"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date et Temps"));
    return model;
}
