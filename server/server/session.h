#ifndef SESSION_H
#define SESSION_H

#include <QTcpServer>
#include <QDebug>
#include "player.h"

class Session : public QObject
{
    Q_OBJECT

public:
    Session(Player *player1, Player *player2, QObject *parent = nullptr);
    ~Session();

    void sendMessageToPlayer1(const QString &message);
    void sendMessageToPlayer2(const QString &message);
    void sendMessageToBothPlayers(const QString &message);

private slots:
    void player1ReadyRead();
    void player2ReadyRead();

private:
    Player *player1;
    Player *player2;

    void startGame();

};

#endif // SESSION_H
