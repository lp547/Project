#-------------------------------------------------
#
# Project created by QtCreator 2024-04-18T20:22:02
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFilp
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    startscene.cpp \
    mypushbutton.cpp \
    selectscene.cpp \
    playscene.cpp \
    coinbutton.cpp \
    dataconfig.cpp

HEADERS  += mymainwindow.h \
    startscene.h \
    mypushbutton.h \
    selectscene.h \
    playscene.h \
    coinbutton.h \
    dataconfig.h

FORMS    += mymainwindow.ui

RESOURCES += \
    res.qrc
