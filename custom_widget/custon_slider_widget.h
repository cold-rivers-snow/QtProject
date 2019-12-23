#ifndef CUSTON_SLIDER_WIDGET_H
#define CUSTON_SLIDER_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>

class custon_slider_widget : public QWidget
{
    Q_OBJECT

public:
    explicit custon_slider_widget(QWidget *parent = nullptr);

    void slider_set_widget_resize(int width,int height);
    void slider_set_max_value(float value);
    void slider_set_min_value(float value);
    void slider_set_current_value(float value);

    int slider_get_current_value();

signals:
    void valuchanged(int value);
private:

    int w_width;
    int w_height;
    float max_value;
    float min_value;
    float current_value;

    float slider_ypos;
    float slider_width,slider_height;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // CUSTON_SLIDER_WIDGET_H
