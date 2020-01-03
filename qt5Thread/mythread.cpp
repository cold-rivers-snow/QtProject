#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread(parent)
{
}

MyThread::MyThread(int num)
{
    number = num;
}

void MyThread::stop()
{
    threadStop = true;
    qDebug("[%d] Thread stop",number);
}

void MyThread::run()
{
    threadStop = false;
    int i = 0;

    while(!threadStop)
    {
        qDebug("[%d] MyThread %d",number,i);
        i++;
        sleep(1);
    }
}
