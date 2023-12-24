#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Player : public QObject
{
    Q_OBJECT

public:
    Player(QTcpSocket* socket, const QString& username, QObject *parent = nullptr);
    ~Player();

    QString getPlayerUsername() const;
    int getPoints() const;

    QTcpSocket* tcpSocket;

    int podrunda_time;
    int podrunda_guess;
    int podrunda_resenje;

private:
    QString username;
    int points;
};

#endif // PLAYER_H
