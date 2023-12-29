#include "player.h"

Player::Player(QTcpSocket* socket, const QString& username, QObject *parent, bool ready) : QObject(parent), tcpSocket(socket), username(username), points(0)
{
    qDebug() << "Kreiran je igrac: " << username;
    podrunda_time = -1;
    podrunda_guess = -1;
    podrunda_resenje = -1;
    pointsKoZna = 0;
    playerId = 0;
    isReady = ready;

}

Player::~Player()
{
    // Osigurajte da se resursi oslobode prilikom uništavanja objekta
    qDebug() << "~Player()" << endl;
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

void Player::setPoints(int p)
{
    points = p;
}

