#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Player : public QObject
{
    Q_OBJECT

public:
    Player(QTcpSocket* socket, const QString& username, QObject *parent = nullptr,
            bool isReady = false);
    ~Player();

    QString getPlayerUsername() const;
    int getPoints() const;

    QTcpSocket* tcpSocket;
    bool isReady;
    int playerId;
private:
    QString username;
    int points;
};

#endif // PLAYER_H
