#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "custon_cpu_widget.h"
#include "custon_slider_widget.h"
#include <QPixmap>
#include <QBitmap>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    //Slider信号事件关联的槽函数
    void mvaluechanged(int value);

private:
    Ui::Widget *ui;
    custon_cpu_widget *cpu_widget;      //声明CPU  USED 控件
    custon_slider_widget *slider_widget;    //声明slider事件
    bool m_embedded;
    QPixmap m_device;       //mask窗口区域的背景图片资源
protected:
    void update_background();   //改变窗口样式
    virtual void paintEvent(QPaintEvent *event);
};
#endif // WIDGET_H
