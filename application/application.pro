#-------------------------------------------------
#
# Project created by QtCreator 2023-11-25T12:00:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = application
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


SOURCES += \
    cardwidget.cpp \
    game.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    kozna.cpp \
    koznaui.cpp \
    memorija.cpp \
    mojbroj.cpp \
    mojbrojlogic.cpp \
    podrundaui.cpp \
    pocetniekran.cpp \
    recko.cpp \
    reckoui.cpp \
    podrunda.cpp \
    pogodista.cpp \
    pogodistaui.cpp \
    infolog.cpp \
    resultdialog.cpp





HEADERS += \
    cardwidget.h \
    game.h \
    kozna.h \
    koznaui.h \
    logindialog.h \
    mainwindow.h \
    memorija.h \
    mojbroj.h \
    mojbrojlogic.h\
    podrundaui.h \
    pocetniekran.h \
    recko.h \
    reckoui.h \
    podrunda.h \
    pogodista.h \
    pogodistaui.h \
    infolog.h \
    resultdialog.h


FORMS += \
    logindialog.ui \
    mainwindow.ui \
    pogodistaui.ui \
    memorija.ui \
    reckoui.ui \
    kozna.ui \
    mojbroj.ui \
    podrundaui.ui \
    pocetniekran.ui \
    infolog.ui \
    resultdialog.ui

RESOURCES += resources.qrc
