#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Olympic-game");
db.setUserName("Giovanni");//inserer nom de l'utilisateur
db.setPassword("Giovanni");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
