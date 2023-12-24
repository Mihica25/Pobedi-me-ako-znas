#include "player.h"

Player::Player(QTcpSocket* socket, const QString& username, QObject *parent) : QObject(parent), tcpSocket(socket), username(username), points(0)
{
    qDebug() << "Kreiran je igrac: " << username;

    int pointsKoZna = 0;

}

Player::~Player()
{
    // Osigurajte da se resursi oslobode prilikom uništavanja objekta
    delete tcpSocket;
}


QString Player::getPlayerUsername() const
{
    return username;
}

int Player::getPoints() const
{
    return points;
}

