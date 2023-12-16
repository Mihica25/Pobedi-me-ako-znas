#include "session.h"

Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
    connect(player1->getTcpSocket(), &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
    connect(player2->getTcpSocket(), &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    startGame();
}

Session::~Session()
{
    disconnect(player1->getTcpSocket(), &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
    disconnect(player2->getTcpSocket(), &QTcpSocket::readyRead, this, &Session::player2ReadyRead);
}

void Session::sendMessageToPlayer1(const QString &message)
{
    // Slanje poruke prvom igraču
    player1->getTcpSocket()->write(message.toUtf8());
    player1->getTcpSocket()->flush();
}

void Session::sendMessageToPlayer2(const QString &message)
{
    // Slanje poruke drugom igraču
    player2->getTcpSocket()->write(message.toUtf8());
    player2->getTcpSocket()->flush();
}

void Session::sendMessageToBothPlayers(const QString &message)
{
    sendMessageToPlayer1(message);
    sendMessageToPlayer2(message);
}

void Session::player1ReadyRead()
{
    // Obrada podataka koji stižu od prvog igrača
    qDebug() << "Data received from Player 1: " << player1->getTcpSocket()->readAll();
}

void Session::player2ReadyRead()
{
    // Obrada podataka koji stižu od drugog igrača
    qDebug() << "Data received from Player 2: " << player2->getTcpSocket()->readAll();
}


void Session::startGame(){

    // Ovde cemo implementirati svu logiku, bilo bi dobro da izgleda nalik ovome

//    startWordle();
//    startPogodiSta();
//    startKoZnaZna();
//    startMemorija();
//    startMojBroj();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}
