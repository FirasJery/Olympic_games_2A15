#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{
    int id_rec;
    QString categorie;
    QString etat;
    QString contenu;
    QDate date_a;
    QString mail;
    int id_j;
public:
    //Constructeurs
    Reclamation();
    Reclamation(int, QString,QString,QString,QDate,QString,int);
    //Getters
    int get_id(){return id_rec;}
    QString get_categorie(){return categorie;}
    QString get_etat(){return etat;}
    QString get_contenu(){return contenu;}
    QDate get_datea(){return date_a;}
    int get_idj(){return id_j;}
    //Setters
    void set_id(int a){id_rec=a;}
    void set_categorie(QString a){categorie=a;}
    void set_etat(QString b){etat=b;}
    void set_contenu(QString c){contenu=c;}
    void set_datea(QDate d){date_a=d;}
    void set_mail(QString m){mail=m;}
    void set_idj(int k){id_j=k;}
   //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
};

#endif // RECLAMATION_H
