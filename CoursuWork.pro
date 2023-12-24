QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h
    libconfig.h++

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../vcpkg/packages/libconfig_x64-windows/release/ -llibconfig++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../vcpkg/packages/libconfig_x64-windows/debug/ -llibconfig++

INCLUDEPATH += $$PWD/../vcpkg/packages/libconfig_x64-windows/include
DEPENDPATH += $$PWD/../vcpkg/packages/libconfig_x64-windows/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../vcpkg/packages/libconfig_x64-windows/release/liblibconfig++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../vcpkg/packages/libconfig_x64-windows/debug/liblibconfig++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../vcpkg/packages/libconfig_x64-windows/release/libconfig++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../vcpkg/packages/libconfig_x64-windows/debug/libconfig++.lib
