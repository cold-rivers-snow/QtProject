#include "mainfrom.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent)
{

    tipLbl = new QLabel(this);

    tipLbl->move(60,40);
    //tipLbl->setFixedSize(100,100);
//    QPushButton* pb = new QPushButton();
//    pb->setText("ok");
    pb = new QPushButton(this);
    pb->setFocus();
    pb->setDefault(true);   //默认按钮
    //pb->setShortcut( QKeySequence::InsertParagraphSeparator );

    pb->move(55,70);
    pb->setText("OK");
    tipLbl->setText(tr("欢迎登录"));
    connect(pb,&QPushButton::clicked,this,&MainForm::close);
    //connect(pb, SIGNAL(returnPressed()), this,&MainForm::close);

}
