#ifndef CUSTOM_CPU_WIDGET_H
#define CUSTOM_CPU_WIDGET_H

#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT custom_cpu_widget : public QWidget
{
    Q_OBJECT

public:
    custom_cpu_widget(QWidget *parent = 0); //cpu控件类的构造函数
    void cpu_set_widget_level(int level);   //设置CPU使用层级

};

#endif // CUSTOM_CPU_WIDGET_H
