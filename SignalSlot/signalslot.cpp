#include "signalslot.h"
#include "ui_signalslot.h"

SignalSlot::SignalSlot()
{
    m_value = 0;
}

SignalSlot::~SignalSlot()
{
    delete ui;
}

int SignalSlot::value()const
{
    return m_value;
}

void SignalSlot::setValue(int value)
{
    m_value = value;
    emit valueChanged(m_value);
}
