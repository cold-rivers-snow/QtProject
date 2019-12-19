#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSizeGrip>    //改变父窗口大小
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPainter>
#include <QtEvents>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);//parent == 0 则是父窗口，否则是子窗口。一般默认为0
    ~Widget();

protected:
    virtual void paintEvent(QPaintEvent *event);//绘制窗口
    virtual void resizeEvent(QResizeEvent *event);//调整窗口大小
    virtual void mousePressEvent(QMouseEvent *event);//按下鼠标
    virtual void mouseReleaseEvent(QMouseEvent *event);//松开鼠标
    virtual void mouseDoubleClickEvent(QMouseEvent *event);//双击鼠标
    virtual void mouseMoveEvent(QMouseEvent *event);//移动鼠标
    virtual void whellEvent(QMouseEvent *event);//鼠标滚动
    virtual void enterEvent(QMouseEvent *event);//鼠标进入窗口
    virtual void leaveEvent(QMouseEvent *event);//鼠标离开窗口
    virtual void closeEvent(QMouseEvent *event);//关闭窗口
    virtual void keyPressEvent(QKeyEvent *event);//键盘按下
    virtual void keyReleaseEvent(QKeyEvent *event);//键盘松开
    virtual void focusInEvent(QFocusEvent *event);//键盘得到焦点
    virtual void focusOutEvent(QFocusEvent *event);//键盘失去焦点

private:
    Ui::Widget *ui;
};

//class SubWindow : public QWidget
//{
//    Q_OBJECT
//public:
//    SubWindow(QWidget *parent = 0) : QWidget(parent,Qt::SubWindow)
//    {
//        QSizeGrip *sizegrip = new QSizeGrip(this);
//        sizegrip->setFixedSize(sizegrip->sizeHint());

//        this->setLayout(new QVBoxLayout);//声明SubWindow的布局
//        this->layout()->setMargin(0);//设置空白
//        layout()->addWidget(new QTextEdit);

//        sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
//        sizegrip->raise();

//    }

//    QSize sizeHint() const
//    {
//        return QSize(200,100);
//    }
//};

#endif // WIDGET_H
