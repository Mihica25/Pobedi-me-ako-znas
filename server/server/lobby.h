#ifndef LOBBY_H
#define LOBBY_H

#include "player.h"
#include "session.h"
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QRandomGenerator>
#include <QStringList>
#include <QTextStream>
#include <algorithm>

class Lobby : public QObject
{
  Q_OBJECT

public:
  Lobby (QObject *parent = nullptr);
  ~Lobby ();

  void addPlayer (Player *player);
  const QList<Player *> &getPlayers () const;
  int getPlayersCount () const;

private:
  QList<Player *> players;
  QStringList reckoWordList;

  QStringList loadWordsFromFile (const QString &filePath);
  QStringList chooseRandomWords (const QStringList &wordList);
};

#endif // LOBBY_H
