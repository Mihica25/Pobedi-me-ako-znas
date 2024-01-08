#include "catch.hpp"

#include "../../server/server/lobby.h"
#include "../../server/server/mainwindow.h"
#include "../../server/server/player.h"
#include "../../server/server/server.h"
#include "../../server/server/session.h"

TEST_CASE("Session creation and message sending", "[session]")
{

    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto m1 = std::make_unique<QMainWindow>();
    auto socket1 = std::make_unique<QTcpSocket>(m1.get());
    Player *player1 = new Player(socket.get(), "Player1");
    Player *player2 = new Player(socket1.get(), "Player2");
    QStringList words = {"word1", "word2"};
    Session session(player1, player2, words);

    SECTION("Session is created correctly")
    {
        REQUIRE(session.getPlayer1()->getPlayerUsername() == "Player1");
        REQUIRE(session.getPlayer2()->getPlayerUsername() == "Player2");
    }
}

TEST_CASE("Server initialization and connection handling", "[server]")
{
    Server server;

    SECTION("Server starts without errors")
    {
        REQUIRE_NOTHROW(server.startServer(8080));
    }
}

TEST_CASE("Lobby management", "[lobby]")
{
    Lobby lobby;

    auto m = std::make_unique<QMainWindow>();
    auto socket = std::make_unique<QTcpSocket>(m.get());
    auto m1 = std::make_unique<QMainWindow>();
    auto socket1 = std::make_unique<QTcpSocket>(m1.get());
    Player *player1 = new Player(socket.get(), "Player1");
    Player *player2 = new Player(socket1.get(), "Player2");

    SECTION("Adding players to the lobby")
    {
        lobby.addPlayer(player1);
        REQUIRE(lobby.getPlayersCount() == 1);
        lobby.addPlayer(player2);
        REQUIRE(lobby.getPlayersCount() == 0);
    }
}

TEST_CASE("Player creation and point management", "[player]")
{
    Player player(nullptr, "Player1");

    SECTION("Player is created with correct username")
    {
        REQUIRE(player.getPlayerUsername() == "Player1");
    }

    SECTION("Point addition and retrieval")
    {
        player.addPoints(10);
        REQUIRE(player.getPoints() == 10);
    }
}
