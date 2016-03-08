QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sys-ins
TEMPLATE = lib

SOURCES += main_window.cpp \
           sys_utils.cpp \
    proc_parser.cpp

HEADERS  += main_window.h \
            sys_utils.h \
    proc_parser.h \
    utils.h

FORMS    += ../ui/main_window.ui
