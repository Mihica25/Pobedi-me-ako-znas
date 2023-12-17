#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Player : public QObject
{
    Q_OBJECT

public:
    Player(QTcpSocket *socket, const QString& username, QObject *parent = nullptr);
    ~Player();

    QString getPlayerUsername() const;
    int getPoints() const;
    QTcpSocket* getTcpSocket();

private:
    QTcpSocket* tcpSocket;
    QString username;
    int points;
};

#endif // PLAYER_H
