#ifndef CUSTON_CPU_WIDGET_H
#define CUSTON_CPU_WIDGET_H

#include <QWidget>
#include <QPainter>

class custon_cpu_widget : public QWidget
{
    Q_OBJECT

public:
    custon_cpu_widget(QWidget *parent = nullptr);
    ~custon_cpu_widget();
    void cpu_set_widget_level(int level);       //设置cpu使用层级的成员函数

private:
    int w_width;        //控件宽度
    int w_height;       //控件高度
    int cpu_used_level; //将cpu使用率保存到变量的成员函数

protected:
    virtual void paintEvent(QPaintEvent *event); //描述cpu使用率的函数
};
#endif // CUSTON_CPU_WIDGET_H
