#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T23:46:48
#
#-------------------------------------------------

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtZooClient
TEMPLATE = app


SOURCES += main.cpp\
        qtzooclient.cpp \
    zootabs.cpp \
    zoodialog.cpp \
    zootelnetwidget.cpp \
    zoocommandbutton.cpp

HEADERS  += qtzooclient.h \
    zootabs.h \
    zoodialog.h \
    zootelnetwidget.h \
    zoocommandbutton.h

FORMS    += qtzooclient.ui \
    zootabs.ui \
    zoodialog.ui \
    zootelnetwidget.ui
