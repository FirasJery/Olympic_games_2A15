#ifndef JOUEUR_H
#define JOUEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

class joueur
{
    int num;
    QString nom;
    QString prenom;
    int id;
    int age;
QString nationallite;

    public:
    joueur();
    joueur(QString,QString,QString , int,int, int );
    //
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int  getnum(){return num;}
    int  getid(){return id;}
    int  getage(){return age;}
    QString  getnationallite(){return nationallite;}
    //
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setnum(int nm){num=nm;}
    void setid(int i){id=i;}
    void setage(int a){age=a;}
    void setnationallite(QString na){nationallite=na;}
    //
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int );
    bool modifier(int );
    QSqlQueryModel *tri();
    QSqlQueryModel *triage();
    QSqlQueryModel *triNationallite();
    QSqlQueryModel *cherche_nom(QString );
    QSqlQueryModel *cherche_id(int );
    QSqlQueryModel  *cherche_num(int ) ;
    bool affecter(int,int);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);


};

#endif // JOUEUR_H
