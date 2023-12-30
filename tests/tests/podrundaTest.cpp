#include "catch.hpp"
#include <QMainWindow>
//#include <QtTest/QtTest>

#include "../../application/podrunda.h"
#include "../../application/podrundaui.h"
#include "../../application/ui_podrundaui.h"


TEST_CASE("Podrundaui Constructor", "[Podrundaui]") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    Podrundaui *podrundaui = new Podrundaui(m, socket, "Player1", "Player2", 0, 0);

    SECTION("Constructor Initialization") {

        REQUIRE(podrundaui->getPlayer1() == "Player1");
        REQUIRE(podrundaui->getPlayer2() == "Player2");
        REQUIRE(podrundaui->getPlayer1Points() == 0);
        REQUIRE(podrundaui->getPlayer2Points() == 0);
    }

    SECTION("Time is set correctly") {

        REQUIRE(podrundaui->getTime() == 20);
        REQUIRE(podrundaui->getUi()->labTimer->text() == QString::number(20));
    }

    SECTION("UI is properly initialized") {
        REQUIRE(podrundaui->getUi() != nullptr);
    }

    delete m;
    delete socket;
    delete podrundaui;
}


TEST_CASE("Gameplay Mechanics") {
    //QWidget parent;
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    Podrundaui *podrundaui = new Podrundaui(m, socket, "Player1", "Player2", 0, 0);

    SECTION("Player Points Update") {

        podrundaui->setPlayer1Points(10);
        REQUIRE(podrundaui->getPlayer1Points() == 10);
        podrundaui->setPlayer2Points(20);
        REQUIRE(podrundaui->getPlayer2Points() == 20);
    }

    SECTION("Reset Game Functionality") {

        podrundaui->resetGame();
        REQUIRE(podrundaui->getUi()->labTimer->text().isEmpty());
        REQUIRE(podrundaui->getUi()->labTacanOdgovor->text().isEmpty());
    }

    delete m;
    delete socket;
    delete podrundaui;
}


TEST_CASE("Button_Podrunda Enabling") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    Podrundaui *podrunda = new Podrundaui(m, socket, "Player1", "Player2", 0, 0);

    podrunda->enableUI();

    // Check if the button is enabled
    REQUIRE(podrunda->getUi()->pbOdgovori->isEnabled() == true);
    REQUIRE(podrunda->getUi()->teOdgovor->isEnabled() == true);

    delete m;
    delete socket;
    delete podrunda;
}


TEST_CASE("Button_Podrunda Disabling") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    Podrundaui *podrunda = new Podrundaui(m, socket, "Player1", "Player2", 0, 0);

    podrunda->disableUI();

    // Check if the button is disabled
    REQUIRE(podrunda->getUi()->pbOdgovori->isEnabled() == false);
    REQUIRE(podrunda->getUi()->teOdgovor->isEnabled() == false);

    delete m;
    delete socket;
    delete podrunda;
}
