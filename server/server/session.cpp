#include "session.h"
#include <thread>
#include <chrono>


Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
//    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);
    player1->playerId = 1;
    player2->playerId = 2;
    recko = "HOUSE";

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

    // startRecko();

//    startWordle();
    startPogodiSta();
//    startKoZnaZna();
//    startMemorija();
//    startMojBroj();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}

void Session::startRecko(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
}

void Session::startPogodiSta()
{
    // disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    // disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadPogodiSta);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadPogodiSta);
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
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processReckoMessage(receivedMessage);
        }
    }
}

void Session::player1ReadyReadPogodiSta()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processPogodiStaMessage(receivedMessage, player1);
        }
    }
}

void Session::player2ReadyReadPogodiSta()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processPogodiStaMessage(receivedMessage, player2);
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

void Session::processPogodiStaMessage(const QString &msg, Player* player)
{
    if(msg.startsWith("IMAGE_GEN")) {
        player->isReady = true;
        if(player1->isReady == true && player2->isReady == true){
            generatePogodiSta();
            player1->isReady = false;
            player2->isReady = false;
        }
    }
    else if (msg.startsWith("IMG_GUESS:")) {
        QString guess = msg.mid(10);
        qDebug() << "Player" + QString::number(player->playerId)
                 << " guessed: " + guess;
        if(guess == pogodiSta.toLower()) {
            QString answer = "IMG_ANS:" + QString::number(player->playerId) + ":" + pogodiSta + "\n";
            sendMessageToBothPlayers(answer);
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

void Session::generatePogodiSta()
{
    QFile file(":/data/resources/PogodiSta.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QStringList lines = QTextStream(&file).readAll().split('\n');
        int randomIndex = QRandomGenerator::global()->bounded(lines.size());
        QString randomLine = lines[randomIndex];
        qDebug() << randomLine;

        QStringList parts = randomLine.split(',');
        if (parts.size() == 3) {
            int index = parts[0].trimmed().toInt();
            pogodiSta = parts[1].trimmed();
            qDebug() << "PogodiSta answer: " + pogodiSta;
            QString info = parts[2].trimmed();

            QByteArray message;
            message.append("IMAGE_G:");
            message.append(QString::number(index) + ":");
            message.append(info.toUtf8() + ":");
            message.append(pogodiSta + "\n");
            sendMessageToBothPlayers(message);
        }
    }
}


