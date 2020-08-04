QT             += core gui widgets network
CONFIG         += c++17
DESTDIR         = $$PWD

SOURCES += \
    exampleupdater.cpp \
    main.cpp

INCLUDEPATH += $$PWD/../../include
LIBS += -L$$PWD/../../lib -lxbupdater

INCLUDEPATH += $$PWD/../../third-party/xbapplication/include
LIBS += -L$$PWD/../../third-party/xbapplication/lib -lxbapplication

HEADERS += \
    exampleupdater.h
