#include "modelpunch.h"
#include "ui_modelpunch.h"

ModelPunch::ModelPunch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModelPunch)
{
    ui->setupUi(this);
    QFont ft;
    ft.setPointSize(14);

    //输入用户id
    usr_idl = new QLabel(this);
    usr_idl->move(40,40);
    usr_idl->setText("请输入用户id:");
    usr_idl->setFont(ft);
    usr_idl->adjustSize();

    usr_ide = new QLineEdit(this);
    usr_ide->move(200,40);
    usr_ide->adjustSize();
    modelIdflag = false;

    //输入打卡状态
    usr_punchl = new QLabel(this);
    usr_punchl->move(40,100);
    usr_punchl->setText("请输入打卡状态：");
    usr_punchl->setFont(ft);
    usr_punchl->adjustSize();

    usr_punche = new QLineEdit(this);
    usr_punche->move(200,100);
    usr_punche->adjustSize();
    usr_punche->setPlaceholderText("未打卡、已打卡、请假");//设置提示字


    //输入打卡时间
    usr_datel = new QLabel(this);
    usr_datel->move(40,160);
    usr_datel->setText("请输入打卡日期：");
    usr_datel->setFont(ft);
    usr_datel->adjustSize();

    usr_datee = new QDateTimeEdit(this);//改成DateTime
    usr_datee->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    //上述格式为年月日，时分秒
    usr_datee->move(200,160);
    usr_datee->adjustSize();

    //确定按钮
    ok = new QPushButton(this);
    ok->setFixedSize(100,50);
    ok->move(160,220);
    ok->setText("确定");
    ok->adjustSize();
    connect(ok,&QPushButton::clicked,this,&ModelPunch::modelOk);
    this->resize( QSize( 460, 300 ));//设置默认窗口大小
}

ModelPunch::~ModelPunch()
{
    delete ui;
}

QSize ModelPunch::sizeHint() const      //重载使得默认窗口大小
 {
     return QSize( 400, 300 );
 }

void ModelPunch::modelAttence()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    db = QSqlDatabase::database("qt_sql_default_connection");
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("attence");
        db.setUserName("root");
        db.setPassword("root");
    }

    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open";

    QString tab_name = "user";
    QString check = QString("select user_id from %1").arg(tab_name);
    query.exec(check);

    while(query.next()){
        qDebug() << "11111"<<query.value(0).toInt() << endl;

        if(query.value(0).toInt() == usr_ide->text().toInt())
        {
            modelId1 = query.value(0).toInt();
            modelIdflag = true;
            break;
        }
    }

    QString modelPun = usr_punche->text();
    QString modelDate = usr_datee->text();
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间
    QString nowdate = QTime::currentTime().toString();
    if(modelIdflag)
    {
        if(modelPun == "未打卡")
            modelPunch = 0;
        else if(modelPun == "已打卡")
            modelPunch = 1;
        else if(modelPun == "请假")
            modelPunch = 2;
        else
            QMessageBox::information(this ,tr("提示") , tr("输入有误!"));
        QString str;
        if(modelDate <= "08:00:00")
        {
            //and work_date修改不进去
            str = QString("update atwork set user_state=%1 where user_id=%2 and work_date='%3'").arg(modelPunch).arg(modelId1).arg(modelDate);  //向数据库中修改数据，最好不要让atwork为%1。
        }
        if(modelDate >= "17:00:00")
        {
            str = QString("update atwork set user_state=%1 where user_id=%2 and work_date='%3'").arg(modelPunch).arg(modelId1).arg(modelDate);
        }
        if(modelDate > "08:00:00" && nowdate < "17:00:00")
        {
            QMessageBox::information(this,tr("提示"),tr("非打卡时间"));
            return;
        }
        bool ok = modelquery.exec(str);
        if(ok)
        {

            QMessageBox::information(this ,tr("提示") , tr("修改成功!"));
        }
        else
        {
            QMessageBox::information(this ,tr("提示") , tr("修改失败!"));
        }
        qDebug("插入成功");
    }
}

void ModelPunch::modelOk()
{
    modelAttence();
}
