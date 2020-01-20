#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "ext.h"

class LoginForm : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏
public:
    explicit LoginForm(QDialog *parent = 0);  //explicit 防止歧义
    bool connectMySQL();
    void selMySQL(QString check);


signals:

public slots:
    void login();//点击登录按钮是执行的槽函数
private:
    QLabel *userNameLbl;         //"用户名"标签
    QLabel *pwdLbl;              //"密码"标签
    QLineEdit *userNameLEd;      //用户名编辑行
    QLineEdit *pwdLEd;           //密码编辑行
    QPushButton *loginBtn;       //登录按钮
    QPushButton *exitBtn;        //退出按钮
    QSqlDatabase m_db;          //数据库
    QSqlQuery *m_query;
    QSqlQuery query;            //数据库查询
    QString name,passwd;        //数据库中的用户名和密码
    int id;
};


#endif // LOGIN_H
