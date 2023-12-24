#include "session.h"
#include <thread>
#include <chrono>


Session::Session(Player *player1, Player *player2, QObject *parent) : QObject(parent), player1(player1), player2(player2)
{
//    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyRead);
//    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyRead);

    recko = "HOUSE";

    //generator brojeva

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

    startMojBroj();


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

//isto ovako
void Session::startMojBroj(){
    connect(player1->tcpSocket, &QTcpSocket::readyRead, this, &Session::player1ReadyReadMojBroj);
    connect(player2->tcpSocket, &QTcpSocket::readyRead, this, &Session::player2ReadyReadMojBroj);
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

//isto ovakve

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

        checkMojBrojSolution(player1_res,player2_res);
    }
}

void Session::checkMojBrojSolution(const QString& pt1, const QString& pt2)
{
    if (pt1 == "" || pt2 == "")
        return;

    int res1 = pt1.toInt();
    int res2 = pt2.toInt();
    int res  = targetNumber.toInt();
    qDebug() << pt1 << pt2 << targetNumber;

    if (qAbs(res-res1) < qAbs(res-res2))
    {
        sendMessageToPlayer1("POINTS:10%0");
        sendMessageToPlayer2("POINTS:0%10");
    } else if (qAbs(res-res1) > qAbs(res-res2))
    {
        sendMessageToPlayer1("POINTS:0%10");
        sendMessageToPlayer2("POINTS:10%0");
    } else {
        //obraditi preko turn-a
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
