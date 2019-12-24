#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    painter.setPen(Qt::blue);
    painter.drawLine(10,10,100,40); //线
    painter.drawRect(120,10,80,80);//矩形

    QRectF rect(230.0,10.0,80.0,80.0);
    painter.drawRoundRect(rect,20,20);   //圆角矩形

    QPointF p1[3] = { QPointF(10.0,110.0),QPointF(110.0,110.0), QPointF(110.0,190.0) };
    painter.drawPolygon(p1,3);      //用线绘制指针支点


    QPointF p2[3] = { QPointF(120.0,110.0),QPointF(220.0,110.0), QPointF(220.0,190.0) };
    painter.drawPolygon(p2,3);      //用线绘制指针支点

    painter.setFont(QFont("Arial",20));
    painter.setPen(Qt::black);
    QRect font_rect(10,150,220,180);
    painter.drawText(font_rect,Qt::AlignCenter,"I love Qt");

    painter.end();

}
