#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("Custom Dialog");

    lb1 = new QLabel("Name");
    edit = new QLineEdit("");

    okbtn = new QPushButton("OK");
    cancelbtn = new QPushButton("CANCEL");

    QHBoxLayout *hlay1 = new QHBoxLayout();
    hlay1->addWidget(lb1);
    hlay1->addWidget(edit);

    QHBoxLayout *hlay2 = new QHBoxLayout();
    hlay2->addWidget(okbtn);
    hlay2->addWidget(cancelbtn);

    QVBoxLayout *vlay = new QVBoxLayout();
    vlay->addLayout(hlay1);
    vlay->addLayout(hlay2);

    setLayout(vlay);
}

Dialog::~Dialog()
{
    delete ui;
}

