#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>

class Player : public QObject
{
    Q_OBJECT

public:
    Player(QTcpSocket *socket, QObject *parent = nullptr);
    ~Player();

    int getPlayerId() const;
    int getPoints() const;
    QTcpSocket* getTcpSocket();

private:
    QTcpSocket* tcpSocket;
    int playerId;
    int points;


    void generatePlayerId();

};

#endif // PLAYER_H
