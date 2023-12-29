#QT -= gui

#CONFIG += c++11 console
#CONFIG -= app_bundle

TEMPLATE = app
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20



SOURCES += \
        koznaTest.cpp \
        main.cpp \
        ../../application/cardwidget.cpp \
        ../../application/game.cpp \
        ../../application/kozna.cpp \
        ../../application/koznaui.cpp \
        ../../application/logindialog.cpp \
        ../../application/mainwindow.cpp \
        ../../application/memorija.cpp \
        ../../application/mojbroj.cpp \
        ../../application/mojbrojlogic.cpp \
        ../../application/pocetniekran.cpp \
        ../../application/podrunda.cpp \
        ../../application/podrundaui.cpp \
        ../../application/pogodista.cpp \
        ../../application/pogodistaui.cpp \
        ../../application/recko.cpp \
        ../../application/reckoui.cpp \
        ../../server/server/lobby.cpp \
        ../../server/server/player.cpp \
        ../../server/server/server.cpp \
        ../../server/server/session.cpp \
        memorijaTest.cpp \
        mojbrojTest.cpp \
        pocetniekranTest.cpp \
        podrundaTest.cpp \
        pogodistaTest.cpp \
        reckoTest.cpp \
        serverTest.cpp



HEADERS += \
        catch.hpp \
        ../../application/cardwidget.h \
        ../../application/game.h \
        ../../application/kozna.h \
        ../../application/koznaui.h \
        ../../application/logindialog.h \
        ../../application/mainwindow.h \
        ../../application/memorija.h \
        ../../application/mojbroj.h \
        ../../application/mojbrojlogic.h \
        ../../application/pocetniekran.h \
        ../../application/podrunda.h \
        ../../application/podrundaui.h \
        ../../application/pogodista.h \
        ../../application/pogodistaui.h \
        ../../application/recko.h \
        ../../application/reckoui.h \
        ../../server/server/lobby.h \
        ../../server/server/mainwindow.h \
        ../../server/server/player.h \
        ../../server/server/server.h \
        ../../server/server/session.h



FORMS += \
      ../../application/kozna.ui \
      ../../application/logindialog.ui \
      ../../application/mainwindow.ui \
      ../../application/memorija.ui \
      ../../application/mojbroj.ui \
      ../../application/pocetniekran.ui \
      ../../application/podrundaui.ui \
      ../../application/pogodistaui.ui \
      ../../application/reckoui.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
