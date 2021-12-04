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

QSqlQueryModel* joueur::triNationallite()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from JOUEUR order by NATIONALLITE");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}


QSqlQueryModel* joueur::cherche_nom(QString nom)
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from joueur where NOM ='"+nom+"'");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}


QSqlQueryModel* joueur::cherche_id(int id)
{
    QString res=QString ::number(id);

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from joueur where ID_JOUEUR ='"+res+"'");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}



QSqlQueryModel* joueur::cherche_num(int num)
{
    QString res=QString ::number(num);

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from joueur where NUMERO ='"+res+"'");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}
bool joueur ::affecter(int id,int id_competition)
{
    QSqlQuery query;
    QString res = QString :: number(id);
    QString resc = QString :: number(id_competition);
    query.prepare("insert into PARTICIPER(ID_JOUEUR,CODE_COMPETITION)values(:id,:competition)");
    //

    query.bindValue(":competition",resc);
    query.bindValue(":id",res);



    return query.exec();
}
void joueur::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select NOM from JOUEUR");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}


