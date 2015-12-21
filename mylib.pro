#-------------------------------------------------
#
# Project created by QtCreator 2014-07-27T13:30:46
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT  += serialport
TARGET = mylib
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    button.h \
    room.h \
    shujia.h \
    books.h \
    backg.h


RESOURCES += \
    images.qrc
FORMS    += mainwindow.ui

OTHER_FILES +=
