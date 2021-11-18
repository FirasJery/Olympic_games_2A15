#include "reportage.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlDatabase>


Reportage::Reportage()
{
codeReportage =0; codeCompetition=0; editeur=" "; source=" "; date=" "; contenuReport=" ";
}

Reportage::Reportage(int cd,int cdC, QString ed, QString s, QString d, QString cnt)
{this->codeReportage=cd; this->codeCompetition=cdC; this->editeur =ed; this->source=s; this->contenuReport=cnt;this->date = d;}

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
         query.prepare("INSERT INTO REPORTAGE (CODE_REPORTAGE, CODE_COMPETITION, EDITEUR , SOURCE , DATE_REPORTAGE, CONTENU_REPORTAGE) "
                       " values (:codeReportage,:codeCompetition,:editeur,:source,:date_reportage,:contenu_reportage)");
         query.bindValue(":codeReportage", id_string);
         query.bindValue(":codeCompetition", id_string2);
         query.bindValue(":editeur", editeur);
         query.bindValue(":source", source);
         query.bindValue(":date_reportage", date);
         query.bindValue(":contenu_reportage", contenuReport);
         return query.exec();
}

bool Reportage::supprimer(int cd)
{
    QSqlQuery query;
         query.prepare("Delete from REPORTAGE where CODE_REPORTAGE=:CODE_REPORTAGE");
         query.bindValue(":CODE_REPORTAGE", cd);
         return query.exec();
}

bool Reportage::supprimerTout()
{
    QSqlQuery query;
          query.prepare("TRUNCATE TABLE REPORTAGE");
          return query.exec();

}


QSqlQueryModel* Reportage::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM REPORTAGE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code_R"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code_C"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contenu_R"));
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
         query.prepare("UPDATE REPORTAGE SET  CODE_COMPETITION=:code_competition, EDITEUR=:editeur, SOURCE=:source, DATE_REPORTAGE=:date_reportage, CONTENU_REPORTAGE=:contenu_reportage WHERE CODE_REPORTAGE=:code_reportage");
         query.bindValue(":code_reportage", id_string);
         query.bindValue(":code_competition", id_string2);
         query.bindValue(":editeur", editeur);
         query.bindValue(":source", source);
         query.bindValue(":date_reportage", date);
         query.bindValue(":contenu_reportage", contenuReport);
         return query.exec();
}

QSqlQueryModel* Reportage ::trier(int i)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==1)
             {
                 model->setQuery("SELECT* FROM equipement ORDER BY EDITEUR asc");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT* FROM equipement ORDER BY SOURCE asc");
             }
    else if(i==3)
             {
                 model->setQuery("SELECT* FROM equipement ORDER BY DATE_REPORTAGE asc");
             }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code_R"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code_C"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Editeur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Source"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Contenu_R"));

    return model;
}