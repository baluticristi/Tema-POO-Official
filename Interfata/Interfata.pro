QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -lws2_32
SOURCES += \
    addloc.cpp \
    addobiective.cpp \
    addtrans.cpp \
    adminmeniu.cpp \
    client.cpp \
    clientconnection.cpp \
    clientmenu.cpp \
    delob.cpp \
    dobiective.cpp \
    dtrans.cpp \
    istoricclient.cpp \
    listalocatii.cpp \
    listatransport.cpp \
    locatiemenu.cpp \
    main.cpp \
    oblictiveturistice.cpp \
    sign_in.cpp \
    windowsinstances.cpp

HEADERS += \
    addloc.h \
    addobiective.h \
    addtrans.h \
    adminmeniu.h \
    client.h \
    clientconnection.h \
    clientmenu.h \
    delob.h \
    dobiective.h \
    dtrans.h \
    istoricclient.h \
    listalocatii.h \
    listatransport.h \
    locatiemenu.h \
    oblictiveturistice.h \
    sign_in.h \
    windowsinstances.h

FORMS += \
    addloc.ui \
    addobiective.ui \
    addtrans.ui \
    adminmeniu.ui \
    client.ui \
    clientmenu.ui \
    delob.ui \
    dobiective.ui \
    dtrans.ui \
    istoricclient.ui \
    listalocatii.ui \
    listatransport.ui \
    locatiemenu.ui \
    oblictiveturistice.ui \
    sign_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/background.jpg \
    img/welcome.jpg \
    img/welcome.png
