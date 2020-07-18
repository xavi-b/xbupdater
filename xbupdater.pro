TEMPLATE        = app
CONFIG         += c++17
DEFINES        += QT_DEPRECATED_WARNINGS
QT             += widgets network
TARGET          = xbupdater
DESTIR          = $$PWD

LIBS += -L$$PWD/third-party/xbapplication/lib -lxbapplication
INCLUDEPATH += $$PWD/third-party/xbapplication/include

SUBDIRS += \
    src/

include(src/src.pri)
