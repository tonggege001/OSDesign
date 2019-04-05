#-------------------------------------------------
#
# Project created by QtCreator 2019-03-07T08:56:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileShow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    regularfile.cpp \
    tggdirectory.cpp \
    createdialog.cpp \
    openpanel.cpp

HEADERS += \
        mainwindow.h \
    regularfile.h \
    tggdirectory.h \
    createdialog.h \
    openpanel.h

FORMS += \
        mainwindow.ui \
    regularfile.ui \
    tggdirectory.ui \
    createdialog.ui \
    openpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../syscall/release/ -lsysdirectory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../syscall/debug/ -lsysdirectory
else:unix: LIBS += -L$$PWD/../syscall/ -lsysdirectory

INCLUDEPATH += $$PWD/../syscall
DEPENDPATH += $$PWD/../syscall

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../syscall/release/libsysdirectory.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../syscall/debug/libsysdirectory.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../syscall/release/sysdirectory.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../syscall/debug/sysdirectory.lib
else:unix: PRE_TARGETDEPS += $$PWD/../syscall/libsysdirectory.a
