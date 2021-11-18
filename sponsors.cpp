#include "sponsors.h"
#include <QFile>
#include <QTextStream>


SPONSORS::SPONSORS()
{

}

SPONSORS::SPONSORS(int id, QString nom, QString type, int code, int budget, int etat){
    ID_SPONSOR = id;
    NOM_SPONSOR = nom;
    TYPE = type;
    CODE_COMPETITION = code;
    BUDGET = budget;
    ETAT = etat;
}

bool SPONSORS::Ajouter(){
    QSqlQuery query;
    QString res = QString::number(ID_SPONSOR);
    QString res1 = QString::number(CODE_COMPETITION);
    QString res2 = QString::number(BUDGET);
    QString res3 = QString::number(ETAT);
    query.prepare("INSERT INTO SPONSORS (ID_SPONSOR, NOM_SPONSOR, TYPE, CODE_COMPETITION, BUDGET, ETAT)""VALUES (:id, :nom, :type, :code, :budget, :etat)");
    query.bindValue(":id", res);
    query.bindValue(":nom", NOM_SPONSOR);
    query.bindValue(":type", TYPE);
    query.bindValue(":code", res1);
    query.bindValue(":budget", res2);
    query.bindValue(":etat", res3);

    return query.exec();
}

QSqlQueryModel * SPONSORS::Afficher(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSORS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool SPONSORS::Supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM SPONSORS WHERE ID_SPONSOR = :id");
    query.bindValue(":id", res);

    return query.exec();
}

bool SPONSORS::Modifier(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(CODE_COMPETITION);
    QString res2 = QString::number(BUDGET);
    QString res3 = QString::number(ETAT);
    query.prepare("UPDATE SPONSORS SET NOM_SPONSOR = :nom, TYPE = :type, CODE_COMPETITION = :code, BUDGET = :budget, ETAT = :etat WHERE ID_SPONSOR = :id");
    query.bindValue(":nom", NOM_SPONSOR);
    query.bindValue(":type", TYPE);
    query.bindValue(":code", res1);
    query.bindValue(":budget", res2);
    query.bindValue(":etat", res3);
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * SPONSORS::Triparnom(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSORS ORDER BY NOM_SPONSOR  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));


    return model;
}

QSqlQueryModel * SPONSORS::TriEtat(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSORS ORDER BY ETAT "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}
QSqlQueryModel * SPONSORS::TriBudget(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSORS ORDER BY BUDGET "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}
QSqlQueryModel * SPONSORS::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSORS WHERE ( ID_SPONSOR LIKE '%"+tst+"%' OR NOM_SPONSOR LIKE '%"+tst+"%' OR TYPE LIKE '%"+tst+"%' OR BUDGET LIKE '%"+tst+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool SPONSORS::Export(QString tst)
{
    QString Tex;
    bool test=false;
    QSqlQueryModel * model=new QSqlQueryModel;
            model->setQuery("SELECT BUDGET FROM SPONSORS WHERE ID_SPONSOR ="+tst);
            int rows = model->rowCount();
            for (int i = 0; i < rows; i++)
            {


            int a=model->data(model->index(0,i)).toInt();


            QString res=QString::number(a);
            QString b=QString::number(a*0.2);
            QString c=QString::number(a*0.3);
            QString d=QString::number(a*0.5);
            Tex += "Votre Budget de "+res+" se divise sur 3 proportions :\n"
                                               +b+" pour les frais d'organisation \n"
                                               +c+" pour les frais de médiatisation \n"
                                               +d+" pour les joueurs et les gagnants des compétitions\n "

                        ;
}
            QFile txtFile("Rapport_Financier.txt");
                if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    test=true;
                    QTextStream out(&txtFile);

                    out << Tex;
                    txtFile.close();
                }
                return test;
            }
int SPONSORS::alerte()
{
    int i=0;
    QSqlQuery query("SELECT ETAT FROM SPONSORS");
    while (query.next())
    {

        if (query.value(0).toInt()==0)
        {
            i++;
        }

    }
    return i;
}








