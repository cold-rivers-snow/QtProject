#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Q_UNUSED(parent);

    update_background();        //调用改变窗口样式的函数
    setWindowTitle(tr("Custom Widget"));

    slider_widget = new custon_slider_widget(this); //声明slider控件
    slider_widget->slider_set_widget_resize(24,100);        //控件大小
    slider_widget->slider_set_max_value(22);
    slider_widget->slider_set_min_value(0);
    slider_widget->slider_set_current_value(12);        //默认刻度

    cpu_widget = new custon_cpu_widget(this);   //声明cpu控件
    cpu_widget->cpu_set_widget_level(slider_widget->slider_get_current_value());//层级默认值
    cpu_widget->setGeometry(40,100,80,100);
    slider_widget->setGeometry(130,100,24,100);

    //连接Slider控件信号事件与槽函数
    connect(slider_widget,SIGNAL(valuchanged(int)),this,SLOT(mvaluechanged(int)));

}

Widget::~Widget()
{
    delete ui;
}


//Slider信号事件关联的槽函数
void Widget::mvaluechanged(int value)
{
    cpu_widget->cpu_set_widget_level(value);
}

void Widget::update_background()  //改变窗口样式
{
    m_device = QPixmap(":resources/Linux.jpg","jpg");
    QBitmap bitmap = m_device.createHeuristicMask();
    setFixedSize(m_device.size());  //用于变换为绝对坐标系的函数
    setMask(bitmap);
    update();
}
void Widget::paintEvent(QPaintEvent *event)
{

}
