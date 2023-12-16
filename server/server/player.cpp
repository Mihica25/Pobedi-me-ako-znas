#include "player.h"
#include <QRandomGenerator>

Player::Player(QTcpSocket *socket, QObject *parent) : QObject(parent), tcpSocket(socket), points(0)
{
    generatePlayerId();
}

Player::~Player()
{
    // Osigurajte da se resursi oslobode prilikom uništavanja objekta
    delete tcpSocket;
}

int Player::getPlayerId() const
{
    return playerId;
}

int Player::getPoints() const
{
    return points;
}

void Player::generatePlayerId()
{
    // Generiši slučajan ID između 0 i 10000
    // Ovo je samo privremeno dok ne ubacimo logiku u kojoj ce korisnik unositi nickname
    playerId = QRandomGenerator::global()->bounded(10001);
}

QTcpSocket* Player::getTcpSocket(){
    return tcpSocket;
}
