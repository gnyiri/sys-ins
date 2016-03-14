QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sys-ins
TEMPLATE = lib

SOURCES += main_window.cpp \
           sys_utils.cpp \
           proc_parser.cpp \
           glgraphview.cpp \
    time_series.cpp

HEADERS  += main_window.h \
            sys_utils.h \
            proc_parser.h \
            utils.h \
            glgraphview.h \
    time_series.h

FORMS    += ../ui/main_window.ui
