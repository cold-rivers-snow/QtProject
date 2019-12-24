#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QString>
#include <QKeySequence>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createActions();
    void createMenus();
    void loadFile(const QString &fileName);

    QMenu *fileMenu;
    QAction *openAct;
    QHBoxLayout *layout;
    QPlainTextEdit *textEdit;
    QString fileName;

private slots:
    void open();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
