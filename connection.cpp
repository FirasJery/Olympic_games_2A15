#include "connection.h"
#include <QtSql/QSqlDatabase>


connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("My_database");
db.setUserName("firas");//inserer nom de l'utilisateur
db.setPassword("firas");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}


//void Connection::fermerConnexion()
//{
  //  db.close();
//}
