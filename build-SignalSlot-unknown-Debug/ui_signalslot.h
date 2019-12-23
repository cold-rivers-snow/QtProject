/********************************************************************************
** Form generated from reading UI file 'signalslot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALSLOT_H
#define UI_SIGNALSLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalSlot
{
public:

    void setupUi(QWidget *SignalSlot)
    {
        if (SignalSlot->objectName().isEmpty())
            SignalSlot->setObjectName(QStringLiteral("SignalSlot"));
        SignalSlot->resize(400, 300);

        retranslateUi(SignalSlot);

        QMetaObject::connectSlotsByName(SignalSlot);
    } // setupUi

    void retranslateUi(QWidget *SignalSlot)
    {
        SignalSlot->setWindowTitle(QApplication::translate("SignalSlot", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignalSlot: public Ui_SignalSlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALSLOT_H
