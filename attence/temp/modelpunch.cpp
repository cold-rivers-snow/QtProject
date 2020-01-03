#include "modelpunch.h"


ModelPunch::ModelPunch(QWidget *parent) :
    QWidget(parent)
{
    QFont ft;
    ft.setPointSize(14);

    //输入用户id
    usr_idl = new QLabel(this);
    usr_idl->move(40,60);
    usr_idl->setText("请输入用户id:");
    usr_idl->setFont(ft);

    usr_ide = new QLineEdit(this);
    usr_ide->move(200,60);

    //输入打卡状态
    usr_punchl = new QLabel(this);
    usr_punchl->move(40,100);
    usr_punchl->setText("请输入打卡状态：");
    usr_punchl->setFont(ft);

    usr_punche = new QLineEdit(this);
    usr_punche->move(200,100);

    //输入打卡时间
    usr_datel = new QLabel(this);
    usr_datel->move(40,140);
    usr_datel->setText("请输入打卡日期：");
    usr_datel->setFont(ft);

    usr_datee = new QLineEdit(this);
    usr_datee->move(200,140);

    //确定按钮
    ok = new QPushButton(this);
    ok->setFixedSize(100,50);
    ok->move(140,180);
    ok->setText("确定");
}

ModelPunch::~ModelPunch()
{

}
