#include "memorija.h"
#include "ui_memorija.h"
#include <QWidget>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QByteArray>
#include <random>
#include <unistd.h>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>

Memorija::Memorija(QWidget *parent, QTcpSocket* tcpSocket,
                 QString firstPlayer, QString secondPlayer, bool red,
                 int firstPlayerPoints, int SecondPlayerPoints):
    QWidget(parent),
    ui(new Ui::Memorija)
{
    server = tcpSocket;
    multiplayer = true;
    player1 = firstPlayer;
    player2 = secondPlayer;
    turn = red;
    playerNo = turn;
    player1Points = firstPlayerPoints;
    player2Points = SecondPlayerPoints;
    ui->setupUi(this);

    if(playerNo){
        ui->lePlayer1->setText(firstPlayer);
        ui->lePlayer2->setText(secondPlayer);
        ui->lcdPoints1->display(player1Points);
        ui->lcdPoints2->display(player2Points);
    }else{
        ui->lePlayer1->setText(secondPlayer);
        ui->lePlayer2->setText(firstPlayer);
        ui->lcdPoints1->display(player1Points);
        ui->lcdPoints2->display(player2Points);
    }

    setUpBackground();

    startMemorija();
}

Memorija::~Memorija()
{

    for(auto& cardWidget : cardIdToWidget){
        if(cardWidget != nullptr){
            delete cardWidget;
        }
    }
    delete ui;
}

int Memorija::getPlayer1Points()
{
    return player1Points;
}


int Memorija::getPlayer2Points()
{
    return player2Points;
}

QString Memorija::getPlayer1() {
    return player1;
}

QString Memorija::getPlayer2() {
    return player2;
}

Ui::Memorija *Memorija::getUi() {
    return ui;
}

void Memorija::setUpBackground(){
    QPixmap background(":background/resources/igra_memorije.png");
    background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void Memorija::startMemorija(){

    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    sendMessage(server, "GENERATE_CARD_IDS\n");
}

void Memorija::initializeGame(QVector<int> &cardIdsVector)
{
    int indeks = 0;

    QGridLayout *gridLayout = ui->gridLayout;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {

            QWidget *placeholder = gridLayout->itemAtPosition(row, col)->widget();

            int cardId = cardIdsVector[indeks];

            CardWidget *cardWidget = new CardWidget(cardId,indeks, placeholder);
            cardWidget->show();

            connect(cardWidget, &CardWidget::clicked, this, &Memorija::onCardClicked);

            if(cardIdToWidget.contains(indeks)){
                delete cardIdToWidget[indeks];
            }

            cardIdToWidget[indeks] = cardWidget;
            indeks++;
        }
    }


    if(!playerNo){
        blockWholeWindow(true);
    }

}

void Memorija::onCardClicked(int idReveal){

    if(!turn){
        return;
    }

    if (turnedCards.size() >= 2 || turnedCards.contains(idReveal)){
        return;
    }

    CardWidget *clickedCard = cardIdToWidget.value(idReveal,nullptr);

    if(!clickedCard){
        return;
    }

    clickedCard->reveal();
    if(playerNo){
        sendMessage(server, "MOVE1:" + QString::number(idReveal) + "\n");
    }else{
        sendMessage(server, "MOVE2:" + QString::number(idReveal) + "\n");
    }


    turnedCards.append(idReveal);

    if(turnedCards.size() == 2){
        if(checkForMatch()){
            ++pairsFound;
            if(playerNo){
                ++player1Points;
                ui->lcdPoints1->display(player1Points);
                sendMessage(server, "POINTS1\n");
            }else{
                ++player2Points;
                ui->lcdPoints2->display(player2Points);
                sendMessage(server,"POINTS2\n");
            }
        }else{
            hideUnmatchedCards();

            if(turn){
                blockWholeWindow(true);
            }else{
                blockWholeWindow(false);
            }

            turn = !turn;

            if(playerNo){
                sendMessage(server, "TURN2");
            }else{
                sendMessage(server,"TURN1");
            }
        }
        resetTurnedCards();

        //if(pairsFound == totalPairs){
        //}

    }

}


void Memorija::opponentsView(int card){
    if (turnedCardsOp.size() >= 2 || turnedCardsOp.contains(card)){
        return;
    }

    CardWidget *clickedCard = cardIdToWidget.value(card,nullptr);

    if(!clickedCard){
        return;
    }

    clickedCard->reveal();

    turnedCardsOp.append(card);

    if(turnedCardsOp.size() == 2){
        if(checkForMatchOp()){
            ++pairsFound;
        }else{
            hideUnmatchedCardsOp();
        }
        turnedCardsOp.clear();

        if(pairsFound == totalPairs){
            sendMessage(server, "MEMORIJA_END:" + QString::number(player1Points) + ":" + QString::number(player2Points) + "\n");
        }
    }
}

void Memorija::hideUnmatchedCards(){

    sleep(1);

    for(int idReveale : turnedCards){
        cardIdToWidget.value(idReveale,nullptr)->hide();
    }
}

void Memorija::hideUnmatchedCardsOp(){

    sleep(1);

    for(int idReveale : turnedCardsOp){
        cardIdToWidget.value(idReveale,nullptr)->hide();
    }
}

bool Memorija::checkForMatch(){
   int card1 =  cardIdToWidget.value(turnedCards[0],nullptr)->getId();
   int card2 = cardIdToWidget.value(turnedCards[1],nullptr)->getId();

   return (card1 == card2);
}

bool Memorija::checkForMatchOp(){
   int card1 =  cardIdToWidget.value(turnedCardsOp[0],nullptr)->getId();
   int card2 = cardIdToWidget.value(turnedCardsOp[1],nullptr)->getId();

   return (card1 == card2);
}

void Memorija::resetTurnedCards(){
    turnedCards.clear();
}

void Memorija::onReadyRead() {

    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);


    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }else {
            //qDebug() << "Nije primio poruku\n";
        }
    }
}

void Memorija::processServerMessage(QString serverMessage){

    if (serverMessage.startsWith("CARD_IDS:")) {
        QString ids = serverMessage.mid(9);

        QStringList stringList = ids.split(",");

        QVector<int> cardIdss;
        for(const QString str : stringList){
            bool convert;
            int value = str.toInt(&convert);
            if(convert){
                cardIdss.append(value);
            } else {
                qDebug() << "Invalid integer:" << str << endl;
            }
        }

        initializeGame(cardIdss);
    } else if (serverMessage.startsWith("UPDATE_POINTS")) {

        if(playerNo){
            ++player2Points;
            ui->lcdPoints2->display(player2Points);
        }else{
            ++player1Points;
            ui->lcdPoints1->display(player1Points);
        }
     } else if(serverMessage.startsWith("TURNCARD:")){
        QString str = serverMessage.mid(9);
        bool convert;
        int value = str.toInt(&convert);
        if(convert){
            opponentsView(value);
        } else {
            qDebug() << "Invalid integer:" << str << endl;
        }
    } else if(serverMessage.startsWith("CHANGETURN")){
        switchTurns(turn);
    } else if (serverMessage.startsWith("MEMORIJA_END")) {
        disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        emit mGameEnds();
    } else {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void Memorija::sendMessage(QTcpSocket* socket, QString msg)
{
    socket->write(msg.toUtf8());
    socket->flush();

}

void Memorija::switchTurns(bool t){

    if(t){
        blockWholeWindow(true);
    }else{
        blockWholeWindow(false);
    }

    turn = !turn;

}

void Memorija::blockWholeWindow(bool block){

    ui->widget_1->setEnabled(!block);
    ui->widget_2->setEnabled(!block);
    ui->widget_3->setEnabled(!block);
    ui->widget_4->setEnabled(!block);
    ui->widget_5->setEnabled(!block);
    ui->widget_6->setEnabled(!block);
    ui->widget_7->setEnabled(!block);
    ui->widget_8->setEnabled(!block);
    ui->widget_9->setEnabled(!block);
    ui->widget_10->setEnabled(!block);
    ui->widget_11->setEnabled(!block);
    ui->widget_12->setEnabled(!block);
    ui->widget_13->setEnabled(!block);
    ui->widget_14->setEnabled(!block);
    ui->widget_15->setEnabled(!block);
    ui->widget_16->setEnabled(!block);
    ui->widget_17->setEnabled(!block);
    ui->widget_18->setEnabled(!block);
    ui->widget_19->setEnabled(!block);
    ui->widget_20->setEnabled(!block);

}


