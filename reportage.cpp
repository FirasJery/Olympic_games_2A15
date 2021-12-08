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
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Source"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Editeur"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contenu_R"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code_C"));
    return model;
}

QSqlQueryModel* Reportage::recherche(QString c)
{
    //QString res= QString::number(cd_recherche);
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
        model->setQuery("select * from REPORTAGE where (CODE_REPORTAGE LIKE '%"+c+"%'  OR SOURCE LIKE '%"+c+"%'  OR EDITEUR LIKE '%"+c+"%' )");
       // query.bindValue(":CODE_REPORTAGE", c);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code_R"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Source"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Editeur"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contenu_R"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code_C"));     

    return model;
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
    Reportage R;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==0)
        model= R.afficher();
    if(i==1)
             {
                 model->setQuery("SELECT* FROM REPORTAGE ORDER BY EDITEUR asc");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT* FROM REPORTAGE ORDER BY SOURCE asc");
             }
    else if(i==3)
             {
                 model->setQuery("SELECT* FROM REPORTAGE ORDER BY DATE_REPORTAGE asc");
             }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code_R"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code_C"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Editeur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Source"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contenu_R"));

    return model;
}

QChart* Reportage::statistique()
{
    QString marque; //creation des variable qui vont prendre les valeurs trouvé

            QSqlQuery query;
           query.prepare("SELECT* FROM REPORTAGE");

           int total=0, nbre1=0, nbre2=0, nbre3=0;
           float val;

           query.exec();   // lancement de l'excution de la recherche
             while(query.next())
                 {
                  marque= query.value(2).toString();
                  if(marque=="Infosport")
                  nbre1 += query.value(3).toInt();

                  else if(marque=="BeinSport")
                  nbre2 += query.value(3).toInt();

                  else if(marque=="RMC Sport")
                  nbre3 += query.value(3).toInt();

                  total += query.value(3).toInt() ;
                 }


        QPieSeries *series = new QPieSeries();  //initialisation des parties


        series->setHoleSize(0.35);  //epaisseur du graphe
         val= nbre1*100/total;  //calcul du pourcentage
         QString nbre_string = QString::number(val);
        series->append("Infosport "+nbre_string+"%  ",val); //ajout d'une partie

        val= nbre2*100/total;
        nbre_string = QString::number(val);
        QPieSlice *slice = series->append("BeinSport "+nbre_string+"% ", val);  //on ajoute une partie et on creer une coupure de 15 px

        slice->setExploded();   //on detache la partie avec une coupé
        slice->setLabelVisible();

        val= nbre3*100/total;
        nbre_string = QString::number(val);
        series->append("RMC Sport "+nbre_string+"% ",val);

         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setAnimationOptions(QChart::SeriesAnimations);
         chart->setTitle("Statique selon les Sources ");
         chart->setTheme(QChart::ChartThemeBlueCerulean); //creation du theme
         chart->legend()->setVisible(true);

         return chart;

}


