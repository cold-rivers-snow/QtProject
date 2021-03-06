#ifndef MODELPUNCH_H
#define MODELPUNCH_H

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

namespace Ui {
class ModelPunch;
}

class ModelPunch : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModelPunch(QWidget *parent = nullptr);
    ~ModelPunch();
    void modelAttence();

    QSize sizeHint() const;

public slots:
    void modelOk();
private:
    Ui::ModelPunch *ui;
    QLabel *usr_idl,*usr_punchl,*usr_datel;
    QLineEdit *usr_ide,*usr_punche;
    QDateTimeEdit *usr_datee;
    QPushButton *ok;
    QSqlQuery modelquery,query;
    int modelId1;
    bool modelIdflag;//标志modelid是否要修改
    int modelPunch;
};

#endif // MODELPUNCH_H
