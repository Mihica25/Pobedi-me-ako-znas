#include "player.h"

Player::Player(QTcpSocket* socket, const QString& username, QObject *parent, bool isReady) : QObject(parent), tcpSocket(socket), username(username), points(0)
{
    qDebug() << "Kreiran je igrac: " << username;
    podrunda_time = -1;
    podrunda_guess = -1;
    podrunda_resenje = -1;
    pointsKoZna = 0;

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

void Player::addPoints(int p){
    points += p;
}

