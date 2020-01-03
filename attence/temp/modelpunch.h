#ifndef MODELPUNCH_H
#define MODELPUNCH_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>



class ModelPunch : public QWidget
{
    Q_OBJECT

public:
    explicit ModelPunch(QWidget *parent = nullptr);
    ~ModelPunch();

private:
    QLabel *usr_idl,*usr_punchl,*usr_datel;
    QLineEdit *usr_ide,*usr_punche,*usr_datee;
    QPushButton *ok;
};

#endif // MODELPUNCH_H
