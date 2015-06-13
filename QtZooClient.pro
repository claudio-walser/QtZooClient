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
    settingsdialog.cpp \
    menubar.cpp \
    form.cpp

HEADERS  += qtzooclient.h \
    settingsdialog.h \
    menubar.h \
    form.h

FORMS    += qtzooclient.ui \
    settingsdialog.ui \
    menubar.ui \
    form.ui
