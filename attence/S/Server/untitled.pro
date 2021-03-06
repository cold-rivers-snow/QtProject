#-------------------------------------------------
#
# Project created by QtCreator 2019-12-05T14:22:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    insertuser.cpp \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    mainfrom.cpp \
    modelPasswd.cpp \
    modelpunch.cpp \
    punch.cpp \
    attencesql.cpp \
    ext.cpp

HEADERS += \
    insertuser.h \
        mainwindow.h \
    mainfrom.h \
    modelPasswd.h \
    modelpunch.h \
    punch.h \
    login.h \
    attencesql.h \
    ext.h

FORMS += \
        mainwindow.ui \
        modelpunch.ui
