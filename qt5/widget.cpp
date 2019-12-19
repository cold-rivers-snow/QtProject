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

void Widget::paintEvent(QPaintEvent *event) //创建QWidget窗口需要调用QPaintEvent事件。 重新绘制时使用：paint()和repaint()。
{
    Q_UNUSED(event);    //不使用已声明的函数或数据变量时，使用Q_UNUSED()函数，不会输出警告。
    QString img_full_name;

    QPainter painter(this);

    img_full_name = QString("%1/%2").arg("resources").arg("browser.png");
   // img_full_name = "qqqqqqqqqqqqqqqqq";

    QImage image(img_full_name);
    painter.drawPixmap(0,0,QPixmap::fromImage(image.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    painter.end();
}


void Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Resize Event call]");
    qDebug("width : %d,height : %d",this->width(),this->height());
}



void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Press] x,y:%d,%d",this->x(),this->y());
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Release] x,y:%d,%d",this->x(),this->y());
}
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse DoubleClick] x,y:%d,%d",this->x(),this->y());
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Move] x,y:%d,%d",this->x(),this->y());
}

void Widget::whellEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse whell] x,y:%d,%d",this->x(),this->y());
}
void Widget::enterEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse enter] x,y:%d,%d",this->x(),this->y());
}

void Widget::leaveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse leave] x,y:%d,%d",this->x(),this->y());
}
void Widget::closeEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    //qDebug("[Mouse close] x,y:%d,%d",this->x(),this->y());
    qDebug("Mouse close");
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Press Event");

    switch (event->key()) {
    case Qt::Key_A:
            if(event->modifiers() == true)
                qDebug("A");
            else
                qDebug("a");
            qDebug("%x",event->key());
            break;
    default:
        break;
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Press Event");
}
void Widget::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Press Event");
}
void Widget::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Press Event");
}
