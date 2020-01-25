#ifndef INSERTUSER_H
#define INSERTUSER_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QMessageBox>
#include <QDateTimeEdit>
#include "ext.h"
#include <QRadioButton>
#include <QButtonGroup>

class Insertuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit Insertuser(QWidget *parent = nullptr);
    ~Insertuser();
    void modelAttence();

    QSize sizeHint() const;

public slots:
    void modelOk();
private:
    QLabel *usr_idl,*usr_passwdl,*usr_passwdagainl,*usr_passwdagainl1,*user_permission;
    QLineEdit *usr_ide,*usr_passwde,*usr_passwdagaine,*usr_passwdagaine1;
    QPushButton *ok;
    QSqlQuery modelquery,query;
    int modelId1;
    bool modelIdflag;//标志modelid是否要修改
    int modelPasswd;
    QString modelIdPasswd;//原密码
    QRadioButton* radio0;
    QRadioButton* radio1;

    QButtonGroup*  group;
};

#endif // INSERTUSER_H
