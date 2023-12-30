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
}



