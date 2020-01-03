#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPainter painter;
    painter.begin(this);

    QPen pen(Qt::blue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    pen.setWidth(4);
    painter.setPen(pen);

    QRect rect1(10.0,20.0,80.0,50);
    painter.drawEllipse(rect1);

    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    QRect rect2(110.0,20.0,80.0,50.0);
    painter.drawEllipse(rect2);

    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(30,30,200,30);

    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(30,70,200,70);

    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawLine(30,110,200,110);

    QPointF p1[3] = {QPointF(30.0,80.0),QPointF(20.0,40.0),QPointF(80.0,60.0)};
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    painter.drawPolyline(p1,3);

    QPointF p2[3] = {QPointF(130.0,80.0),QPointF(120.0,40.0),QPointF(180.0,60.0)};
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawPolyline(p2,3);

    QPointF p3[3] = {QPointF(230.0,80.0),QPointF(220.0,40.0),QPointF(280.0,60.0)};
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawPolyline(p3,3);

    //填充QBrush
    painter.setBrush(QBrush(Qt::green,Qt::Dense3Pattern));
    painter.setPen(Qt::blue);
    painter.drawEllipse(10,10,100,100);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::blue);
    painter.drawEllipse(80,10,100,100);

    QPixmap pixmap(":resources/qtblog.png");
    int w = pixmap.width();
    int h = pixmap.height();
    pixmap.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QBrush brush(pixmap);
    painter.setBrush(brush);
    painter.setPen(Qt::blue);
    painter.drawRect(0,0,w,h);

    QRadialGradient gradient(50,50,50,50,50);
    gradient.setColorAt(0,QColor::fromRgbF(0,1,0,1));
    gradient.setColorAt(1,QColor::fromRgbF(0,0,0,0));
    QBrush brush1(gradient);

    painter.setBrush(brush1);
    painter.drawRect(0,0,100,100);


    //渐变
    QLinearGradient ling(QPointF(70,70),QPoint(140,140));       //起点，终点
    ling.setColorAt(0,Qt::blue);
    ling.setColorAt(1,Qt::green);

    ling.setSpread(QGradient::PadSpread);

    QBrush brush2(ling);
    painter.setBrush(brush2);
    painter.drawRect(0,0,200,200);

    QRadialGradient radg(100,100,50,120,120);

    radg.setSpread(QGradient::PadSpread);
    radg.setColorAt(0,Qt::black);
    radg.setColorAt(1,Qt::white);

    QBrush brush3(radg);
    painter.setBrush(brush3);
    painter.drawRect(0,0,200,200);

    QConicalGradient cong(100,100,45.0);
    cong.setColorAt(0,Qt::black);
    cong.setColorAt(1,Qt::white);

    QBrush brush4(cong);
    painter.setBrush(brush4);
    painter.drawRect(0,0,200,200);

    //转换  使界面扩大、缩小、旋转、远近
    QImage image(":recourse/qtblog.png");

    QPainter painter1(this);
    painter1.setPen(QPen(Qt::blue,1,Qt::DashLine));
    painter1.drawRect(0,0,100,100);

    QTransform transfrom;
    transfrom.translate(50,50);
    transfrom.rotate(45);
    transfrom.scale(0.5,0.5);

    painter1.setTransform(transfrom);
    painter1.drawImage(0,0,image);


    painter1.drawRect(0,0,100,100);

    QTransform transfrom1;
    transfrom1.translate(50,50);
    transfrom1.rotate(70,Qt::YAxis);

    painter1.setTransform(transfrom1);
    painter1.drawImage(0,0,image);

    //组合
//    painter1.drawImage(0,0,destinationImage);
//    painter1.setCompositionMode(QPainter::CompositionMode_DestinationOver);
//    painter1.drawImage(0,0,sourceImage);




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
