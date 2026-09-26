QT += core gui qml quick quickcontrols2 multimedia concurrent
# QtDBus and the freedesktop portal are Linux-only. macOS uses native panels.
macx {
    QT += widgets
    # libwebp comes from Homebrew; the prefix differs by architecture.
    exists(/opt/homebrew/include/webp/demux.h): INCLUDEPATH += /opt/homebrew/include
    exists(/usr/local/include/webp/demux.h): INCLUDEPATH += /usr/local/include
    exists(/opt/homebrew/lib/libwebp.dylib): LIBS += -L/opt/homebrew/lib
    exists(/usr/local/lib/libwebp.dylib): LIBS += -L/usr/local/lib
}
# Like Qt's own modules, Hype never throws or catches. Without unwinding tables and with
# link-time optimization, the installed binary is about a quarter smaller.
CONFIG += c++17 release ltcg exceptions_off
TARGET = hype
TEMPLATE = app
HEADERS += src/deck.h src/renderer.h
SOURCES += src/main.cpp src/deck.cpp src/renderer.cpp
RESOURCES += src/resources.qrc

SOURCES += src/syntax.cpp
HEADERS += src/syntax.h
SOURCES += src/pptx.cpp
HEADERS += src/pptx.h
LIBS += -lz -lwebpdemux -lwebp

SOURCES += src/animationexport.cpp
HEADERS += src/animationexport.h

SOURCES += src/apptheme.cpp
HEADERS += src/apptheme.h
SOURCES += src/images.cpp
HEADERS += src/images.h
SOURCES += src/filedialog.cpp
HEADERS += src/filedialog.h
SOURCES += src/recovery.cpp
SOURCES += src/cli.cpp
HEADERS += src/cli.h
