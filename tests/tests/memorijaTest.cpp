#include "catch.hpp"
#include <QMainWindow>

#include "../../application/memorija.h"
#include "ui_memorija.h"

TEST_CASE("Memorija Constructor", "[Memorija]")
{
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto memorija = std::make_unique<Memorija>(m.get(), socket.get(), "Player1", "Player2", true, 0, 0);

    SECTION("Constructor Initialization")
    {

        REQUIRE(memorija->getPlayer1() == "Player1");
        REQUIRE(memorija->getPlayer2() == "Player2");
        REQUIRE(memorija->getPlayer1Points() == 0);
        REQUIRE(memorija->getPlayer2Points() == 0);
    }

    SECTION("UI is properly initialized")
    {
        REQUIRE(memorija->getUi() != nullptr);
    }
}

TEST_CASE("BlockWholeWindow Method")
{
    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto memorija = std::make_unique<Memorija>(m.get(), socket.get(), "Player1", "Player2", true, 0, 0);

    memorija->blockWholeWindow(true);

    REQUIRE(memorija->getUi()->widget_1->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_2->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_3->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_4->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_5->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_6->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_7->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_8->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_9->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_10->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_11->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_12->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_13->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_14->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_15->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_16->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_17->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_18->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_19->isEnabled() == false);
    REQUIRE(memorija->getUi()->widget_20->isEnabled() == false);
}
