TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = \
    src \
    app \
    test

app.depends = src
test.depends = src

OTHER_FILES += \
    defaults.pri
