#include "mainwindow.h"
#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    //链接mysql

    QSqlDatabase db(QSqlDatabase::addDatabase("QMYSQL"));
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("attence");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) //测试数据库是否链接成功
    {
      // QMessageBox::critical(0, QObject::tr("Databse Error"), db.lastError().text());
       qDebug() << db.lastError() << endl;
    }
    else
    {
       qDebug() << "Ok" << endl;
    }

    return app.exec();
}

