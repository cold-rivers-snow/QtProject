#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include "ext.h"
#include <QHeaderView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setTabel();
    void setTabelH();
    ~MainWindow();

private slots:
        void cl();
        void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString insName;
    QSqlQuery query;        //数据库
    QString usrname;   //获取用户名
    int id;                 //获取id
    QString date;           //打卡日期
};

#endif // MAINWINDOW_H
