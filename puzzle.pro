TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sdl_context.cpp \
    texture.cpp \
    puzzle.cpp \
    game.cpp

HEADERS += \
    sdl_context.hpp \
    texture.hpp \
    puzzle.hpp \
    game.hpp

unix|win32: LIBS += -lSDL2
unix|win32: LIBS += -lSDL2_image

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/external/nativefiledialog/build/lib/Release/x64/release/ -lnfd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/external/nativefiledialog/build/lib/Release/x64/debug/ -lnfd
else:unix: LIBS += -L$$PWD/external/nativefiledialog/build/lib/Release/x64/ -lnfd

INCLUDEPATH += $$PWD/external/nativefiledialog/src/include
DEPENDPATH += $$PWD/external/nativefiledialog/src/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/external/nativefiledialog/build/lib/Release/x64/release/libnfd.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/external/nativefiledialog/build/lib/Release/x64/debug/libnfd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/external/nativefiledialog/build/lib/Release/x64/release/nfd.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/external/nativefiledialog/build/lib/Release/x64/debug/nfd.lib
else:unix: PRE_TARGETDEPS += $$PWD/external/nativefiledialog/build/lib/Release/x64/libnfd.a

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gtk+-3.0
