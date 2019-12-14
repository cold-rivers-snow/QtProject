#include "widget.h"
#include "ui_widget.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_isRun = false;
    connectMySQL();
    m_timer = new QTimer(this);
    this->setWindowTitle("随机修改数据库中值");
    connect(m_timer, SIGNAL(timeout()), this, SLOT(sqlDataTimeout()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

Widget::~Widget()
{
    delete ui;
    delete m_query;
}

bool Widget::connectMySQL()
{
     m_db = QSqlDatabase::addDatabase("QMYSQL");
     m_query = new QSqlQuery(m_db);
     m_db.setHostName("127.0.0.1");
     m_db.setPort(3306);
     m_db.setDatabaseName("mysql");
     m_db.setUserName("root");
     m_db.setPassword("root");
     if(!m_db.open()){

         qDebug() << "error";
         return false;
     }

     return true;
}

void Widget::upateMySQL()
{
    m_timer->start(1000);
}

QStringList Widget::selectAppropriateData(const QString &cmd)
{
    QStringList list;
    if(!m_query->exec(cmd) || m_query->size() == 0){

        return list;
    }

    while(m_query->next()){

        list << m_query->value(0).toString();
    }
    return list;
}

void Widget::btnClicked()
{
    if(!m_isRun){

        upateMySQL();
        ui->pushButton->setText("停止");
    }
    else{
        ui->pushButton->setText("开始");
        m_timer->stop();
    }

    m_isRun = !m_isRun;
}

void Widget::sqlDataTimeout()
{
    QStringList list = selectAppropriateData("select idval from sourcenetload.datasample");


    //更新每一个
    for(int i = 0; i < list.size(); i++){

        int numData = qrand()%655350;
        QString valueDataStr = QString("update sourcenetload.datasample set value=%1 where idval=%2").arg(QString::number(numData)).arg(list[i]);
        //qDebug() << valueDataStr;
        m_query->exec(valueDataStr);
    }


    list = selectAppropriateData("select id from sourcenetload.circle");

    //更新每一个
    for(int i = 0; i < list.size(); i++){

        int numData = qrand()%2;
        QString valueDataStr = QString("update sourcenetload.circle set isRun=%1 where id=%2").arg(QString::number(numData)).arg(list[i]);
        //qDebug() << valueDataStr;
        m_query->exec(valueDataStr);
    }

}

