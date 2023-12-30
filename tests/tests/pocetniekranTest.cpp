#include "catch.hpp"
#include <QMainWindow>

#include "../../application/pocetniekran.h"
#include "../../application/ui_pocetniekran.h"

TEST_CASE("PocetniEkran Constructor", "[PocetniEkran]") {

    PocetniEkran *pocetniekran = new PocetniEkran();

    SECTION("Constructor Initialization") {

        REQUIRE(pocetniekran->getPlayer1Points() == 0);
        REQUIRE(pocetniekran->getPlayer2Points() == 0);
    }

    SECTION("UI is properly initialized") {
        REQUIRE(pocetniekran->getUi() != nullptr);
    }

}
