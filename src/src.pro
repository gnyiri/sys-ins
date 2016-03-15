QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sys-ins
TEMPLATE = lib

SOURCES += main_window.cpp \
           sys_utils.cpp \
           proc_parser.cpp \
           glgraphview.cpp \
    time_series.cpp \
    time_series_renderer.cpp

HEADERS  += main_window.h \
            sys_utils.h \
            proc_parser.h \
            utils.h \
            glgraphview.h \
    time_series.h \
    time_series_renderer.h

FORMS    += ../ui/main_window.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    fragment_shader.frag
