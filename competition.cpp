#include "competition.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>

competition::competition()
{
    nom="";lieu="";desc=""; type="" ;
}

competition::competition(QString nom , QString lieu , QString desc , QString type , QDate date_d , QDate date_f)
{
    this->nom=nom;this->lieu=lieu;this->desc=desc;this->type=type;this->date_d=date_d;this->date_f=date_f;
}

bool competition::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into COMPETITIONS ( NOM, LIEU,DATE_DE,DATE_FIN,DESCR,TYPE)"
                  " values(:a,:b,:c,:d,:e,:f) ");
    query.bindValue(":a",nom);
    query.bindValue(":b",lieu);
    query.bindValue(":c",date_d);
    query.bindValue(":d",date_f);
    query.bindValue(":e",desc);
    query.bindValue(":f",type);
    return query.exec();
}
QSqlQueryModel * competition::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from COMPETITIONS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCR"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
          return model;

}
bool competition::supprimer(int cc)
{
    QSqlQuery query;
    int res3= cc;
    query.prepare("Delete from COMPETITIONS where CODE_COMPETITION =?");
    query.addBindValue(res3);
    return    query.exec();
}
bool competition::modifier(QString nom, QString lieu, QString desc, QString type, QDate date_d,QDate date_f,QString code)
{

    QSqlQuery query;
    query.prepare("update COMPETITIONS  set NOM = '"+nom+"' , LIEU = '"+lieu+"'   , DESCR = '"+desc+"', TYPE = '"+type+"'  where CODE_COMPETITION = '"+code+"' ");
          return query.exec();
}

QSqlQueryModel * competition::recherche(QString a)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM competitions WHERE ( CODE_COMPETITION LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR DATE_DE LIKE '%"+a+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCR"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}






