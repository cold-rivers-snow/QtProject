#include "login.h"

LoginForm::LoginForm(QDialog *parent) :
    QDialog(parent)
{
    //设置窗体标题
    this->setWindowTitle(tr("登录界面"));

//    insertName = "";

    //设置字体大小
    QFont ft;
    ft.setPointSize(14);

    //用户名Label
    userNameLbl = new QLabel(this);   //new一个标签对象
    userNameLbl->move(55,80);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
    userNameLbl->setText("用户名:");  //设置标签文本
    userNameLbl->setFont(ft);

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(120,80);
    userNameLEd->setPlaceholderText(tr("请输入用户名!"));//占位符
    userNameLEd->setFont(ft);

    //密码Label
    pwdLbl = new QLabel(this);
    pwdLbl->move(65,130);
    pwdLbl->setText("密码:");
    pwdLbl->setFont(ft);

    //密码输入框
    pwdLEd = new QLineEdit(this);
    pwdLEd->move(120,130);
    pwdLEd->setPlaceholderText("请输入密码!");
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示
    pwdLEd->setFont(ft);

    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn->move(80,200);
    loginBtn->setText("登录");
    loginBtn->setFont(ft);

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->move(170,200);
    exitBtn->setText("退出");
    exitBtn->setFont(ft);

    //单击登录按钮时 执行 LoginForm::login 槽函数(自定义)；单击退出按钮时 执行 LoginForm::close 槽函数(窗体的关闭函数，不用自己写)
    connect(loginBtn,&QPushButton::clicked,this,&LoginForm::login);
    connect(exitBtn,&QPushButton::clicked,this,&LoginForm::close);

    //数据库连接
    connectMySQL();


}

void LoginForm::login()
{    
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    QString tab_name = "user";
    QString check = QString("select user_name,user_passwd from %1 where user_permission = 0 ").arg(tab_name);

    //selMySQL(check);
    m_query->exec(check);
    while(m_query->next()){
        name = m_query->value(0).toString();
        passwd = m_query->value(1).toString();
        id = m_query->value(2).toString();


    if(userNameLEd->text().trimmed() == name && pwdLEd->text() == passwd)
    {
        insertName = name;
        accept();//关闭窗体，并设置返回值为Accepted

        qDebug() << insertName ;
        break;
    }

   }
    if(userNameLEd->text().trimmed() != name || pwdLEd->text() != passwd)
    {
        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

     // 清空输入框内容
       // userNameLEd->clear();
        pwdLEd->clear();

        //光标定位
        pwdLEd->setFocus();
    }
//    else
//    {                              //标题              内容                OK按钮
//       QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

//    // 清空输入框内容
//       userNameLEd->clear();
//       pwdLEd->clear();

//       //光标定位
//       userNameLEd->setFocus();
//    }

    /*
    //测试登录部分
    if(userNameLEd->text().trimmed() == tr("chen") && pwdLEd->text() == tr("11"))
    {
       accept();//关闭窗体，并设置返回值为Accepted
    }
    else if(userNameLEd->text().trimmed() == tr("chen") && pwdLEd->text() != tr("11"))
    {
        QMessageBox::warning(this, tr("警告！"),tr("密码错误！"),QMessageBox::Yes);

     // 清空输入框内容
       // userNameLEd->clear();
        pwdLEd->clear();

        //光标定位
        pwdLEd->setFocus();
    }
    else
    {                              //标题              内容                OK按钮
       QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

    // 清空输入框内容
       userNameLEd->clear();
       pwdLEd->clear();

       //光标定位
       userNameLEd->setFocus();
    }
    */
}

bool LoginForm::connectMySQL()
{
     m_db = QSqlDatabase::addDatabase("QMYSQL");
     m_query = new QSqlQuery(m_db);
     m_db.setHostName("127.0.0.1");
     m_db.setPort(3306);
     m_db.setDatabaseName("attence");
     m_db.setUserName("root");
     m_db.setPassword("root");
     if(!m_db.open()){

         qDebug() << "error";
         return false;
     }
     else
     {
         qDebug() << "OK";
     }

     return true;
}


void LoginForm::selMySQL(QString check)
{
    m_query->exec(check);
    while(m_query->next()){
        name = m_query->value(0).toString();
        passwd = m_query->value(1).toString();
        id = m_query->value(2).toString();
    }
}
