
#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
class MainForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);

signals:

public slots:
private:
    QLabel *tipLbl;  //"欢迎登录"标签
    QPushButton *pb;
};

#endif // MAINFORM_H

