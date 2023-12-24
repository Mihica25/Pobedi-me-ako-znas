#include "session.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>
#include <QRandomGenerator>

Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
//    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    recko = "HOUSE";
    //podrunda_resenje = -1;

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

    //sendMessageToPlayer1("TURN:true\n");

    //sendMessageToPlayer2("TURN:false\n");

    sendMessageToBothPlayers("START");

    //startRecko();

//    startWordle();
//    startPogodiSta();
//    startKoZnaZna();
//    startMemorija();
//    startMojBroj();

    startPodrunda();

    // Svako implemenitra komunikaciju izmedju servera i klijenta za svoju igru
    // Takodje moramo razmisliti gde implementirati komunikaciju na klijentskoj strani

    return;
}

void Session::startRecko(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
}

void Session::startPodrunda()
{
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadPodrunda);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadPodrunda);
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

void Session::player1ReadyReadPodrunda()
{
    // Obrada podataka koji stižu od prvog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processPodrundaMessage(receivedMessage, 1);
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

void Session::player2ReadyReadPodrunda()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processPodrundaMessage(receivedMessage, 2);
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

void Session::processPodrundaMessage(const QString& msg, const int num)
{
    if(msg.startsWith("ANSWER:"))
    {
        QString guesss = msg.mid(7);
        double guess = guesss.toDouble();
        if (num == 1)
        {
            player1->podrunda_guess = guess;
        }
        else if (num == 2)
        {
            player2->podrunda_guess = guess;
        }
    }
    else if (msg.startsWith("TIME:"))
    {
        QString times = msg.mid(5);
        double time = times.toDouble();
        if (num == 1)
        {
            player1->podrunda_time = time;
        }
        else if (num == 2)
        {
            player2->podrunda_time = time;
        }
    }
    else if (msg.startsWith("RESENJE:"))
    { 
        QString resenje = msg.mid(8);
        player1->podrunda_resenje = resenje.toDouble();
        player2->podrunda_resenje = resenje.toDouble();
    }
    else if (msg.startsWith("PITANJE!"))
    {
        // generisanje pitanja

        QString filePath = "/home/tamara/Desktop/pobedi-me-ako-znas/server/server/podrunda_pitanja/pitanja.txt";
        QStringList pitanja;

        if (!QFile::exists(filePath))
        {
            qDebug() << "Fajl ne postoji.\n";
        }

        // Otvaranje fajla za čitanje
        QFile file(filePath);
        //qDebug() << "Greška prilikom otvaranja fajla:" << file.errorString();
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nije moguće otvoriti fajl za čitanje.\n";
        }

        // Čitanje linija iz fajla i ispis na ekran
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            qDebug() << line;
            pitanja.append(line);
        }

        // Zatvaranje fajla
        file.close();

        int randomNumber = QRandomGenerator::global()->bounded(5);

        QString pitanje = pitanja.value(randomNumber);

        //qDebug() << "pitanje na serveru:" << pitanje << endl;
        //QStringList pitanje_odgovor = pitanje.split(',');
        sendMessageToBothPlayers("PITANJE:" + pitanje + "\n");
    }


    if (player1->podrunda_time != -1 & player2->podrunda_time != -1 & player1->podrunda_guess != -1 & player2->podrunda_guess != -1 & player1->podrunda_resenje != -1 & player2->podrunda_resenje != -1)
    {        
        int pobednikk = checkPodrundaWinner();
        QString pobednik = QString::number(pobednikk);
        //sendMessageToPlayer1("POBEDNIK:" + pobednik);

        if (pobednikk == 11)
        {
            sendMessageToPlayer1("POBEDNIK:" + pobednik);
            pobednikk = 21;
            QString pobednik = QString::number(pobednikk);
            sendMessageToPlayer2("POBEDNIK:" + pobednik);
        }
        else if (pobednikk == 21)
        {
            sendMessageToPlayer1("POBEDNIK:" + pobednik);
            pobednikk = 11;
            QString pobednik = QString::number(pobednikk);
            sendMessageToPlayer2("POBEDNIK:" + pobednik);
        }
        else if (pobednikk == 12)
        {
            sendMessageToPlayer1("POBEDNIK:" + pobednik);
            pobednikk = 22;
            QString pobednik = QString::number(pobednikk);
            sendMessageToPlayer2("POBEDNIK:" + pobednik);
        }
        else if (pobednikk == 22)
        {
            sendMessageToPlayer1("POBEDNIK:" + pobednik);
            pobednikk = 12;
            QString pobednik = QString::number(pobednikk);
            sendMessageToPlayer2("POBEDNIK:" + pobednik);
        }
        else
        {
            sendMessageToBothPlayers("POBEDNIK:" + pobednik);
        }
    }
    /*
    if(msg.startsWith("ROUND:")) {
            QString guess = msg.mid(6);  // Preskakanje prvih 5 karaktera (prefiks "ROUND:")
            guess = guess.toUpper();
            QString result = checkReckoSolution(word);
            if(result == "GGGGG"){
                sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\nPOINTS:10\n"));
            } else {
                sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\n"));
            }
    }
    */
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

int Session::checkPodrundaWinner()
{
    int razlika1 = qAbs(player1->podrunda_guess - player1->podrunda_resenje);
    int razlika2 = qAbs(player2->podrunda_guess - player2->podrunda_resenje);

    //qDebug() << "podrunda resenje 1 " << player1->podrunda_resenje;

    if (razlika1 < 0 || razlika2 < 0)
        return -1;

    //return razlika2;

    if (razlika1 < razlika2)
    {
        // pobednik je 1. igrac jer je blizi resenju
        return 11;
    }
    else if (razlika1 > razlika2)
    {
        // pobednik je 2. igrac jer je blizi resenju
        return 21;
    }
    else if (razlika1 == razlika2)
    {
        if(player1->podrunda_time > player2->podrunda_time)
        {
            // pobednik je 1. igrac jer je brzi
            return 12;
        }
        else if(player1->podrunda_time < player2->podrunda_time)
        {
            // pobednik je 2. igrac jer je brzi
            return 22;
        }
        else
        {
            // nereseno -> oba igraca dobijaju poene
            return 0;
        }
    }
    return -1;
}
