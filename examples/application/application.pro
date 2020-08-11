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

unix {
copydata.commands = cp -r $$PWD/application $$PWD/application2
QMAKE_POST_LINK += $$copydata.commands
}

win32 {
copydata.commands = $$quote($(COPY_FILE) $$shell_path($$PWD/application.exe) $$shell_path($$PWD/application2.exe))
copylib1.commands = $$quote($(COPY_FILE) $$shell_path($$PWD/../../lib/xbupdater.dll) $$shell_path($$PWD/xbupdater.dll))
copylib2.commands = $$quote($(COPY_FILE) $$shell_path($$PWD/../../third-party/xbapplication/lib/xbapplication.dll) $$shell_path($$PWD/xbapplication.dll))
QMAKE_POST_LINK += $$copydata.commands && $$copylib1.commands && $$copylib2.commands
}
