#ifndef LOBBY_H
#define LOBBY_H

#include <QObject>
#include "player.h"
#include <QDebug>
#include <algorithm>
#include "session.h"

class Lobby : public QObject
{
    Q_OBJECT

public:
    Lobby(QObject *parent = nullptr);
    ~Lobby();

    void addPlayer(Player *player);
    const QList<Player*>& getPlayers() const;
    int getPlayersCount() const;


private:
    QList<Player*> players;

};

#endif // LOBBY_H
