TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = \
    src \
    app

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
