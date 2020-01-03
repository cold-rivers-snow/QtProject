#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread1 = new MyThread(1);
    thread2 = new MyThread(2);

    connect(thread1,SIGNAL(stop()),this,SLOT(slot_stoped()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::btn_start()
{
    thread1->start();
    thread2->start();
}
void Widget::btn_isRunning()
{
    if(thread1->isRunning())
        qDebug("[1] Thread is running");
    else
        qDebug("[1] Thread is not running");
}

void Widget::btn_isFinished()
{
    if(thread1->isFinished())
        qDebug("[1] Thread is Finish");
    else
        qDebug("[1] Thread is not Finish");
}

void Widget::slot_stoped()
{
    qDebug("Thread started");
}
