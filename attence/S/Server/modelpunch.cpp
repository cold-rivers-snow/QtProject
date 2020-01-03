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

    //输入打卡状态
    usr_punchl = new QLabel(this);
    usr_punchl->move(40,100);
    usr_punchl->setText("请输入打卡状态：");
    usr_punchl->setFont(ft);
    usr_punchl->adjustSize();

    usr_punche = new QLineEdit(this);
    usr_punche->move(200,100);
    usr_punche->adjustSize();

    //输入打卡时间
    usr_datel = new QLabel(this);
    usr_datel->move(40,160);
    usr_datel->setText("请输入打卡日期：");
    usr_datel->setFont(ft);
    usr_datel->adjustSize();

    usr_datee = new QLineEdit(this);
    usr_datee->move(200,160);
    usr_datee->adjustSize();

    //确定按钮
    ok = new QPushButton(this);
    ok->setFixedSize(100,50);
    ok->move(140,220);
    ok->setText("确定");
    ok->adjustSize();

    this->resize( QSize( 400, 300 ));//设置默认窗口大小
}

ModelPunch::~ModelPunch()
{
    delete ui;
}

QSize ModelPunch::sizeHint() const      //重载使得默认窗口大小
 {
     return QSize( 400, 300 );
 }
