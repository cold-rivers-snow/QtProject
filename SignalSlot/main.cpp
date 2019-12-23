#include "mainwindow.h"

#include <QApplication>
#include "signalslot.h"
#include <QLabel>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel *lb = new QLabel();
    lb->setGeometry(10,10,100,40);

    SignalSlot s1,s2;
    QObject::connect(&s1,SIGNAL(valueChanged(int)),&s2,SLOT(setValue(int)));

    s1.setValue(50);
    qDebug() << s2.value();
    lb->setText(QString("%1").arg(s2.value()));

    w.show();
    return a.exec();
}
