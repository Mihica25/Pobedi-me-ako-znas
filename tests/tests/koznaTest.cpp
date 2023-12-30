#include "catch.hpp"
#include <QMainWindow>

#include "../../application/koznaui.h"
#include "../../application/ui_kozna.h"



TEST_CASE("KoZnaui Constructor") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    KoZnaui *kozna = new KoZnaui(m, socket, "Player1", "Player2", true, 0, 0);

    SECTION("Constructor Initialization") {

        REQUIRE(kozna->getPlayer1() == "Player1");
        REQUIRE(kozna->getPlayer2() == "Player2");
        REQUIRE(kozna->getPlayer1Points() == 0);
        REQUIRE(kozna->getPlayer2Points() == 0);
    }

    SECTION("Time is set correctly") {

        REQUIRE(kozna->getTime() == 45);
    }
    delete kozna;
    delete socket;
    delete m;
}


TEST_CASE("Button_KoZna Enabling") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    KoZnaui *kozna = new KoZnaui(m, socket, "Player1", "Player2", true, 0, 0);

    kozna->enableUi();

    // Check if the button is enabled
    REQUIRE(kozna->getUI()->pushButtonAns1->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns2->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns3->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns4->isEnabled() == true);

    delete kozna;
    delete socket;
    delete m;
}


TEST_CASE("Button_KoZna Disabling") {
    QMainWindow *m = new QMainWindow();
    QTcpSocket *socket = new QTcpSocket(m);
    KoZnaui *kozna = new KoZnaui(m, socket, "Player1", "Player2", true, 0, 0);

    kozna->disableUi();

    // Check if the button is disabled
    REQUIRE(kozna->getUI()->pushButtonAns1->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns2->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns3->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns4->isEnabled() == false);

    delete kozna;
    delete socket;
    delete m;
}




