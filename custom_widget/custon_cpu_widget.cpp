#include "custon_cpu_widget.h"

custon_cpu_widget::custon_cpu_widget(QWidget *parent)
    : QWidget(parent)
{
    this->w_width = 80;
    this->w_height = 100;
    resize(QSize(this->w_width,this->w_height));
    setFixedSize(this->w_width,this->w_height);//设置控件大小
    this->cpu_used_level = 10;
}

custon_cpu_widget::~custon_cpu_widget()
{

}

void custon_cpu_widget::cpu_set_widget_level(int level)
{
    this->cpu_used_level = level;
    this->repaint();    //调用repaint()会调用PaintEvent()
}


void custon_cpu_widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QColor(0,0,0));  //图形外轮廓线颜色
    painter.setBrush(QColor(0,0,0));//图形内部填充颜色
    painter.drawRect(0,0,this->w_width,this->w_height);

    int i;
    for(i = 21;i >= 0;i--)
    {
        if(this->cpu_used_level > i)
            painter.setBrush(QColor(153,255,0));        //used color;
        else
            painter.setBrush(QColor(51,102,0));         //free color        绘制矩形

        painter.drawRect(6,(this->w_height - 8) - (i * 4),30,3);        //指定宽度和高度
        painter.drawRect(43,(this->w_height - 8) - (i * 4),30,3);
    }
}
