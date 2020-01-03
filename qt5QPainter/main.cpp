#include "widget.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;

    QGraphicsRectItem *rect = scene.addRect(QRectF(0,0,100,100));
//    QGraphicsItem *item = scene.itemAt(50,50);


    QPainterPath path;
    path.moveTo(30,120);
    path.cubicTo(80,0,50,50,80,80);

    scene.addPath(path,QPen(Qt::black),QBrush(Qt::green));
    scene.addText("I love Qt programming.",QFont("Times",15,QFont::Bold));
    QGraphicsView view(&scene);
    view.show();




//    Widget w;
//    w.show();
    return a.exec();
}
