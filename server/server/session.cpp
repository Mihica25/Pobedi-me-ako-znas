#include "session.h"
#include <thread>
#include <chrono>
#include <random>
#include <QDebug>


Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
//    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    cardIdssss = generateCardIds();
    startGame();
}

Session::~Session()
{
//    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    delete player1;
    delete player2;
}

void Session::sendMessageToPlayer1(QString message)
{
    // Slanje poruke prvom igraču
    qDebug() << "Saljemo poruku igracu 1: " << message << endl;
    player1->tcpSocket->write(message.toUtf8());
    player1->tcpSocket->flush();
}

void Session::sendMessageToPlayer2(QString message)
{
    // Slanje poruke drugom igraču
    qDebug() << "Saljemo poruku igracu 2: " << message << endl;
    player2->tcpSocket->write(message.toUtf8());
    player2->tcpSocket->flush();
}

void Session::sendMessageToBothPlayers(QString message)
{
    sendMessageToPlayer1(message);
    sendMessageToPlayer2(message);
}

//void Session::player1ReadyRead()
//{
//    // Obrada podataka koji stižu od prvog igrača
//    qDebug() << "Data received from Player 1: " << player1->tcpSocket->readAll();
//}

//void Session::player2ReadyRead()
//{
//    // Obrada podataka koji stižu od drugog igrača
//    qDebug() << "Data received from Player 2: " << player2->tcpSocket->readAll();
//}

void Session::startGame(){

    sendMessageToPlayer1("OP_NAME:" + player2->getPlayerUsername() + "\n");

    sendMessageToPlayer2("OP_NAME:" + player1->getPlayerUsername() + "\n");

    sendMessageToPlayer1("TURN:true\n");

    sendMessageToPlayer2("TURN:false\n");

    sendMessageToBothPlayers("START");

//    startRecko();

//    startWordle();
//    startPogodiSta();
//    startKoZnaZna();
    startMemorija();
//    startMojBroj();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}

void Session::startMemorija(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead,this,&Session::player1ReadyReadMemorija);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMemorija);

}


void Session::player1ReadyReadMemorija()
{
    // Obrada podataka koji stižu od prvog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processMemorijaMessage(receivedMessage);
        }
    }
}

void Session::player2ReadyReadMemorija()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processMemorijaMessage(receivedMessage);
        }
    }
}

//or use send Message to players and handle the changes there
void Session::processMemorijaMessage(const QString& request){
    if(request.startsWith("GENERATE_CARD_IDS")){
        QString cardIdsString;
        int size =cardIdssss.size();
        for(int i = 0; i < size; ++i){
            cardIdsString.append(QString::number(cardIdssss[i]));

            if(i < size - 1){
                cardIdsString.append(",");
            }
        }
        sendMessageToBothPlayers("CARD_IDS:" + cardIdsString + "\n");
    }else if(request.startsWith("TURN1")){
        sendMessageToPlayer1("CHANGETURN\n");
    }else if(request.startsWith("TURN2")){
        sendMessageToPlayer2("CHANGETURN\n");
    }else if(request.startsWith("MOVE1:")){
        QString id = request.mid(6);
        sendMessageToPlayer2("TURNCARD:" + id + "\n");
    }else if(request.startsWith("MOVE2:")){
        QString id = request.mid(6);
        sendMessageToPlayer1("TURNCARD:" + id + "\n");
    }else if(request.startsWith("POINTS1")){
        sendMessageToPlayer2("UPDATE_POINTS\n");
    }else if(request.startsWith("POINTS2")){
        sendMessageToPlayer1("UPDATE_POINTS\n");
    }else{
        //TODO
    }
}


void Session::shuffleQVector(QVector<int> &vector){
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vector.begin(),vector.end(),g);
}

QVector<int> Session::generateCardIds(){

    QVector<int> allCardIds;

    for(int i = 1; i <= 20; ++i){
        allCardIds.append(i);
    }

    shuffleQVector(allCardIds);

    QVector<int> cardIdss;

    for(int i = 0; i<10; ++i){
        cardIdss.append(allCardIds[i]);
    }

    QVector<int> finalCardIds;

    for(int num : cardIdss){
        finalCardIds.append(num);
        finalCardIds.append(num);
    }

    shuffleQVector(finalCardIds);
    return finalCardIds;
}

void Session::startRecko(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
}

void Session::player1ReadyReadRecko()
{
    // Obrada podataka koji stižu od prvog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processReckoMessage(receivedMessage);
        }
    }
}

void Session::player2ReadyReadRecko()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processReckoMessage(receivedMessage);
        }
    }
}

void Session::processReckoMessage(const QString& msg){
    if(msg.startsWith("WORD:")) {
            QString word = msg.mid(5);  // Preskakanje prvih 5 karaktera (prefiks "WORD:")
            word = word.toUpper();
            QString result = checkReckoSolution(word);
            if(result == "GGGGG"){
                sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\nPOINTS:10\n"));
            } else {
                sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\n"));
            }
    }
}

QString Session::checkReckoSolution(const QString& word){
    QString result;
    qDebug() << word << endl;
    qDebug() << recko << endl;
    for(int i = 0; i < recko.size() && i < word.size(); i++){
        if(word.at(i) == recko.at(i)){
            result.append("G");
        } else if (recko.contains(word.at(i))) {
            result.append("Y");
        } else {
            result.append("R");
        }
    }
    return result;
}
