#include "catch.hpp"
#include <QMainWindow>

#include "../../application/pogodista.h"
#include "../../application/pogodistaui.h"
#include "ui_pogodistaui.h"

TEST_CASE ("PogodiStaUI Constructor", "[PogodiStaUI]")
{
  auto m = std::make_unique<QMainWindow> ();
  auto socket = std::make_unique<QTcpSocket> (m.get ());
  auto pogodista = std::make_unique<PogodiStaUI> (
	  m.get (), socket.get (), "Player1", "Player2", true, 0, 0, 0);

  SECTION ("Constructor Initialization")
  {

	REQUIRE (pogodista->getPlayer1 () == "Player1");
	REQUIRE (pogodista->getPlayer2 () == "Player2");
	REQUIRE (pogodista->getPlayer1Points () == 0);
	REQUIRE (pogodista->getPlayer2Points () == 0);
  }

  SECTION ("UI is properly initialized")
  {
	REQUIRE (pogodista->getUi () != nullptr);
  }
}

TEST_CASE ("PogodiStaUI startGame Method", "[PogodiStaUI]")
{
  auto m = std::make_unique<QMainWindow> ();
  auto socket = std::make_unique<QTcpSocket> (m.get ());
  auto pogodista = std::make_unique<PogodiStaUI> (
	  m.get (), socket.get (), "Player1", "Player2", true, 0, 0, 0);

  SECTION ("Time is set correctly") { REQUIRE (pogodista->getTime () == 60); }

  SECTION ("Initial values are set correctly")
  {

	REQUIRE (pogodista->getRoundNumber () == 6);
	REQUIRE (pogodista->getPixelSize () == 32);
  }
}

TEST_CASE ("PogodiSta getAnswer Method", "[PogodiSta]")
{
  auto pogodista = std::make_unique<PogodiSta> (0, "info", "answer");

  REQUIRE (pogodista->getAnswer () == "answer");
}

TEST_CASE ("PogodiSta getInfo Method", "[PogodiSta]")
{
  auto pogodista = std::make_unique<PogodiSta> (0, "info", "answer");

  REQUIRE (pogodista->getInfo () == "info");
}

TEST_CASE ("PogodiSta calculatePoints Method", "[PogodiSta]")
{
  auto pogodista = std::make_unique<PogodiSta> (0, "info", "answer");

  SECTION ("Funkcije")
  {
	int roundNumber = 5;
	int points = pogodista->calculatePoints (roundNumber);
	REQUIRE (points == 25);
  }
}
