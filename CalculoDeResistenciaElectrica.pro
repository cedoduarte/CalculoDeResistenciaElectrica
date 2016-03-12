#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T14:43:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalculoDeResistenciaElectrica
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DoubleSpinBoxItemDelegate.cpp

HEADERS  += Widget.h \
    DoubleSpinBoxItemDelegate.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
