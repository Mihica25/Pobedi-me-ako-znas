#include "lobby.h"

Lobby::Lobby(QObject *parent) : QObject(parent)
{
    // Inicijalizujte praznu listu
    players = QList<Player*>();
}

Lobby::~Lobby()
{
    // Oslobodite resurse i obrišite sve igrače
    std::for_each(players.begin(), players.end(), [](Player* player) {
        delete player;
    });
    players.clear();  // Očistite listu
}

void Lobby::addPlayer(Player *player)
{
    // Dodajte novog igrača u lobi
    players.append(player);

    // Ovde trebamo kreirati sesije svaki put kada ima dovoljan broj igraca koji cekaju u lobiju

    qDebug() << "Dodat je novi igrac u Lobby. Sada ih ima: " << getPlayersCount();
}

const QList<Player*>& Lobby::getPlayers() const {
    return players;
}

int Lobby::getPlayersCount() const{
    return players.size();
}
