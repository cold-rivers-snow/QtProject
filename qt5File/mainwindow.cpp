#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."),this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct,SIGNAL(triggered()),this,SLOT(open()));
}
void MainWindow::createMenus()
{

}
void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Application"),tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    textEdit->setPlainText(in.readAll());
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
        loadFile(fileName);
}
