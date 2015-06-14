#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T23:46:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtZooClient
TEMPLATE = app


SOURCES += main.cpp\
        qtzooclient.cpp \
    menubar.cpp \
    zootabs.cpp \
    zoodialog.cpp

HEADERS  += qtzooclient.h \
    menubar.h \
    zootabs.h \
    zoodialog.h

FORMS    += qtzooclient.ui \
    menubar.ui \
    zootabs.ui \
    zoodialog.ui
