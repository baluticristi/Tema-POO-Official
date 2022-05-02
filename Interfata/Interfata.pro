QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -lws2_32
SOURCES += \
    adminmeniu.cpp \
    client.cpp \
    clientconnection.cpp \
    loginadmin.cpp \
    main.cpp \
    mainwindow.cpp \
    sign_in.cpp \
    windowsinstances.cpp

HEADERS += \
    adminmeniu.h \
    client.h \
    clientconnection.h \
    loginadmin.h \
    mainwindow.h \
    sign_in.h \
    windowsinstances.h

FORMS += \
    adminmeniu.ui \
    client.ui \
    loginadmin.ui \
    mainwindow.ui \
    sign_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/background.jpg \
    img/welcome.jpg \
    img/welcome.png
