#include "insertuser.h"


Insertuser::Insertuser(QWidget *parent) :
    QMainWindow(parent)
{
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


    //输入用户名
    usr_passwdl = new QLabel(this);
    usr_passwdl->move(40,100);
    usr_passwdl->setText("请输入用户名：");        //输入密码框带小眼睛，可以优化修改
    usr_passwdl->setFont(ft);
    usr_passwdl->adjustSize();

    usr_passwde = new QLineEdit(this);
    usr_passwde->move(200,100);
    usr_passwde->adjustSize();


    //输入新密码
    usr_passwdagainl = new QLabel(this);
    usr_passwdagainl->move(40,160);
    usr_passwdagainl->setText("请输入新密码：");
    usr_passwdagainl->setFont(ft);
    usr_passwdagainl->adjustSize();

    usr_passwdagaine = new QLineEdit(this);
    usr_passwdagaine->move(200,160);
    usr_passwdagaine->adjustSize();
    usr_passwdagaine->setEchoMode(QLineEdit::Password);

    //输入再次输入新密码
    usr_passwdagainl1 = new QLabel(this);
    usr_passwdagainl1->move(40,220);
    usr_passwdagainl1->setText("请输入新密码：");
    usr_passwdagainl1->setFont(ft);
    usr_passwdagainl1->adjustSize();

    usr_passwdagaine1 = new QLineEdit(this);
    usr_passwdagaine1->move(200,220);
    usr_passwdagaine1->adjustSize();
    usr_passwdagaine1->setEchoMode(QLineEdit::Password);


    //输入再次输入新密码
    user_permission = new QLabel(this);
    user_permission->move(40,280);
    user_permission->setText("是否为管理员：");
    user_permission->setFont(ft);
    user_permission->adjustSize();


    QString str1B = "否";
    QString str0B = "是";

    group = new QButtonGroup(this);


    radio0 = new QRadioButton(str0B,this);
    group->addButton(radio0);
    radio0->move(200,280);

    radio1 = new QRadioButton(str1B,this);
    group->addButton(radio1);
    radio1->move(300,280);

    //确定按钮
    ok = new QPushButton(this);
    ok->setFixedSize(100,50);
    ok->move(160,340);
    ok->setText("确定");
    ok->adjustSize();
    connect(ok,&QPushButton::clicked,this,&Insertuser::modelOk);
    this->resize( QSize( 460, 400 ));//设置默认窗口大小
}

Insertuser::~Insertuser()
{

}

QSize Insertuser::sizeHint() const      //重载使得默认窗口大小
 {
     return QSize( 400, 300 );
 }


void Insertuser::modelAttence()
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
    QString check = QString("select user_id,user_passwd from %1").arg(tab_name);
    query.exec(check);

    while(query.next()){
        qDebug() << "11111"<<query.value(0).toInt() << endl;

        if(query.value(0).toInt() == usr_ide->text().toInt())
        {
            modelId1 = query.value(0).toInt();
            modelIdPasswd = query.value(1).toString();
            modelIdflag = true;
            break;
        }
    }


    if(!modelIdflag && usr_passwdagaine->text() == usr_passwdagaine1->text())
    {
        int permission = 0;
        if(radio0->isChecked())
            permission = 1;

        QString str = QString("insert into user(user_name,user_id,user_passwd,user_permission) values ('%1',%2,'%3',%4)").arg(usr_passwde->text()).arg(usr_ide->text().toInt()).arg(usr_passwdagaine->text()).arg(permission);  //向数据库中修改数据，最好不要让atwork为%1。
        bool ok = modelquery.exec(str);
        if(ok)
        {
            QMessageBox::information(this ,tr("提示") , tr("插入用户成功!"));
            //以后考虑当前登录的用户如果该密码成功，则要退出当前界面，重新登录。
            if(yid == modelId1)
            {
                //关闭所有界面，弹出登录界面
            }
        }
        else
        {
            QMessageBox::information(this ,tr("提示") , tr("插入用户失败!"));
        }
        qDebug("插入成功");
    }
    else
    {
        //QMessageBox::information(this ,tr("提示") , tr("密码或id错误!"));

    }
}

void Insertuser::modelOk()
{
    modelAttence();
}
