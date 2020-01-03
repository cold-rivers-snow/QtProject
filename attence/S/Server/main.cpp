#include "mainwindow.h"
#include "login.h"
#include "mainfrom.h"
#include "punch.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /**
    //测试数据库部分
    qDebug() << QCoreApplication::libraryPaths();
    qDebug() << QSqlDatabase::drivers()<<endl; //列出qt可用的数据库

    //链接mysql
    QCoreApplication::addLibraryPath("/opt/Qt5.9.1/5.9.1/gcc_64/plugins/sqldrivers/libqsqlmysql.so");
    QSqlDatabase db(QSqlDatabase::addDatabase("QMYSQL"));
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("attence");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) //测试数据库是否链接成功
    {
       QMessageBox::critical(0, QObject::tr("Databse Error"), db.lastError().text());
       qDebug() << db.lastError() << endl;
    }
    else
    {
       qDebug() << "Ok" << endl;
    }
    */



    //欢迎界面
    MainForm *main1 = new MainForm();
    main1->setWindowTitle("欢迎界面");//设置窗体标题
    main1->setFixedSize(200,150);
    main1->move ((QApplication::desktop()->width() - main1->width())/2,(QApplication::desktop()->height() - main1->height())/2);//设置窗体的位置居中

    //登录界面
    LoginForm login;
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {
       main1->show();
       a.exec();
    }
    else
        return 0;


    //考勤界面
    Punch *p = new Punch();
    p->setWindowTitle("考勤系统");//设置窗体标题
    p->setFixedSize(450,300);
    p->move ((QApplication::desktop()->width() - p->width())/2,(QApplication::desktop()->height() - p->height())/2);
    p->show();



    return a.exec();
}
