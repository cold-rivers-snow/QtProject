#include "sql.h"

bool Sql::connectMySQL()
{
     m_db = QSqlDatabase::addDatabase("QMYSQL");
     m_query = new QSqlQuery(m_db);
     m_db.setHostName("127.0.0.1");
     m_db.setPort(3306);
     m_db.setDatabaseName("attence");
     m_db.setUserName("root");
     m_db.setPassword("root");
     if(!m_db.open()){

         qDebug() << "error";
         return false;
     }
     else
     {
         qDebug() << "OK";
     }

     return true;
}
