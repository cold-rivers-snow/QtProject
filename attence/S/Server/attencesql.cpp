//#include "attencesql.h"

//attenceSql::attenceSql(QDialog *parent) :
//    QDialog(parent)
//{
//    //数据库连接
//    connectMySQL();


//}

//bool attenceSql::connectMySQL()
//{
//     m_db = QSqlDatabase::addDatabase("QMYSQL");
//     m_query = new QSqlQuery(m_db);
//     m_db.setHostName("127.0.0.1");
//     m_db.setPort(3306);
//     m_db.setDatabaseName("attence");
//     m_db.setUserName("root");
//     m_db.setPassword("root");
//     if(!m_db.open()){

//         qDebug() << "error";
//         return false;
//     }
//     else
//     {
//         qDebug() << "OK";
//     }

//     return true;
//}


//void attenceSql::selMySQL(QString check)
//{
//    m_query->exec(check);
//    while(m_query->next()){
//        name = m_query->value(0).toString();
//        passwd = m_query->value(1).toString();
//        id = m_query->value(2).toString();
//    }
//}
