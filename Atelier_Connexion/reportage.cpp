#include "reportage.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
Reportage::Reportage()
{
codeReportage =0; codeCompetition=0; editeur=""; source=""; date=""; contenuReport="";
}

Reportage::Reportage(int cd, int cdC, QString ed, QString s, QString d, QString cnt)
{this->codeReportage=cd; this->codeCompetition=cdC; this->editeur =ed; this->source=s; this->editeur =d; this->contenuReport=cnt;}
int Reportage::getcode(){return codeReportage ;}
int Reportage::getcodeCmp(){return codeCompetition ;}
QString Reportage::getsource(){return source;}
QString Reportage::getsdate(){return date;}
QString Reportage:: getcont(){return contenuReport;}
QString Reportage:: getediteur(){return editeur;}
void Reportage::setcode(int cd){this->codeReportage= cd;}
void Reportage::setcodeCmp(int cdC){this->codeCompetition= cdC;}
void Reportage::setsource(QString s){this->source= s;}
void Reportage:: setdate(QString d){this->date= d;}
void Reportage:: setcont(QString cnt){this->contenuReport= cnt;}
void Reportage:: setediteur(QString ed){this->editeur=ed;}
bool Reportage::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(codeReportage);
    QString id_string2= QString::number(codeCompetition);
         query.prepare("INSERT INTO REPORTAGE (CODE_REPORTAGE, CODE_COMPETITION, EDITEUR, SOURCE, DATE_REPORTAGE, CONTENU_REPORTAGE) "
                       "VALUES (:CODE_REPORTAGE, :CODE_COMPETITION, :EDITEUR, :SOURCE, :DATE_REPORTAGE, :CONTENU_REPORTAGE)");
         query.bindValue(":CODE_REPORTAGE", id_string);
         query.bindValue(":CODE_COMPETITION", id_string2);
         query.bindValue(":EDITEUR", editeur);
         query.bindValue(":SOURCE", source);
         query.bindValue(":DATE_REPORTAGE", date);
         query.bindValue(":CONTENU_REPORTAGE", contenuReport);
         return query.exec();
}

bool Reportage::supprimer(int cd)
{
    QSqlQuery query;
         query.prepare("Delete from REPORTAGE where CODE_REPORTAGE:CODE_REPORTAGE");
         query.bindValue(0, codeReportage);
         return query.exec();
}


QSqlQueryModel* Reportage::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM reportage");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code Reportage"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code Competion"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Contenue Reportage"));




    return model;
}

bool Reportage::recherche(int cd)
{
    QSqlQuery query;
        QString id_string = QString::number(cd);
        query.prepare(" selet * from equipement where indentifiant_eq='"+id_string+"'");
    while(query.next())
    {
        int cd = query.value(0).toInt();
        int cdm = query.value(1).toInt();
        QString s = query.value(2).toString() ;
        QString cnt = query.value(3).toString();
        QString d = query.value(4).toString();
        QString e = query.value(5).toString();
    }
    return query.exec();
}

