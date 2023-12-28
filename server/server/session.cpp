#include "session.h"
#include <thread>
#include <chrono>


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

    //pokretanje sledece igre

    return;
}
//
void Session::stopPogodiSta() {
    qDebug() << "Zavrsila se igra Pogodi Sta, prelazimo na sledecu igru :)" << endl;
    disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
}

void Session::startMojBroj(){
    qDebug()<<"zapoCETOOOOOOOOOOO";
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadMojBroj);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMojBroj);
}

void Session::startPogodiSta()
{
    // disconnect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadRecko);
    // disconnect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadRecko);
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

void Session::player1ReadyReadMojBroj()
{
    // Obrada podataka koji stižu od prvog igrača
    QString msg = QString::fromUtf8(player1->tcpSocket->readAll());
    qDebug() << "Data received from Player 1: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processMojBrojMessage(receivedMessage);
        }
    }
}

void Session::player2ReadyReadMojBroj()
{
    // Obrada podataka koji stižu od drugog igrača
    QString msg = QString::fromUtf8(player2->tcpSocket->readAll());
    qDebug() << "Data received from Player 2: " << msg;

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processMojBrojMessage(receivedMessage);
        }
    }
}

void Session::processMojBrojMessage(const QString& msg){

    // Ako pocinje sa NUMBER I U PITANJU JE GENERATE ONDA POZOVI GENERISANJE brojeva i posalji igracima
    if(msg.startsWith("GENERATE:"))
    {
        //NE DIRATI GENERISANJE BROJEVA - FUNKCIONISE!
        QString originality = msg.mid(9);
        qDebug() << "OVOOOO jE; " << originality;
        if (originality == "original")
        {
            //generisi brojeve

            //saljemo brojeve
            sendMessageToBothPlayers("GENERATE:" + targetNumber + initialNumbers + "\n");

            qDebug() << "SALJE SE ORIGINAL: " << "GENERATE:" + targetNumber + initialNumbers + "\n";
        } else
        {
            //uzmi kopiju


            qDebug() << "SALJE SE KOPIJA: " << "GENERATE:" + targetNumber + initialNumbers + "\n";
            //saljemo brojeve
            sendMessageToBothPlayers("GENERATE:" + targetNumber + initialNumbers + "\n");
        }

    } else if(msg.startsWith("START GAME:"))
    {
        targetNumber = generateTargetNumber();
        initialNumbers = generateInitialNumbers();

        QString player = msg.mid(11);
        qDebug() << "SIGNAL I ZA START NJEGOV" << player;

        if (player == player1->getPlayerUsername())
        {
            qDebug() << "player111111111111111";
            sendMessageToPlayer1("START GAME");
        } else
        {
            qDebug() << "player222222222222222";
            sendMessageToPlayer2("START GAME");
        }
    } else if(msg.startsWith("EXPRESSION:"))
    {
        QString expression = msg.mid(11);
        if (expression.startsWith(player1->getPlayerUsername()))
            sendMessageToPlayer2("EXPRESSION:" + expression.mid(player1->getPlayerUsername().length()+1) + "\n");
        else
            sendMessageToPlayer1("EXPRESSION:" + expression.mid(player2->getPlayerUsername().length()+1) + "\n");

    } else if(msg.startsWith("RESULT:"))
    {
        QString result = msg.mid(7);
        qDebug() << "RESULT: " << result;

        int index = result.indexOf('%');
        if (result.left(index) == player1->getPlayerUsername())
        {
            player1_res = result.mid(index+1);
            qDebug() << "PLAYER1 RESULT: " << player1_res;
        } else
        {
            player2_res = result.mid(index+1);
            qDebug() << "PLAYER2 RESULT: " << player2_res;
        }

        submit_mojbroj++;
        checkMojBrojSolution(player1_res,player2_res);
    } else if(msg.startsWith("GAME END"))
    {
        qDebug("ENDDDDDDDDDDDDDDDDDDDDDDD");
        gameEnd_mojbroj++;

        if (gameEnd_mojbroj == 2)
        {
            sendMessageToBothPlayers("GAME END\n");
            //ovdeee
            stopMojBroj();
        }
    }
}

void Session::processKoZnaMessage(const QString& msg, int num){
    qDebug() << "Primljenja poruka:" << msg << endl;

    if(msg.startsWith("P1:")){
        player1->pointsKoZna = msg.mid(3).toInt();

    }

    if(msg.startsWith("P2:")){
        player2->pointsKoZna = msg.mid(3).toInt();

    }


    if(msg.startsWith("SEND")){
        qDebug()<< "Primljena"<<endl;

        sendMessageToBothPlayers("PITANJE:" + pitanje + "\n");
    }
    if(msg.startsWith("ANSWER:") and num == 1) {
        QStringList odg = msg.mid(7).split(",");
             //answer1 = msg.mid(7);
        answer1 = odg.value(0);
        qDebug() << answer1 ;

        qDebug() << odg.value(1).toInt() << "porukicaaaaa\n";
        qDebug() << odg << "listaaa\n";
        int poeni1 = odg.value(1).toInt();
        if (poeni1 == 5)
             player1->pointsKoZna -= poeni1;
        else
            player1->pointsKoZna += poeni1;


        //if da se doda sa prefiksom da li je manje ili vece od nule
        sendMessageToBothPlayers("POENI1:" + QString::number(player1->pointsKoZna) + "\n");
        //sendMessageToBothPlayers("POENI1:" + odg.value(1) + "\n");
        if(answer1 != "DALJE")
           sendMessageToPlayer2("ANSWERP1:" + answer1 + "\n");
    }

    if(msg.startsWith("ANSWER:") and num == 2) {
            // answer2 = msg.mid(7);
            //sendMessageToPlayer1("ANSWERP22:" + answer2 + "\n");

        QStringList odg = msg.mid(7).split(",");
             //answer1 = msg.mid(7);
        answer2 = odg.value(0);

        qDebug()<<"sada"<< answer2 << endl;

        qDebug() << odg.value(1) << "porukicaaaaa\n";
        qDebug() << odg << "listaaa\n";
        int poeni2 = odg.value(1).toInt();
        qDebug() << poeni2 << "kad je dalje\n";
        if (poeni2 == 5)
             player2->pointsKoZna -= poeni2;
        else
            player2->pointsKoZna += poeni2;


        //da se doda
        sendMessageToBothPlayers("POENI2:" + QString::number(player2->pointsKoZna) + "\n");
        if(answer2 != "DALJE")
          sendMessageToPlayer1("ANSWERP22:" + answer2 + "\n");
    }

    if(answer1 != "" and answer2 != ""){

        if (answer1 == "true" & answer2 == "true")
        {
            sendMessageToBothPlayers("PODRUNDA\n");
            otvoriPodrundu();
        }
        else
        {
            sendMessageToBothPlayers("PREBACI\n");
        }

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

        if(msg.startsWith("END")) {
            stopKoZna();
        }


    }
}



//DODATI POENE U SERVER
void Session::checkMojBrojSolution(const QString& pt1, const QString& pt2)
{
    qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<< submit_mojbroj;
    if (submit_mojbroj != 2 && submit_mojbroj != 4)
        return;

    int res1 = pt1.toInt();
    int res2 = pt2.toInt();
    int res  = targetNumber.toInt();
    qDebug() << pt1 << pt2 << targetNumber;

    if ( (res1 == -1179 || res1 == -1951) && (res2 != -1179 && res2 != -1951) )
    {
        sendMessageToBothPlayers("POINTS:0%10");
        return;
    } else if ( (res2 == -1179 || res2 == -1951) && (res1 != -1179 && res1 != -1951) )
    {
        sendMessageToBothPlayers("POINTS:10%0");
        return;
    } else if ( (res1 == -1179 && res2 == -1951) || (res1 == -1951 && res2 == -1179) || (res1 == -1179 && res2 == -1179) || (res1 == -1951 && res2 == -1951))
    {   qDebug() << "PRAZNO!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        sendMessageToBothPlayers("POINTS:0%0");
        return;
    }

    if (qAbs(res-res1) < qAbs(res-res2))
    {
        sendMessageToBothPlayers("POINTS:10%0");
    } else if (qAbs(res-res1) > qAbs(res-res2))
    {
        sendMessageToBothPlayers("POINTS:0%10");
    } else {
        sendMessageToBothPlayers("POINTS:5%5");
    }

}

QString Session::generateTargetNumber()
{
    return QString::number(QRandomGenerator::global()->bounded(1,1000));
}

//Done - added QRadnomGenerator
QString Session::generateInitialNumbers()
{
    QString initialNumbers;

    for (int i = 0; i < 4; ++i)
    {
        int randomNumber = QRandomGenerator::global()->bounded(1,10);
        initialNumbers = initialNumbers + "-" + QString::number(randomNumber);
    }

    int fifthNumberOptions[] = {10, 15, 20};
    int fifthNumber = QRandomGenerator::global()->bounded(3);
    initialNumbers = initialNumbers + "-" + QString::number(fifthNumberOptions[fifthNumber]);

    int sixthNumberOptions[] = {25, 50, 75, 100};
    int sixthNumber = QRandomGenerator::global()->bounded(3);
    initialNumbers = initialNumbers + "-" + QString::number(sixthNumberOptions[sixthNumber]);

    return initialNumbers;
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
        player1->pobednik = true;
        player2->pobednik = false;
        player1->pointsKoZna += 10;
        return 11;
    }
    else if (razlika1 > razlika2)
    {
        // pobednik je 2. igrac jer je blizi resenju
        player1->pobednik = false;
        player2->pobednik = true;
        player2->pointsKoZna += 10;
        return 21;
    }
    else if (razlika1 == razlika2)
    {
        if(player1->podrunda_time > player2->podrunda_time)
        {
            // pobednik je 1. igrac jer je brzi
            player1->pobednik = true;
            player2->pobednik = false;
            player1->pointsKoZna += 10;
            return 12;
        }
        else if(player1->podrunda_time < player2->podrunda_time)
        {
            // pobednik je 2. igrac jer je brzi
            player1->pobednik = false;
            player2->pobednik = true;
            player2->pointsKoZna += 10;
            return 22;
        }
        else
        {
            // nereseno -> oba igraca dobijaju poene
            player1->pobednik = true;
            player2->pobednik = true;
            player1->pointsKoZna += 10;
            player2->pointsKoZna += 10;
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
    else if (msg.startsWith("POGODISTA_END:")) {

    }
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


