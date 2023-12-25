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

    //ovo mora da se sredi, ovde samo radi testiranja
    QVector<QVector<QString>> questions;
    QVector<QString> question1;
    question1 << "Koji mesece ima tacno 28 dana?" "Janaur""Februar" << "Mart" << "April" << "Februar";
    questions.append(question1);
    QVector<QString> question2;
    question2 << "Neutralna boja?" << "Bela" << "Plava" << "Crvena" << "Zelena" << "Bela";
    questions.append(question2);
    QVector<QString> question3;
    question3 << "Ko je rekorder evrolige po broju asistencija?" << "Markus Vilijams" << "Stefan Jovic" << "Milos Teodosic" << "Nik Kalates" << "Stefan Jovic";
    questions.append(question3);

    QString answer1 = "";
    QString answer2 = "";
    player1->pointsKoZna = 0;
    player2->pointsKoZna = 0;






   pitanje = "koloko godina ima rsum?_5_6_7_22_22/Koji mesece ima tacno 28 dana?_Janaur_Februar_Mart_April_Februar/Ko je rekorder evrolige po broju asistencija?_Markus Vilijams_Stefan Jovic_Milos Teodosic_Nik Kalates_Stefan Jovic";

    qDebug()<<"velicina:"<<pitanje.size();


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

    //startRecko();
      startKoZna();
      startPodrunda();

//    startWordle();
//    startPogodiSta();
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

void Session::startKoZna(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadKoZna);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadKoZna);
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

void Session::player1ReadyReadKoZna()
{
    // Obrada podataka koji stižu od prvog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processKoZnaMessage(receivedMessage, 1);
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

void Session::player2ReadyReadKoZna()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processKoZnaMessage(receivedMessage, 2);
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

void Session::processKoZnaMessage(const QString& msg, int num){

    if(msg.startsWith("SEND")){

        sendMessageToBothPlayers("PITANJE:" + pitanje + "\n");
    }
    if(msg.startsWith("ANSWER:") and num == 1) {
        QStringList odg = msg.mid(7).split(",");
             //answer1 = msg.mid(7);
        answer1 = odg.value(0);
        qDebug()<< answer1 ;

        qDebug() << odg.value(1).toInt() << "porukicaaaaa\n";
        qDebug() << odg << "listaaa\n";
        int poeni1 = odg.value(1).toInt();
        if (poeni1 == 5)
             player1->pointsKoZna -= poeni1;
        else
            player1->pointsKoZna += poeni1;


        //if da se doda sa prefiksom da li je manje ili vece od nule
        sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
        sendMessageToPlayer2("ANSWERP1:" + answer1 + "\n");


      }

    if(msg.startsWith("ANSWER:") and num == 2) {
            // answer2 = msg.mid(7);
            //sendMessageToPlayer1("ANSWERP2:" + answer2 + "\n");

        QStringList odg = msg.mid(7).split(",");
             //answer1 = msg.mid(7);
        answer2 = odg.value(0);

        qDebug()<<"sada"<< answer2 << endl;

        qDebug() << odg.value(1) << "porukicaaaaa\n";
        qDebug() << odg << "listaaa\n";
        int poeni2 = odg.value(1).toInt();
        if (poeni2 == 5)
             player2->pointsKoZna -= poeni2;
        else
            player2->pointsKoZna += poeni2;


        //da se doda
        sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        sendMessageToPlayer1("ANSWERP2:" + answer2 + "\n");
    }

    if(answer1 != "" and answer2 != ""){
        sendMessageToBothPlayers("PREBACI\n");
        answer1 = "";
        answer2 = "";

      if(msg.startsWith("POINTS:") and num == 1){
          qDebug() << "serverrr" << player1->pointsKoZna << endl;
          int poeni = msg.mid(7).toInt();
          player1->pointsKoZna += poeni;
          sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
      }


      if(msg.startsWith("POINTS:") and num == 2){
          qDebug() << "serverrr" << player2->pointsKoZna << endl;
         int  poeni = msg.mid(7).toInt();
           player2->pointsKoZna += poeni;
          sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
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

QString Session::checkKoZnaSolution(const QString& word){
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

