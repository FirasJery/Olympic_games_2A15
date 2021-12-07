#ifndef DOSSIER_MEDICAL_H
#define DOSSIER_MEDICAL_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class competition
{int code_comp;
    QString nom , lieu , desc ,type;
    QDate date_d , date_f ;
public:
    competition();
    competition(QString,QString,QString,QString,QDate,QDate);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int) ;

    bool modifier(QString, QString, QString, QString, QDate,QDate,QString);
    ~competition (){}
};
#endif // DOSSIER_MEDICAL_H

