#include "catch.hpp"
#include <QMainWindow>

#include "../../application/koznaui.h"
#include "ui_kozna.h"



TEST_CASE("KoZnaui Constructor") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto kozna = std::make_unique<KoZnaui>(m.get(), socket.get(), "Player1", "Player2", true, 0, 0);

    SECTION("Constructor Initialization") {

        REQUIRE(kozna->getPlayer1() == "Player1");
        REQUIRE(kozna->getPlayer2() == "Player2");
        REQUIRE(kozna->getPlayer1Points() == 0);
        REQUIRE(kozna->getPlayer2Points() == 0);
    }

    SECTION("Time is set correctly") {

        REQUIRE(kozna->getTime() == 45);
    }
}


TEST_CASE("Button_KoZna Enabling") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto kozna = std::make_unique<KoZnaui>(m.get(), socket.get(), "Player1", "Player2", true, 0, 0);

    kozna->enableUi();

    REQUIRE(kozna->getUI()->pushButtonAns1->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns2->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns3->isEnabled() == true);
    REQUIRE(kozna->getUI()->pushButtonAns4->isEnabled() == true);

}


TEST_CASE("Button_KoZna Disabling") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto kozna = std::make_unique<KoZnaui>(m.get(), socket.get(), "Player1", "Player2", true, 0, 0);

    kozna->disableUi();

    REQUIRE(kozna->getUI()->pushButtonAns1->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns2->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns3->isEnabled() == false);
    REQUIRE(kozna->getUI()->pushButtonAns4->isEnabled() == false);

}





