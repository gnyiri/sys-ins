include(../defaults.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = sys-ins

INCLUDEPATH = ../src

SOURCES += main.cpp

LIBS += -L../src -lsys-ins
