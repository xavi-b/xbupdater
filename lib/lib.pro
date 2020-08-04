TEMPLATE        = lib
CONFIG         += c++17
DEFINES        += QT_DEPRECATED_WARNINGS
QT             += widgets network
TARGET          = xbupdater
DESTDIR         = $$PWD

LIBS += -L$$PWD/../third-party/xbapplication/lib -lxbapplication
INCLUDEPATH += $$PWD/../third-party/xbapplication/include

SUBDIRS += \
    $$PWD/../include \
    $$PWD/../src

include($$PWD/../include/include.pri)
include($$PWD/../src/src.pri)


