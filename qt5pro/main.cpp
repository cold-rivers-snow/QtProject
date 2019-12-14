#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //qt实战：
    //F1详细API
    //Qt主要IDE：工具Qt Creator、帮助文件Qt Assistant和GUI设计工具Qt Designer、将源代码编译为二进制文件qmake。
    //创建新项目：Ctrl+N
    //基类：QMainWindow 、QDialog、QWidget。
    //F5调试
    //Shift+F5 停止调试
    //F10 以行为单位运行全部代码
    //F11 以函数为单位运行代码窗口
    //Shift+F6 跳过执行函数
    //F2向头文件移动
    //Shift+F2向成员函数或成员变量移动
    //F4 在cpp文件和h文件中切换
    //qmake自动生成Makefile 文件
    //qmake -project
    //qmake -o Makefile address.pro
    //vs中：qmake -tp vc address.pro


    return a.exec();
}
