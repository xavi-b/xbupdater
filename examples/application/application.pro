QT             += core gui widgets network
CONFIG         += c++17
DESTDIR         = $$PWD

SOURCES += \
    exampleupdatableapplication.cpp \
    main.cpp

INCLUDEPATH += $$PWD/../../third-party/xbapplication/include
LIBS += -L$$PWD/../../third-party/xbapplication/lib -lxbapplication

HEADERS += \
    exampleupdatableapplication.h
