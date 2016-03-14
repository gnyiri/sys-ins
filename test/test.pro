#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T10:37:58
#
#-------------------------------------------------

QT       += testlib core

QT       -= gui

TARGET = unit_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = ../src
LIBS += -L../src -lsys-ins

SOURCES += \
    unit_test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS +=
