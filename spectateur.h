#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <QString>
#include<QSqlQueryModel>

class Spectateur
{
public:
    Spectateur();
    Spectateur(int,int,int,int,int,int,QString,QString);
    int getid();
    int getage();
    int getcapacite();
    int gethoraire_e();
    int gethoraire_s();
    int getnbr_ticket();
    QString getadresse();
    QString gettype_classe();
    void setid(int);
    void setage (int);
    void setcapacite(int);
    void sethoraire_e(int);
    void sethoraire_s(int);
    void setnbr_ticket(int);
    void setadresse(QString);
    void settype_classe(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
private:

    int id,age,capacite,horaire_e,horaire_s,nbr_ticket;
    QString adresse,type_classe;


};

#endif // SPECTATEUR_H
