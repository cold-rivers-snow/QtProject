#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QComboBox>
#include <QCommandLinkButton>
#include <QDate>
#include <QDateEdit>
#include <QLabel>
#include <QTime>
#include <QtWidgets/QTimeEdit>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDial>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFocusFrame>
#include <QFontComboBox>
#include <QLCDNumber>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>
#include <QProgressBar>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSlider>
#include <QTabWidget>
#include <QToolBar>
#include <QAction>
#include <QTabBar>
#include <QToolBox>
#include <QHBoxLayout>
#include <QToolButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QBoxLayout>
#include <QColumnView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDataWidgetMapper>
#include <QStringListModel>
#include <QDesktopWidget>
#include <QCalendarWidget>
#include <QInputDialog>
#include <QDir>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDockWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QListView>
#include <QTreeView>
#include <QSplitter>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QBitArray>
#include <QBrush>
#include <QPainter>
#include <QByteArray>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void chkChanged();
    void valueChanged();
    void changedData();
    void valuechange();
    void double_valuechange();
    //按钮的3种事件
    void btn_click();
    void btn_pressed();
    void btn_released();
    //字体
    void changedIndex(int idx);
    void changedFont(const QFont &f);
    //文本
    void textchanged(QString str);
    //菜单
    void trigerMenu(QAction* act);
    void on_actionnew_triggered();
    //滚动条
    void valueChanged1(int value);
    void currentTab(int index);

    //图标
    void trigger1();
    void open();
    void newFile();
private:
    Ui::MainWindow *ui;
    QButtonGroup *chk_group[2];
    QCheckBox *exclusive[3],*non_exclusive[3];
    QComboBox *combo;
    QCommandLinkButton *cmmBtn;
    QDateEdit   *dateEdit[4];
    QLabel *lb1[6],*lb;
    QDial *dial[5];
    QSpinBox *spin[3];
    QDoubleSpinBox *doublepin[3];
    QPushButton *btn[6];
    QFocusFrame *btn_frame;
    QFontComboBox *fontcombo[5];
    QLineEdit *edit[5],*edit1;
    QMenu *menu[3];
    QAction *act[2];
    QMenuBar *menubar;
    QStatusBar* status;
    QProgressBar *progress[4];
    QRadioButton *radio1[3],*radio2[3];
    QScrollArea *area;
    QScrollBar *vscrollbar[3],*hscrollbar[3];
    QSlider *slider[2];
    QTabWidget *tab;
    QWidget *browser_tab,*users_tab;
    QTabBar *tabBar;    //图形绘制选项卡
    QToolBox *box;  //特定选项卡
    QHBoxLayout *lay,*hboxLayout;
    QToolButton *button[3];//显示文本控件
    QToolBar *tool;
    QVBoxLayout *vboxlayout;
    QGridLayout *gridLayout;
    QStandardItemModel *model;
    QStandardItem *name,*firstName,*lastName;
    QColumnView *columnView;
    QStringListModel *typeModel;
    QDataWidgetMapper *mapper;
    QCalendarWidget *calendar;
};

#endif // MAINWINDOW_H
