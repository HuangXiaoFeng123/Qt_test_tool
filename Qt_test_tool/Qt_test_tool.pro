QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    control_electricity.cpp \
    main.cpp \
    toolwidget.cpp

HEADERS += \
    control_electricity.h \
    toolwidget.h

FORMS += \
    control_electricity.ui \
    toolwidget.ui

DEFINES += WINIO_DLL
    unix|win32: LIBS += -L$$PWD/./ -lWinIo64

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \

RC_ICONS = exe_ico.ico
