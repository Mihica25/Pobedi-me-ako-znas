#include "session.h"
#include <thread>
#include <chrono>


Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    startGame();
}

Session::~Session()
{
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    delete player1;
    delete player2;
}

void Session::sendMessageToPlayer1(const QString &message)
{
    // Slanje poruke prvom igraču
    player1->tcpSocket->write(message.toUtf8());
    player1->tcpSocket->flush();
}

void Session::sendMessageToPlayer2(const QString &message)
{
    // Slanje poruke drugom igraču
    player2->tcpSocket->write(message.toUtf8());
    player2->tcpSocket->flush();
}

void Session::sendMessageToBothPlayers(const QString &message)
{
    sendMessageToPlayer1(message);
    sendMessageToPlayer2(message);
}

void Session::player1ReadyRead()
{
    // Obrada podataka koji stižu od prvog igrača
    qDebug() << "Data received from Player 1: " << player1->tcpSocket->readAll();
}

void Session::player2ReadyRead()
{
    // Obrada podataka koji stižu od drugog igrača
    qDebug() << "Data received from Player 2: " << player2->tcpSocket->readAll();
}


void Session::startGame(){
//    player1->tcpSocket->waitForReadyRead(-1);
//    qDebug() << (QString::fromUtf8(player1->tcpSocket->readAll())) << endl;

    // Ovde cemo implementirati svu logiku, bilo bi dobro da izgleda nalik ovome
    sendMessageToPlayer1("OPPONENT USERNAME: " + player2->getPlayerUsername());
    sendMessageToPlayer2("OPPONENT USERNAME: " + player1->getPlayerUsername());
    sendMessageToPlayer1("TURN: true");
    sendMessageToPlayer2("TURN: false");
//    startWordle();
//    startPogodiSta();
//    startKoZnaZna();
//    startMemorija();
//    startMojBroj();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}
