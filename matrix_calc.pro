#-------------------------------------------------
#
# Project created by QtCreator 2018-03-13T17:59:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = matrix_calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    array.cpp \
    writer.cpp

RC_FILE     = resources.rc

HEADERS  += mainwindow.h \
    array.h \
    writer.h

FORMS    += mainwindow.ui

RESOURCES +=
