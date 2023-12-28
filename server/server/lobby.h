#ifndef LOBBY_H
#define LOBBY_H

#include <QObject>
#include "player.h"
#include <QDebug>
#include <algorithm>
#include "session.h"
#include <QRandomGenerator>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QStringList>

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
    QStringList reckoWordList;

    QStringList loadWordsFromFile(const QString &filePath);
    QStringList chooseRandomWords(const QStringList &wordList);

};

#endif // LOBBY_H
