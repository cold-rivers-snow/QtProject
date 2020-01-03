#include "mainwindow.h"

#include <QApplication>
#include "modelpunch.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ModelPunch w;
    w.show();
    return a.exec();
}
