#include "session.h"
#include <thread>
#include <chrono>
#include <random>
#include <QDebug>


Session::Session(Player *player1, Player *player2, QStringList reckoChoosenWords, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
//    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);
    player1->playerId = 1;
    player2->playerId = 2;
    reckoWords = reckoChoosenWords;
    recko = reckoWords[0];
    qDebug() << "Recko word:" << recko << endl;
    reckoGameNo = 1;
    reckoPoints = 12;
    reckoWordNo = 0;

    generatedCards = generateCardIds();
    submit_mojbroj = 0;
    gameEnd_mojbroj = 0;

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

    QString filePath = "/home/user/pobedi-me-ako-znas/server/server/pitanja/kozna.txt";


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
        pitanje = in.readLine();

        file.close();


    //pitanje = "koloko godina ima rsum?_5_6_7_22_22/Koji mesece ima tacno 28 dana?_Janaur_Februar_Mart_April_Februar/Ko je rekorder evrolige po broju asistencija?_Markus Vilijams_Stefan Jovic_Milos Teodosic_Nik Kalates_Stefan Jovic";

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

    startRecko();

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

void Session::stopRecko(){
    qDebug() << "Zavrsio se Recko, prelazimo na sledecu igru :)" << endl;
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);

    // Ovde trebamo pozvati funkciju koja ce pokrenuti MojBroj
    startMojBroj();

    return;
}


void Session::startMemorija(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead,this,&Session::player1ReadyReadMemorija);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMemorija);

}

void Session::stopMemorija(){
    qDebug() << "Zavrsila se Memorija, prizazujemo statistiku " << endl;

    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadMemorija);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMemorija);

    return;
}


//
void Session::stopMojBroj(){
    qDebug() << "Zavrsio se Mojbroj, prelazimo na sledecu igru :)" << endl;
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadMojBroj);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMojBroj);

    startKoZna();

    return;
}

void Session::stopKoZna(){
    qDebug() << "Zavrsila se KoZna, prelazimo na sledecu igru :)" << endl;
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadKoZna);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadKoZna);

    startPogodiSta();
    //pokretanje sledece igre

    return;
}
//
void Session::stopPogodiSta() {
    qDebug() << "Zavrsila se igra Pogodi Sta, prelazimo na sledecu igru :)" << endl;
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadPogodiSta);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadPogodiSta);
    //pokretanje sledece igre

}

void Session::startMojBroj(){
    qDebug()<<"zapoCETOOOOOOOOOOO";
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadMojBroj);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMojBroj);
}

void Session::startPogodiSta()
{
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadPogodiSta);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadPogodiSta);
}

void Session::startKoZna(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadKoZna);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadKoZna);
}


void Session::otvoriPodrundu() {
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadKoZna);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadKoZna);

    startPodrunda();
}

void Session::stopPodrunda()
{
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadPodrunda);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadPodrunda);

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

    //qDebug()<<receivedMessages<<endl;

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processKoZnaMessage(receivedMessage, 1);
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

void Session::processReckoMessage(const QString& msg){
    if(msg.startsWith("WORD:")) {
            reckoWordNo++;
            QString word = msg.mid(5);  // Preskakanje prvih 5 karaktera (prefiks "WORD:")
            word = word.toUpper();
            QString result = checkReckoSolution(word);
            if(result == "GGGGG"){
                sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\nPOINTS:") + QString::number(reckoPoints) + "\n" + "GAME" + QString::number(reckoGameNo) + "_ENDED\n");
                if(reckoGameNo == 1){
                    player1->addPoints(reckoPoints);
                } else {
                    player2->addPoints(reckoPoints);
                }
                reckoWordNo = 0;
                reckoPoints = 12;
                reckoGameNo++;
                recko = reckoWords[1];
                qDebug() << "Recko2: " << recko;
                if(reckoGameNo > 2){
                    qDebug() << "Stopiramo recka" << endl;
                    stopRecko();
                }
            } else {
                if(reckoWordNo < 5){
                    sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\n"));
                    reckoPoints -= 2;
                } else {
                     sendMessageToBothPlayers("OP_WORD:" + word + "\nRESULT:" + result.append("\nGAME") + QString::number(reckoGameNo) + "_ENDED\n");
                     reckoPoints = 12;
                     reckoWordNo = 0;
                     reckoGameNo++;
                     recko = reckoWords[1];
                     qDebug() << "Recko2: " << recko;
                     if(reckoGameNo > 2){
                         qDebug() << "Stopiramo recka" << endl;
                         stopRecko();
                     }
                }
            }
    } else if(msg.startsWith("TIMES_UP")){
        sendMessageToBothPlayers("CORRECT_WORD:" + recko + "\nGAME" + QString::number(reckoGameNo) + "_ENDED\n");
        reckoPoints = 12;
        reckoGameNo++;
        reckoWordNo = 0;
        recko = reckoWords[1];
        qDebug() << "Recko2: " << recko;
        if(reckoGameNo > 2){
            qDebug() << "Stopiramo recka" << endl;
            stopRecko();
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

        QString filePath = "/home/user/pobedi-me-ako-znas/server/server/pitanja/podrunda.txt";
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

        if(player1->pobednik & player2->pobednik)
        {
            //sendMessageToBothPlayers("POENI3\n");
            sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
            sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        }
        else if(player1->pobednik & !player2->pobednik)
        {
            //sendMessageToBothPlayers("POENI1\n");
            sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
            //sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        }
        else if(!player1->pobednik & player2->pobednik)
        {
            //sendMessageToBothPlayers("POENI2\n");
            //sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
            sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        }


        if (player1->podrunda_guess == -2 & player2->podrunda_guess == -2)
        {
            sendMessageToBothPlayers("ISTEKLO VREME!\n");
        }
        else if(player1->podrunda_guess == -2)
        {
            qDebug() << "prvi nije odg\n";
            sendMessageToPlayer1("ISTEKLO VREME!\n");
            sendMessageToPlayer2("POBEDNIK:22\n");
            sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        }
        else if(player2->podrunda_guess == -2)
        {
            qDebug() << "drugi nije odg\n";
            sendMessageToPlayer2("ISTEKLO VREME!\n");
            sendMessageToPlayer1("POBEDNIK:11\n");
            sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
        }
        else
        {
            //int pobednikk = checkPodrundaWinner();
            //QString pobednik = QString::number(pobednikk);
            //sendMessageToPlayer1("POBEDNIK:" + pobednik);

            if (pobednikk == 11)
            {
                //sendMessageToBothPlayers("POENI1\n");
                sendMessageToPlayer1("POBEDNIK:" + pobednik);
                pobednikk = 21;
                QString pobednik = QString::number(pobednikk);
                sendMessageToPlayer2("POBEDNIK:" + pobednik);
            }
            else if (pobednikk == 21)
            {
                //sendMessageToBothPlayers("POENI2\n");
                sendMessageToPlayer1("POBEDNIK:" + pobednik);
                pobednikk = 11;
                QString pobednik = QString::number(pobednikk);
                sendMessageToPlayer2("POBEDNIK:" + pobednik);
            }
            else if (pobednikk == 12)
            {
                //sendMessageToBothPlayers("POENI1\n");

                sendMessageToPlayer1("POBEDNIK:" + pobednik);
                pobednikk = 22;
                QString pobednik = QString::number(pobednikk);
                sendMessageToPlayer2("POBEDNIK:" + pobednik);
            }
            else if (pobednikk == 22)
            {
                //sendMessageToBothPlayers("POENI2\n");
                sendMessageToPlayer1("POBEDNIK:" + pobednik);
                pobednikk = 12;
                QString pobednik = QString::number(pobednikk);
                sendMessageToPlayer2("POBEDNIK:" + pobednik);
            }
            else
            {
                if(pobednikk == 0)
                    //sendMessageToBothPlayers("POENI12\n");

                sendMessageToBothPlayers("POBEDNIK:" + pobednik);
            }
        }

        player1->podrunda_time = -1;
        player2->podrunda_time = -1;
        player1->podrunda_guess = -1;
        player2->podrunda_guess = -1;
        player1->podrunda_resenje = -1;
        player2->podrunda_resenje = -1;

        stopPodrunda();
    }
}

void Session::processMemorijaMessage(const QString& request){
    if(request.startsWith("GENERATE_CARD_IDS")){
        QString cardIdsString;
        int size =generatedCards.size();
        for(int i = 0; i < size; ++i){
            cardIdsString.append(QString::number(generatedCards[i]));

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

    const int totalCards = 20;
    const int cardPairs = 10;

    QVector<int> allCardIds;
    QVector<int> finalCardIds;

    for(int i = 1; i <= totalCards; ++i){
        allCardIds.append(i);
    }

    shuffleQVector(allCardIds);

    for(int i = 0; i<cardPairs; ++i){
        finalCardIds.append(allCardIds[i]);
        finalCardIds.append(allCardIds[i]);
    }

    shuffleQVector(finalCardIds);
    return finalCardIds;
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
