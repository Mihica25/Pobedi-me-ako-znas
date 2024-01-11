#include "catch.hpp"
#include <QMainWindow>

#include "../../application/mojbroj.h"
#include "../../application/mojbrojlogic.h"
#include "ui_mojbroj.h"

TEST_CASE ("MojBrojLogic Initialization", "[MojBrojLogic]")
{
  MojBrojLogic gameLogic;

  SECTION ("Initial Game Phase")
  {
	REQUIRE (gameLogic.getCurrentRound () == GamePhase::Round1);
  }

  SECTION ("Initial Target Number")
  {
	REQUIRE (gameLogic.getTargetNumber () == 0);
  }

  SECTION ("Initial Available Numbers")
  {
	REQUIRE (gameLogic.availableNumbers.isEmpty ());
  }

  SECTION ("Initial Current Expression")
  {
	REQUIRE (gameLogic.currentExpression.isEmpty ());
  }
}

TEST_CASE ("Game Operations", "[MojBrojLogic]")
{
  MojBrojLogic gameLogic;

  SECTION ("Choose Number")
  {
	gameLogic.availableNumbers = { 1, 2, 3, 4 };
	gameLogic.chooseNumber (2);
	REQUIRE (gameLogic.currentExpression.contains ("2"));
	REQUIRE_FALSE (gameLogic.availableNumbers.contains (2));
  }

  SECTION ("Submit Solution")
  {
	gameLogic.setTargetNumber (10);
	gameLogic.currentExpression = { "5", "+", "5" };
	int result = gameLogic.submitSolution ("5+5", "indicator");
	REQUIRE (result == 10);
  }

  SECTION ("End Game")
  {
	bool end = gameLogic.endGame ();
	REQUIRE (end == false);
	REQUIRE (gameLogic.getCurrentRound () == GamePhase::Round2);

	end = gameLogic.endGame ();
	REQUIRE (end == true);
	REQUIRE (gameLogic.getCurrentRound () == GamePhase::End);
  }
}
