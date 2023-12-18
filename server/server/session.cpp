#include "session.h"
#include <thread>
#include <chrono>


Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    recko = "HOUSE";

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

    sendMessageToPlayer1(player2->getPlayerUsername());
    if(player1->tcpSocket->waitForReadyRead(10000)){
        qDebug() << (QString::fromUtf8(player1->tcpSocket->readAll())) << endl;
    }
    sendMessageToPlayer2(player1->getPlayerUsername());
    if(player2->tcpSocket->waitForReadyRead(10000)){
        qDebug() << (QString::fromUtf8(player2->tcpSocket->readAll())) << endl;
    }

    sendMessageToPlayer1("true");
    if(player1->tcpSocket->waitForReadyRead(10000)){
        qDebug() << (QString::fromUtf8(player1->tcpSocket->readAll())) << endl;
    }
    sendMessageToPlayer2("false");
    if(player2->tcpSocket->waitForReadyRead(10000)){
        qDebug() << (QString::fromUtf8(player2->tcpSocket->readAll())) << endl;
    }
    QString result = "";
    if(player1->tcpSocket->waitForReadyRead(60000)){
        QString word = QString::fromUtf8(player1->tcpSocket->readAll());
        qDebug() << word << endl;
        qDebug() << recko << endl;
        QString result = "";
        if(recko.size() >=4 && word.size() >=4){
            for(unsigned i = 0; i<5; i++){
                QString slovo = word.at(i);
                if(recko.contains(slovo)){
                    break;
                }
                qDebug() << "Ispis" << endl;
                if(word.at(i) == recko.at(i)){
                    result += "G";
                    qDebug() << "at" << endl;
                }
                else if (recko.contains(word.at(i))) {
                    result += "Y";
                    qDebug() << "contains ili upper" << endl;
                } else {
                    result += "R";
                }
            }
        }
//        for(unsigned i = 0; i<5; i++){
//            QString slovo = word.at(i);
//            if(recko.contains(slovo)){
//                break;
//            }
//            qDebug() << "Ispis" << endl;
//            if(word.at(i) == recko.at(i)){
//                result += "G";
//                qDebug() << "at" << endl;
//            }
//            else if (recko.contains(word.at(i))) {
//                result += "Y";
//                qDebug() << "contains ili upper" << endl;
//            } else {
//                result += "R";
//            }
//        }
    }
    sendMessageToPlayer1(result);
    if(result == "GGGGG"){
        sendMessageToPlayer1("10");
    }
    result = "";
    if(player1->tcpSocket->waitForReadyRead(60000)){
        QString word = QString::fromUtf8(player1->tcpSocket->readAll());
        qDebug() << word << endl;
        QString result = "";
        for(int i = 0; i<5; i++){
            qDebug() << "Ispis" << endl;
            if(word.at(i) == recko.at(i)){
                result += "G";
                qDebug() << "at" << endl;
            }
            else if (recko.contains(word.at(i))) {
                result += "Y";
                qDebug() << "contains ili upper" << endl;
            } else {
                result += "R";
            }
        }
    }
    sendMessageToPlayer1(result);
    if(result == "GGGGG"){
        sendMessageToPlayer1("10");
    }
    result = "";
    if(player1->tcpSocket->waitForReadyRead(60000)){
        QString word = QString::fromUtf8(player1->tcpSocket->readAll());
        qDebug() << word << endl;
        QString result = "";
        for(int i = 0; i<5; i++){
            if(word.at(i) == recko.at(i)){
                result += "G";
            }
            else if (recko.contains(word.at(i).toUpper())) {
                result += "Y";
            } else {
                result += "R";
            }
        }
    }
    sendMessageToPlayer1(result);
    if(result == "GGGGG"){
        sendMessageToPlayer1("10");
    }
    result = "";
    if(player1->tcpSocket->waitForReadyRead(60000)){
        QString word = QString::fromUtf8(player1->tcpSocket->readAll());
        qDebug() << word << endl;
        QString result = "";
        for(int i = 0; i<5; i++){
            if(word.at(i) == recko.at(i)){
                result += "G";
            }
            else if (recko.contains(word.at(i).toUpper())) {
                result += "Y";
            } else {
                result += "R";
            }
        }
    }
    sendMessageToPlayer1(result);
    if(result == "GGGGG"){
        sendMessageToPlayer1("10");
    }
    result = "";
    if(player1->tcpSocket->waitForReadyRead(60000)){
        QString word = QString::fromUtf8(player1->tcpSocket->readAll());
        qDebug() << word << endl;
        QString result = "";
        for(int i = 0; i<5; i++){
            if(word.at(i) == recko.at(i)){
                result += "G";
            }
            else if (recko.contains(word.at(i).toUpper())) {
                result += "Y";
            } else {
                result += "R";
            }
        }
    }
    sendMessageToPlayer1(result);
    if(result == "GGGGG"){
        sendMessageToPlayer1("10");
    }
    result = "";




//    startWordle();
//    startPogodiSta();
//    startKoZnaZna();
//    startMemorija();
//    startMojBroj();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}
