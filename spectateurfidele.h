
/*#ifndef SPECTATEURFIDELE_H
#define SPECTATEURFIDELE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class spectateurfidele
{
public:
    spectateurfidele();
    spectateurfidele(int,QString,QString,QString,QString);
    int get_id();
     int get_nbr_ticket();
     int get_age();
    QString get_adresse();
   QString  get_type_classe();

    //  QString get_ADRESSE_MAIL();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
private:
    QString adresse,type_classe;
int id,age,nbr_ticket;
};

#endif // SPECTATEURFIDELE_H
*/
