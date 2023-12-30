#include "catch.hpp"
#include <QMainWindow>

#include "../../application/pogodista.h"
#include "../../application/pogodistaui.h"
#include "../../application/ui_pogodistaui.h"



TEST_CASE("PogodiStaUI Constructor", "[PogodiStaUI]") {

    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    PogodiStaUI *pogodista = new PogodiStaUI(m, socket, "Player1", "Player2", true, 0, 0, 0);

    SECTION("Constructor Initialization") {

        REQUIRE(pogodista->getPlayer1() == "Player1");
        REQUIRE(pogodista->getPlayer2() == "Player2");
        REQUIRE(pogodista->getPlayer1Points() == 0);
        REQUIRE(pogodista->getPlayer2Points() == 0);
    }

    SECTION("UI is properly initialized") {
        REQUIRE(pogodista->getUi() != nullptr);
    }
}


TEST_CASE("PogodiStaUI startGame Method", "[PogodiStaUI]") {

    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    PogodiStaUI *pogodista = new PogodiStaUI(m, socket, "Player1", "Player2", true, 0, 0, 0);

    SECTION("Time is set correctly") {

        REQUIRE(pogodista->getTime() == 60);
    }

    SECTION("Initial values are set correctly") {

        REQUIRE(pogodista->getRoundNumber() == 6);
        REQUIRE(pogodista->getPixelSize() == 32);
    }

}


TEST_CASE("PogodiSta calculatePoints Method", "[PogodiSta]") {

    PogodiSta *pogodista = new PogodiSta(0, "info", "answer");

    SECTION("Funkcije") {
        int roundNumber = 5;  // Example round number
        int points = pogodista->calculatePoints(roundNumber);
        REQUIRE(points == 25);
    }
}
