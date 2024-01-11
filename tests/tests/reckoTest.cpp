#include "catch.hpp"
#include <QMainWindow>

#include "../../application/recko.h"
#include "../../application/reckoui.h"
#include "ui_reckoui.h"

TEST_CASE ("Recko Constructor", "[Recko]")
{
  auto m = std::make_unique<QMainWindow> ();
  auto socket = std::make_unique<QTcpSocket> (m.get ());
  auto recko = std::make_unique<ReckoUI> (m.get (), socket.get (), "Player1",
										  "Player2", true, 0, 0);

  SECTION ("Constructor Initialization")
  {

	REQUIRE (recko->getPlayer1 () == "Player1");
	REQUIRE (recko->getPlayer2 () == "Player2");
	REQUIRE (recko->getPlayer1Points () == 0);
	REQUIRE (recko->getPlayer2Points () == 0);
  }

  SECTION ("Time is set correctly")
  {

	REQUIRE (recko->getTime () == 60);
	REQUIRE (recko->getUi ()->lbTimer->text () == QString::number (60));
  }

  SECTION ("UI is properly initialized")
  {
	REQUIRE (recko->getUi () != nullptr);
  }
}

TEST_CASE ("Row Functionality")
{

  auto recko = std::make_unique<Recko> ();

  recko->setCurrentRow (2);
  REQUIRE (recko->getCurrentRow () == 2);

  recko->incrementRow ();
  REQUIRE (recko->getCurrentRow () == 3);
}

TEST_CASE ("Wordle check")
{

  auto recko = std::make_unique<Recko> ();
  recko->newWordle ();

  QString selectedWord = recko->wordle;
  auto words = recko->getQuizWords ();

  SECTION ("Wordle should be in quizWords")
  {
	REQUIRE (std::find (words.begin (), words.end (), selectedWord)
			 != words.end ());
  }
}
