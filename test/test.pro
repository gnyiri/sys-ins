#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T10:37:58
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_sys_utils_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = ../src
LIBS += -L../src -lsys-ins

SOURCES += tst_sys_utils_test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
