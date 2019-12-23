#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H

#include <QObject>

namespace Ui {
class SignalSlot;
}

class SignalSlot : public QObject
{
    Q_OBJECT

public:
    explicit SignalSlot();
    ~SignalSlot();
    int value()const;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    Ui::SignalSlot *ui;
    int m_value;
};

#endif // SIGNALSLOT_H
