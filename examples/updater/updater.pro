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

unix {
zip.commands = cd $$PWD && pwd && rm -f updater.zip && zip updater.zip updater libxbupdater.so libxbapplication.so && unzip -l updater.zip
copylib1.commands = cp -L $$PWD/../../lib/libxbupdater.so $$PWD/libxbupdater.so
copylib2.commands = cp -L $$PWD/../../third-party/xbapplication/lib/libxbapplication.so $$PWD/libxbapplication.so
zip.depends = copylib1 copylib2
QMAKE_EXTRA_TARGETS += copylib1 copylib2 zip
QMAKE_POST_LINK += copylib1 copylib2 zip
}

win32 {
clean.commands = $$quote($(DEL_FILE) $$shell_path($$PWD/updater.zip) 2>nul)
zip.commands = cd $$shell_path($$PWD) && tar.exe -a -c -f updater.zip updater.exe *.dll plugins/platforms/*.dll
copylib1.commands = $$quote($(COPY_FILE) $$shell_path($$PWD/../../lib/xbupdater.dll) $$shell_path($$PWD/xbupdater.dll))
copylib2.commands = $$quote($(COPY_FILE) $$shell_path($$PWD/../../third-party/xbapplication/lib/xbapplication.dll) $$shell_path($$PWD/xbapplication.dll))
QMAKE_POST_LINK += $$clean.commands && $$copylib1.commands && $$copylib2.commands && $$zip.commands
}
