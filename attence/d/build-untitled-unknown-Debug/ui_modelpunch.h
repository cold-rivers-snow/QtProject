/********************************************************************************
** Form generated from reading UI file 'modelpunch.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELPUNCH_H
#define UI_MODELPUNCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelPunch
{
public:

    void setupUi(QWidget *ModelPunch)
    {
        if (ModelPunch->objectName().isEmpty())
            ModelPunch->setObjectName(QStringLiteral("ModelPunch"));
        ModelPunch->resize(400, 300);

        retranslateUi(ModelPunch);

        QMetaObject::connectSlotsByName(ModelPunch);
    } // setupUi

    void retranslateUi(QWidget *ModelPunch)
    {
        ModelPunch->setWindowTitle(QApplication::translate("ModelPunch", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModelPunch: public Ui_ModelPunch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELPUNCH_H
