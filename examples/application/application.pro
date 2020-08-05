QT             += core gui widgets network
CONFIG         += c++17 console
DESTDIR         = $$PWD

SOURCES += \
    exampleupdatableapplication.cpp \
    main.cpp

INCLUDEPATH += $$PWD/../../third-party/xbapplication/include
LIBS += -L$$PWD/../../third-party/xbapplication/lib -lxbapplication

HEADERS += \
    exampleupdatableapplication.h

copydata.commands = $(COPY_DIR) $$PWD/application $$PWD/application2
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
