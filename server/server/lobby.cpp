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


void Lobby::addPlayer(Player* player) {
    // Dodajemo novog igrača u lobi
    players.append(player);
    qDebug() << "Dodat je novi igrac u Lobby. Sada ih ima: " << getPlayersCount();

    // Proveramo da li imamo dovoljan broj igrača za sesiju
    if (getPlayersCount() >= 2) {
        // Kreiranje sesije sa prva dva igrača iz liste
        Session* session = new Session(players[0], players[1]);
//        delete session;

        // Uklanjamo igrače iz liste
        players.removeFirst();  // Uklanjamo prvog igrača
        players.removeFirst();  // Uklanjamo drugog igrača
        qDebug() << "Uklonili smo igrace iz Lobby-ja nakon zavrsetka igre. Sada ih ima: " << getPlayersCount();
    }
}

const QList<Player*>& Lobby::getPlayers() const {
    return players;
}

int Lobby::getPlayersCount() const{
    return players.size();
}
