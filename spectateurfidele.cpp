/*#include "spectateurfidele.h"
#include <QDebug>
client_fidele::client_fidele()
{
id=0;
nbr_ticket=0;
age=0;
adresse="";
type_classe="";
}
spectateurfidele::spectateurfidele(int id,QString adresse,QString type_classe,int nbr_ticket,int age)
{
  this->id=id;
  this->age=age;
  this->type_classe=type_classe;
    this->nbr_ticket=nbr_ticket;
    this->adresse=adresse;

}
int spectateurfidele::get_id(){return  id;}
QString spectateurfidele::get_adresse(){return adresse;}
QString spectateurfidele::get_type_classe(){return type_classe;}
int spectateurfidele::get_nbr_ticket(){return nbr_ticket;}
int spectateurfidele::get_age(){return age;}


/* ----- */


/*bool spectateurfidele::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client_fidele (MATRICULE_FISCALE, NOM,CIN,ADRESSE,ADRESSE_MAIL) "
                    "VALUES (:MATRICULE_FISCALE, :NOM, :CIN,:ADRESSE,:ADRESSE_MAIL)");
query.bindValue(":id",id );
query.bindValue(":NOM", );
query.bindValue(":CIN", CIN );
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":ADRESSE_MAIL",ADRESSE_MAIL );


return    query.exec();
}

QSqlQueryModel * client_fidele::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client_fidele");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE_FISCALE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
    return model;
}

bool client_fidele::supprimer(int MATRICULE_FISCALEE)
{
QSqlQuery query;
QString res= QString::number(MATRICULE_FISCALEE);
query.prepare("Delete from client_fidele where MATRICULE_FISCALE = :MAT ");
query.bindValue(":MAT", res);
return    query.exec();
}
bool client_fidele::modifier(int MATRICULE_FISCALE)
{
    QSqlQuery query;
    QString res= QString::number(MATRICULE_FISCALE);
    query.prepare("UPDATE client_fidele SET MATRICULE_FISCALE=:MATRICULE_FISCALE,NOM=:NOM,CIN=:CIN,ADRESSE=:ADRESSE,ADRESSE_MAIL=:ADRESSE_MAIL WHERE MATRICULE_FISCALE=:MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE", MATRICULE_FISCALE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":CIN", CIN );
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":ADRESSE_MAIL", ADRESSE_MAIL);
    return    query.exec();

}


spectateurfidele::spectateurfidele()
{

}*/
