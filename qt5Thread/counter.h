#ifndef COUNTER_H
#define COUNTER_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>


class Counter
{
public:
    Counter(){n = 0;}

    void increment() { QMutexLocker locker(&mutex); ++n;}
    void decrement() { QMutexLocker locker(&mutex); --n;}
    int value() const { QMutexLocker locker(&mutex); return n;}

private:
    mutable QMutex mutex;
    int n;
};

#endif // COUNTER_H
