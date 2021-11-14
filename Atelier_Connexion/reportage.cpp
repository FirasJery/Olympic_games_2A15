#include "reportage.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlDatabase>


Reportage::Reportage()
{
codeReportage =0; editeur=" "; source=" "; date=" "; contenuReport=" ";
}

Reportage::Reportage(int cd,int cdC, QString ed, QString s, QString d, QString cnt)
{this->codeReportage=cd; this->codeCompetition=cdC; this->editeur =ed; this->source=s; this->editeur =d; this->contenuReport=cnt;}

int Reportage::getcode(){return codeReportage ;}
int Reportage::getcodeC(){return codeCompetition ;}
QString Reportage::getsource(){return source;}
QString Reportage::getsdate(){return date;}
QString Reportage:: getcont(){return contenuReport;}
QString Reportage:: getediteur(){return editeur;}

void Reportage::setcode(int cd){this->codeReportage= cd;}
void Reportage::setcodeC(int cdC){this->codeCompetition= cdC;}
void Reportage::setsource(QString s){this->source= s;}
void Reportage:: setdate(QString d){this->date= d;}
void Reportage:: setcont(QString cnt){this->contenuReport= cnt;}
void Reportage:: setediteur(QString ed){this->editeur=ed;}


bool Reportage::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(codeReportage);
    QString id_string2= QString::number(codeCompetition);
         query.prepare("INSERT INTO REPORTAGE (CODE_REPORTAGE, CODE_COMPETITION, EDITEUR, SOURCE, DATE_REPORTAGE, CONTENU_REPORTAGE) " "VALUES ( :code_reportage, :code_competition, :editeur, :source, :date_reportage, :contenu_reportage)");
         query.bindValue(" :code_reportage", id_string);
         query.bindValue(" :code_competition", id_string2);
         query.bindValue(" :editeur", editeur);
         query.bindValue(" :source", source);
         query.bindValue(" :date_reportage", date);
         query.bindValue(" :contenu_reportage", contenuReport);
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
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code R"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code C"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Contenu R"));
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
    QString id_string2= QString::number(codeCompetition);
         query.prepare("UPDATE REPORTAGE SET  EDITEUR=:editeur, SOURCE=:source, DATE_REPORTAGE=:date_reportage, CONTENU_REPORTAGE=:contenu_reportage, WHERE CODE_REPORTAGE=:code_reportage, CODE_COMPETITION=:code_competition ");
         query.bindValue(":code_reportage", id_string);
         query.bindValue(":code_competition", id_string2);
         query.bindValue(":editeur", editeur);
         query.bindValue(":source", source);
         query.bindValue(":date_reportage", date);
         query.bindValue(":contenu_reportage", contenuReport);
         return query.exec();
}
