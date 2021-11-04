#include "reportage.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
Reportage::Reportage()
{
codeReportage =""; editeur=""; source=""; contenuReport="";
}

Reportage::Reportage(QString cd, QString ed, QString s, QString cnt)
{this->codeReportage=cd; this->editeur =ed; this->source=s; this->contenuReport=cnt;}
QString Reportage::getcode(){return codeReportage ;}
QString Reportage::getsource(){return source;}
QString Reportage::getsdate(){return date;}
QString Reportage:: getcont(){return contenuReport;}
QString Reportage:: getediteur(){return editeur;}
void Reportage::setcode(QString cd){this->codeReportage= cd;}
void Reportage::setsource(QString s){this->source= s;}
void Reportage:: setdate(QString d){this->date= d;}
void Reportage:: setcont(QString cnt){this->contenuReport= cnt;}
void Reportage:: setediteur(QString ed){this->editeur=ed;}
bool Reportage::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO REPORTAGE (CODE, EDITEUR, SOURCE, CONTENU) "
                       "VALUES (:CODE, :EDITEUR, :SOURCE, :CONT_REPORT)");
         query.bindValue(":CODE", codeReportage);
         query.bindValue(":EDITEUR", editeur);
         query.bindValue(":SOURCE", source);
         //query.bindValue(":Date", date);
         query.bindValue(":CONT_REPORT", contenuReport);
         return query.exec();
}
QSqlQueryModel* Reportage::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM reportage");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Contenue"));




    return model;
}
