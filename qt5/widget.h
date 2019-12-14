#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSizeGrip>    //改变父窗口大小
#include <QVBoxLayout>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};

class SubWindow : public QWidget
{
    Q_OBJECT
public:
    SubWindow(QWidget *parent = 0) : QWidget(parent,Qt::SubWindow)
    {
        QSizeGrip *sizegrip = new QSizeGrip(this);
        sizegrip->setFixedSize(sizegrip->sizeHint());

        this->setLayout(new QVBoxLayout);//声明SubWindow的布局
        this->layout()->setMargin(0);//设置空白
        layout()->addWidget(new QTextEdit);

        sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
        sizegrip->raise();

    }

    QSize sizeHint() const
    {
        return QSize(200,100);
    }
};

#endif // WIDGET_H
