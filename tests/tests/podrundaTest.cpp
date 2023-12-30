#include "catch.hpp"
#include <QMainWindow>
//#include <QtTest/QtTest>

#include "../../application/podrunda.h"
#include "../../application/podrundaui.h"
#include "ui_podrundaui.h"


TEST_CASE("Podrundaui Constructor", "[Podrundaui]") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto podrundaui = std::make_unique<Podrundaui>(m.get(), socket.get(), "Player1", "Player2", 0, 0);

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
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto podrundaui = std::make_unique<Podrundaui>(m.get(), socket.get(), "Player1", "Player2", 0, 0);

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


TEST_CASE("Button_Podrunda Enabling") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto podrunda = std::make_unique<Podrundaui>(m.get(), socket.get(), "Player1", "Player2", 0, 0);

    podrunda->enableUI();

    // Check if the button is enabled
    REQUIRE(podrunda->getUi()->pbOdgovori->isEnabled() == true);
    REQUIRE(podrunda->getUi()->teOdgovor->isEnabled() == true);

}


TEST_CASE("Button_Podrunda Disabling") {
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto podrunda = std::make_unique<Podrundaui>(m.get(), socket.get(), "Player1", "Player2", 0, 0);

    podrunda->disableUI();

    // Check if the button is disabled
    REQUIRE(podrunda->getUi()->pbOdgovori->isEnabled() == false);
    REQUIRE(podrunda->getUi()->teOdgovor->isEnabled() == false);
}
