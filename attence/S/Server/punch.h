#ifndef PUNCH_H
#define PUNCH_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QDateTimeEdit>
#include <QDateTime>
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include "login.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "modelpunch.h"
#include "modelPasswd.h"
#include "insertuser.h"
class Punch : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏
public:
    explicit Punch(QDialog *parent = 0);  //explicit 防止歧义
    void modefyPunch();

signals:

public slots:
    void punchPasswd();//点击修改密码的执行的槽函数
    void punchslot();//点击打卡按钮是执行的槽函数
    void selslot(); //点击查询按钮执行槽函数
    void timerUpdate();
    void timeinsert();
    void insertUser();
private:
    QLabel *timenow;         //现在时间 标签
    QPushButton *punch;       //修改打卡按钮
    QPushButton *insertNameP;       //修改打卡按钮
    QDateTimeEdit *dt;      //时间显式
    QPushButton *sel;       //查询按钮
    MainWindow* w;          //查询窗口
    ModelPunch* mw;         //修改打卡窗口
    ModelPasswd* mw1;       //修改用户密码
    Insertuser* mw2;       //修改用户密码
    QString insName;
    QString usrname;   //获取用户名
    int id;                 //获取id
    int state;              //获取打卡状态
    QString date;           //打卡日期
    QSqlQuery insertquery,query;        //数据库
    bool btn;
    QPushButton *modifyPss;       //修改密码

};



#endif // PUNCH_H
