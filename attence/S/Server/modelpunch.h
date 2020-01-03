#ifndef MODELPUNCH_H
#define MODELPUNCH_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class ModelPunch;
}

class ModelPunch : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModelPunch(QWidget *parent = nullptr);
    ~ModelPunch();

    QSize sizeHint() const;
private:
    Ui::ModelPunch *ui;
    QLabel *usr_idl,*usr_punchl,*usr_datel;
    QLineEdit *usr_ide,*usr_punche,*usr_datee;
    QPushButton *ok;
};

#endif // MODELPUNCH_H
