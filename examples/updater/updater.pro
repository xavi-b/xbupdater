QT             += core gui widgets network
CONFIG         += c++17 console
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

zip.commands = cd $$PWD && pwd && rm -f updater.zip && zip updater.zip updater libxbupdater.so libxbapplication.so && unzip -l updater.zip
copylib1.commands = cp -L $$PWD/../../lib/libxbupdater.so $$PWD/libxbupdater.so
copylib2.commands = cp -L $$PWD/../../third-party/xbapplication/lib/libxbapplication.so $$PWD/libxbapplication.so
zip.depends = $(first) copylib1 copylib2
first.depends = $(first) zip
export(first.depends)
export(copylib1.commands)
export(copylib2.commands)
export(zip.commands)
QMAKE_EXTRA_TARGETS += first copylib1 copylib2 zip
