#include "reportage.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>


Reportage::Reportage()
{
codeReportage =0; editeur=""; source=""; date=""; contenuReport="";
}

Reportage::Reportage(int cd, QString ed, QString s, QString d, QString cnt)
{this->codeReportage=cd; this->editeur =ed; this->source=s; this->editeur =d; this->contenuReport=cnt;}

int Reportage::getcode(){return codeReportage ;}
QString Reportage::getsource(){return source;}
QString Reportage::getsdate(){return date;}
QString Reportage:: getcont(){return contenuReport;}
QString Reportage:: getediteur(){return editeur;}

void Reportage::setcode(int cd){this->codeReportage= cd;}
void Reportage::setsource(QString s){this->source= s;}
void Reportage:: setdate(QString d){this->date= d;}
void Reportage:: setcont(QString cnt){this->contenuReport= cnt;}
void Reportage:: setediteur(QString ed){this->editeur=ed;}


bool Reportage::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(codeReportage);
         query.prepare("INSERT INTO REPORTAGE (CODE_REPORTAGE, EDITEUR, SOURCE, DATE_REPORTAGE, CONTENU_REPORTAGE) "
                       "VALUES (:CODE_REPORTAGE, :EDITEUR, :SOURCE, :DATE_REPORTAGE, :CONTENU_REPORTAGE)");
         query.bindValue(0, id_string);
         query.bindValue(1, editeur);
         query.bindValue(2, source);
         query.bindValue(3, date);
         query.bindValue(4, contenuReport);
         return query.exec();
}

bool Reportage::supprimer(int cd)
{
    QSqlQuery query;
         query.prepare("Delete from REPORTAGE where CODE_REPORTAGE:CODE_REPORTAGE");
         query.bindValue(0, cd);
         return query.exec();
}


QSqlQueryModel* Reportage::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM REPORTAGE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code Reportage"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Contenue Reportage"));
    return model;
}

bool Reportage::recherche(int cd_recherche)
{
    QSqlQuery query;
        QString id_string = QString::number(cd_recherche);
        query.prepare(" selet * from equipement where indentifiant_eq='"+id_string+"'");
    while(query.next())
    {
        int cd = query.value(0).toInt();
        QString s = query.value(1).toString() ;
        QString cnt = query.value(2).toString();
        QString d = query.value(3).toString();
        QString e = query.value(4).toString();
    }
    return query.exec();
}

bool Reportage::modifier()
{
    QSqlQuery query;
    QString id_string= QString::number(codeReportage);
         query.prepare("UPDATE REPORTAGE SET  EDITEUR=:editeur, SOURCE=:source, DATE_REPORTAGE=:date_reportage, CONTENU_REPORTAGE=:contenu_reportage, WHERE CODE_REPORTAGE=:code_reportage ");
         query.bindValue(":code_reportage", id_string);
         query.bindValue(":editeur", editeur);
         query.bindValue(":source", source);
         query.bindValue(":date_reportage", date);
         query.bindValue(":contenu_reportage", contenuReport);
         return query.exec();
}
