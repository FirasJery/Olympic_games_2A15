
#include "spectateur.h"
#include <QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include"mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<vector>
#include <qcustomplot.h>

Spectateur::Spectateur()
{
id=0;
age=0;
nbr_ticket=0;
adresse=" ";
type_classe=" ";
}
Spectateur::Spectateur(int id,int age,int nbr_ticket,QString adresse,QString type_classe){
    this->id=id;
    this->age=age;


    this->nbr_ticket=nbr_ticket;
    this->adresse=adresse;
    this->type_classe=type_classe;

}
int Spectateur::getid(){return id;}
int Spectateur::getage(){return age;}

int Spectateur::getnbr_ticket(){return nbr_ticket;}
QString Spectateur::getadresse(){return adresse;}
QString Spectateur::gettype_classe(){return type_classe;}

void Spectateur:: setid(int id){this->id=id;}
void Spectateur:: setage(int age){this->age=age;}
void Spectateur:: setnbr_ticket(int nbr_ticket){this->nbr_ticket=nbr_ticket;}
void Spectateur:: setadresse(QString adresse){this->adresse=adresse;}
void Spectateur:: settype_classe(QString type_classe){this->type_classe=type_classe;}

bool Spectateur::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
     QString age_string= QString::number(age);

    query.prepare("insert into SPECTATEUR (id, age,adresse, type_classe,nbr_ticket) "
                  "values (:id, :age,: adresse, :type_classe, :nbr_ticket)");
    query.bindValue(0, id_string); //
    query.bindValue(1, age_string);
    query.bindValue(2, adresse);

    query.bindValue(3, type_classe);

    query.bindValue(4, nbr_ticket);

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
    model->setQuery("SELECT id,age,adresse,type_classe,nbr_ticket from spectateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")); //ajouter les noms de colonnes de mon tab
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_classe"));


    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_ticket"));
    return model;
}

bool Spectateur::modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
        QString nbr_ticket_string=QString::number(nbr_ticket);
        query.prepare("UPDATE spectateur SET id=:id,age=:age,adresse=:adresse,type_classe=:type_classe,nbr_ticket=:nbr_ticket WHERE id=:id ");
        query.bindValue(":id",id_string);
        query.bindValue(":age", age_string);
        query.bindValue(":adresse", adresse);
        query.bindValue(":type_classe", type_classe);
        query.bindValue(":nbr_ticket",nbr_ticket_string);

        query.exec();

}

QSqlQueryModel* Spectateur::trinom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from spectateur order by ID");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;
}
QSqlQueryModel* Spectateur::trinbrticket()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from spectateur order by nbr_ticket");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;
}

QSqlQueryModel* Spectateur::triage()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from spectateur order by AGE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;
}

QSqlQueryModel* Spectateur::recherche_ID(int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(id);
            model->setQuery("select * from spectateur where ID='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;

}
QSqlQueryModel* Spectateur::recherche_age(int age)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(age);
            model->setQuery("select * from spectateur where age='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;

}
QSqlQueryModel* Spectateur::recherche_nbr_ticket(int nbr_ticket)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(nbr_ticket);
            model->setQuery("select * from spectateur where nbr_ticket='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_classe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_ticket"));

   return model;

}

void Spectateur::statistique(QVector<double>* PlaceData)
{
    QSqlQuery q;
    int i=0;
    q.exec("select Age from spectateur");
    while (q.next())
    {
        if(q.value(0).toInt()>15)
            i++;
    }
    *PlaceData<< i;
}
void Spectateur::statistique_1(QVector<double>* PlaceData)
{
    QSqlQuery q;
    int i=0;
    q.exec("select Age from spectateur");
    while (q.next())
    {
        if((q.value(0).toInt())>15&&(q.value(0).toInt()<25))
            i++;
    }
    *PlaceData<< i;
}
void Spectateur::statistique_2(QVector<double>* PlaceData)
{
    QSqlQuery q;
    int i=0;
    q.exec("select Age from spectateur");
    while (q.next())
    {
        if((q.value(0).toInt())>25&&(q.value(0).toInt()<35))
            i++;
    }
    *PlaceData<< i;
}
void Spectateur::statistique_3(QVector<double>* PlaceData)
{
    QSqlQuery q;
    int i=0;
    q.exec("select Age from spectateur");
    while (q.next())
    {
        if((q.value(0).toInt())>35&&(q.value(0).toInt()<45))
            i++;
    }
    *PlaceData<< i;
}
void Spectateur::statistique_4(QVector<double>* PlaceData)
{
    QSqlQuery q;
    int i=0;
    q.exec("select Age from spectateur");
    while (q.next())
    {
        if(q.value(0).toInt()>45)
            i++;
    }
    *PlaceData<< i;
}









