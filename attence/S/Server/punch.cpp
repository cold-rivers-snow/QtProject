#include "punch.h"


Punch::Punch(QDialog *parent) :
    QDialog(parent)
{
    //设置字体大小
    QFont ft;
    ft.setPointSize(14);

    state = 0;  //打卡状态

    //现在时间标签
    timenow = new QLabel(this);
    timenow->move(40,60);
    timenow->setText("现在时间：");
    timenow->setFont(ft);

    //显示时间
    QTimer* tr = new QTimer(this);
    dt = new QDateTimeEdit(this);
    dt->setFixedSize(280,32);
    dt->move(130,60);
    dt->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    dt->setDateTime(QDateTime::currentDateTime());
    connect(tr,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    tr->start(1000);
    dt->setFont(ft);


    //修改用户打卡按钮
    punch = new QPushButton(this);
    punch->move(20,140);
    punch->setText("更改打卡"); //插入id，打卡状态，时间
    punch->setFixedSize(110,110);
    connect(punch,&QPushButton::clicked,this,&Punch::punchslot);
    btn = false;

    QTimer *time_clock=new QTimer(parent);

    connect(time_clock,SIGNAL(timeout()),this,SLOT(timeinsert()));
    time_clock->start(1000);

    //修改用户密码按钮
    modifyPss = new QPushButton(this);
    modifyPss->move(170,140);
    modifyPss->setText("更改密码"); //插入id，原密码，新密码
    modifyPss->setFixedSize(110,110);
    connect(modifyPss,&QPushButton::clicked,this,&Punch::punchPasswd);


    //查询按钮
    sel = new QPushButton(this);
    sel->move(320,140);
    sel->setText("查询");
    sel->setFixedSize(110,110);
    connect(sel,&QPushButton::clicked,this,&Punch::selslot);


}

void Punch::timerUpdate()
{
    dt->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    dt->setDateTime(QDateTime::currentDateTime());
}

void Punch::timeinsert()
{
    if(!btn && (QTime::currentTime().toString() == "08:00:00" || QTime::currentTime().toString() == "17:00:00"))
    {
        modefyPunch();            //待改
        qDebug("插入成功0");
    }
}

//修改打卡按钮的槽函数
void Punch::punchslot()
{
//    state = 1;
//    btn = true;
//    insertSQL();
    //出现一个界面，接收输入，用户id，打卡状态，打卡日期。
    //设置字体大小
    //修改打卡界面
    mw = new ModelPunch(this);
    mw->move ((QApplication::desktop()->width() - mw->width())/2,(QApplication::desktop()->height() - mw->height())/2);
    mw->setWindowTitle("修改打卡系统");
    mw->setBaseSize(1800,1600);
    mw->setWindowModality(Qt::ApplicationModal); //父窗口进入子窗口后，父窗口不可用
    mw->show();
    //modefyPunch();            //已改
}

//修改用户密码的槽函数
void Punch::punchPasswd()
{
    //出现一个界面，接收输入，用户id，原密码，新密码。
    //设置字体大小
    //修改打卡界面
    mw1 = new ModelPasswd(this);
    mw1->move ((QApplication::desktop()->width() - mw1->width())/2,(QApplication::desktop()->height() - mw1->height())/2);
    mw1->setWindowTitle("修改用户密码系统");
    mw1->setBaseSize(1800,1600);
    mw1->setWindowModality(Qt::ApplicationModal); //父窗口进入子窗口后，父窗口不可用
    mw1->show();
}


//查询的槽函数
void Punch::selslot()
{
    //查询界面
    w = new MainWindow(this);
    w->move ((QApplication::desktop()->width() - w->width())/2,(QApplication::desktop()->height() - w->height())/2);
    w->setWindowTitle("查询系统");
    w->setWindowModality(Qt::ApplicationModal); //父窗口进入子窗口后，父窗口不可用
    w->show();
}

//插入数据库打卡状态
void Punch::modefyPunch()
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


    insName = insertName;

//    insName = "john";
    QString tab_name = "user";
    QString check = QString("select user_name,user_id from %1").arg(tab_name);
    query.exec(check);
    int qid;
    while(query.next()){
        usrname = query.value(0).toString();
        id = query.value(1).toInt();
        if(usrname == insName)
        {
            qid = id;
            break;
        }
    }
    date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString nowdate = QTime::currentTime().toString();
    qDebug() << insName << usrname << qid  << date << endl;
    QString str;
    if(nowdate <= "08:00:00")
    {
        str = QString("insert into atwork (user_name, user_id, user_state,work_date) "
                              "values('%1', '%2', '%3','%4')").arg(insName).arg(qid).arg(state).arg(date);  //向数据库中插入数据，最好不要让atwork为%1。
    }
    if(nowdate >= "17:00:00")
    {
        str = QString("insert into offwork (user_name, user_id, user_state,work_date) "
                              "values('%1', '%2', '%3','%4')").arg(insName).arg(qid).arg(state).arg(date);
    }
    if(nowdate > "08:00:00" && nowdate < "17:00:00")
    {
        QMessageBox::information(this,tr("提示"),tr("非打卡时间"));
        return;
    }
    bool ok = insertquery.exec(str);
    if(ok)
    {

        QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
    }
    else
    {
        QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
    }
    qDebug("插入成功");
}



