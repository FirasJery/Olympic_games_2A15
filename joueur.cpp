#include "joueur.h"
#include <QMessageBox>
joueur::joueur(){}
joueur::joueur(QString nom ,QString prenom,QString nationallite, int id ,int num, int age )
{

     this->nom=nom;
     this->num=num;
     this->prenom=prenom;
     this->id=id;
     this->age=age;
     this->nationallite=nationallite;


}

bool joueur ::ajouter()
{
    QSqlQuery query;
    QString res = QString :: number(id);
    query.prepare("insert into JOUEUR(ID_JOUEUR,AGE,NUMERO,NOM,NATIONALLITE,PRENOM)values(:id,:age,:num,:nom,:nationallite,:prenom)");
    //
    query.bindValue(":num",num);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":id",res);
    query.bindValue(":age",age);
    query.bindValue(":nationallite",nationallite);


    return query.exec();
}
QSqlQueryModel * joueur :: afficher()
{
QSqlQueryModel * model=new QSqlQueryModel ();
model->setQuery("select* from JOUEUR");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));
return model;
}
bool joueur ::supprimer(int id)
{
QSqlQuery query;
QString res=QString ::number(id);
query.prepare("delete from JOUEUR where ID_JOUEUR= :id");
query.bindValue(":id",res);
return query.exec();
}
bool joueur::modifier(int id)
{
    QSqlQuery query;
    QString res=QString ::number(id);

    query.prepare("UPDATE JOUEUR SET ID_JOUEUR=:id,NOM=:nom,PRENOM=:prenom,NUMERO=:num,AGE=:age,NATIONALLITE=:nationallite where ID_JOUEUR=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num",num);
    query.bindValue(":age",age);
    query.bindValue(":nationallite",nationallite);

    return query.exec();
}
QSqlQueryModel* joueur::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from JOUEUR order by ID_Joueur");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}
QSqlQueryModel* joueur::triage()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from JOUEUR order by AGE");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}
