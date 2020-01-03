#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT

public:
    explicit MyThread(QObject *parent = nullptr);
    MyThread(int num);

    void stop();

protected:
    void run();

private:
    bool threadStop;
    int number;
};

#endif // MYTHREAD_H
