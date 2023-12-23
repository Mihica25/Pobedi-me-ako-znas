#include "reckoui.h"
#include "ui_reckoui.h"

ReckoUI::ReckoUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReckoUI),
    recko(new Recko()),
    tajmer(new QTimer(this))
{
    ui->setupUi(this);
    setUpBackground();
    setUpRows();
    connect(ui->pbPotvrdi1 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi1);
    connect(ui->pbPotvrdi2 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi2);
    connect(ui->pbPotvrdi3 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi3);
    connect(ui->pbPotvrdi4 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi4);
    connect(ui->pbPotvrdi5 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi5);


    time = 60;
    ui->leTimer->setText(QString::number(time));

    connect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &ReckoUI::timesUp, this, &ReckoUI::on_timesUp);
    connect(this, &ReckoUI::gameEnds, this, &ReckoUI::on_gameEnds);
    tajmer->start(1000);
}

ReckoUI::ReckoUI(QWidget *parent, QTcpSocket* tcpSocket,
                 QString player1, QString player2, bool red,
                 int player1Points, int player2Points):
    QMainWindow(parent),
    ui(new Ui::ReckoUI),
    recko(new Recko()),
    tajmer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    player1 = player1;
    player2 = player2;
    turn = red;
    qDebug() << red << endl;
    playerNo = turn;
    player1Points = player1Points;
    player2Points = player2Points;
    ui->setupUi(this);
    setUpBackground();
    setUpRows();
    time = 60;
    ui->leTimer->setText(QString::number(time));

    connect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &ReckoUI::timesUp, this, &ReckoUI::on_timesUp);
    connect(this, &ReckoUI::gameEnds, this, &ReckoUI::on_gameEnds);
//    this->show();
    startGame();
}

void ReckoUI::startGame(){
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    tajmer->start(1000);
    if(turn){
        connect(ui->pbPotvrdi1 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi1Multiplayer);
        connect(ui->pbPotvrdi2 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi2Multiplayer);
        connect(ui->pbPotvrdi3 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi3Multiplayer);
        connect(ui->pbPotvrdi4 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi4Multiplayer);
        connect(ui->pbPotvrdi5 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi5Multiplayer);
    } else {
        disableRow(0);
//        connect(server, &QTcpSocket::readyRead, this, &ReckoUI::waitMyTurn);
//        waitMyTurn();
    }
    return;
}

ReckoUI::~ReckoUI()
{
    delete ui;
}

void ReckoUI::setUpBackground(){
    QPixmap background(":background/resources/recko.png");
    background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void ReckoUI::waitMyTurn(){
//    disconnect(server, &QTcpSocket::readyRead, this, &ReckoUI::waitMyTurn);
    if(server->waitForReadyRead(60000)){
        QString result = QString::fromUtf8(server->readAll());
        qDebug() << "Client received: " << result << endl;
        if(result == "GGGGG"){
            if(server->waitForReadyRead(10000)){
                QByteArray rawData = server->readAll();
                int points;
                QDataStream stream(rawData);
                stream >> points;
                if(playerNo){
                    player1Points += points;
                } else {
                    player2Points += points;
                }
            }
            colorRow(result);
            return;
        } else {
            colorRow(result);
        }
    }
    if(server->waitForReadyRead(60000)){
        QString result = QString::fromUtf8(server->readAll());
        qDebug() << "Client received: " << result << endl;
        if(result == "GGGGG"){
            if(server->waitForReadyRead(10000)){
                QByteArray rawData = server->readAll();
                int points;
                QDataStream stream(rawData);
                stream >> points;
                if(playerNo){
                    player1Points += points;
                } else {
                    player2Points += points;
                }
            }
            colorRow(result);
            return;
        } else {
            colorRow(result);
        }
    }
    if(server->waitForReadyRead(60000)){
        QString result = QString::fromUtf8(server->readAll());
        qDebug() << "Client received: " << result << endl;
        if(result == "GGGGG"){
            if(server->waitForReadyRead(10000)){
                QByteArray rawData = server->readAll();
                int points;
                QDataStream stream(rawData);
                stream >> points;
                if(playerNo){
                    player1Points += points;
                } else {
                    player2Points += points;
                }
            }
            colorRow(result);
            return;
        } else {
            colorRow(result);
        }
    }
    if(server->waitForReadyRead(60000)){
        QString result = QString::fromUtf8(server->readAll());
        qDebug() << "Client received: " << result << endl;
        if(result == "GGGGG"){
            if(server->waitForReadyRead(10000)){
                QByteArray rawData = server->readAll();
                int points;
                QDataStream stream(rawData);
                stream >> points;
                if(playerNo){
                    player1Points += points;
                } else {
                    player2Points += points;
                }
            }
            colorRow(result);
            return;
        } else {
            colorRow(result);
        }
    }
    if(server->waitForReadyRead(60000)){
        QString result = QString::fromUtf8(server->readAll());
        qDebug() << "Client received: " << result << endl;
        if(result == "GGGGG"){
            if(server->waitForReadyRead(10000)){
                QByteArray rawData = server->readAll();
                int points;
                QDataStream stream(rawData);
                stream >> points;
                if(playerNo){
                    player1Points += points;
                } else {
                    player2Points += points;
                }
            }
            colorRow(result);
            return;
        } else {
            colorRow(result);
        }
    }
}

void ReckoUI::on_pbPotvrdi1Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
//    if(server->waitForReadyRead(10000)){
//        QString result = QString::fromUtf8(server->readAll());
//        qDebug() << "Client received: " << result << endl;
//        if(result == "GGGGG"){
//            if(server->waitForReadyRead(10000)){
//                QByteArray rawData = server->readAll();
//                int points;
//                QDataStream stream(rawData);
//                stream >> points;
//                if(playerNo){
//                    player1Points += points;
//                } else {
//                    player2Points += points;
//                }
//            }
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);

//        } else {
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);
//            disableRow(recko->getCurrentRow(), false);
//            recko->incrementRow();
//        }
//    }
}
void ReckoUI::on_pbPotvrdi2Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
//    if(server->waitForReadyRead(10000)){
//        QString result = QString::fromUtf8(server->readAll());
//        qDebug() << "Client received: " << result << endl;
//        if(result == "GGGGG"){
//            if(server->waitForReadyRead(10000)){
//                QByteArray rawData = server->readAll();
//                int points;
//                QDataStream stream(rawData);
//                stream >> points;
//                if(playerNo){
//                    player1Points += points;
//                } else {
//                    player2Points += points;
//                }
//            }
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);

//        } else {
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);
//            disableRow(recko->getCurrentRow(), false);
//            recko->incrementRow();
//        }
//    }
}
void ReckoUI::on_pbPotvrdi3Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
//    if(server->waitForReadyRead(10000)){
//        QString result = QString::fromUtf8(server->readAll());
//        qDebug() << "Client received: " << result << endl;
//        if(result == "GGGGG"){
//            if(server->waitForReadyRead(10000)){
//                QByteArray rawData = server->readAll();
//                int points;
//                QDataStream stream(rawData);
//                stream >> points;
//                if(playerNo){
//                    player1Points += points;
//                } else {
//                    player2Points += points;
//                }
//            }
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);

//        } else {
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);
//            disableRow(recko->getCurrentRow(), false);
//            recko->incrementRow();
//        }
//    }
}
void ReckoUI::on_pbPotvrdi4Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
//    if(server->waitForReadyRead(10000)){
//        QString result = QString::fromUtf8(server->readAll());
//        qDebug() << "Client received: " << result << endl;
//        if(result == "GGGGG"){
//            if(server->waitForReadyRead(10000)){
//                QByteArray rawData = server->readAll();
//                int points;
//                QDataStream stream(rawData);
//                stream >> points;
//                if(playerNo){
//                    player1Points += points;
//                } else {
//                    player2Points += points;
//                }
//            }
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);

//        } else {
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);
//            disableRow(recko->getCurrentRow(), false);
//            recko->incrementRow();
//        }
//    }
}
void ReckoUI::on_pbPotvrdi5Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
//    if(server->waitForReadyRead(10000)){
//        QString result = QString::fromUtf8(server->readAll());
//        qDebug() << "Client received: " << result << endl;
//        if(result == "GGGGG"){
//            if(server->waitForReadyRead(10000)){
//                QByteArray rawData = server->readAll();
//                int points;
//                QDataStream stream(rawData);
//                stream >> points;
//                if(playerNo){
//                    player1Points += points;
//                } else {
//                    player2Points += points;
//                }
//            }
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);

//        } else {
//            colorRow(result);
//            disableRow(recko->getCurrentRow() - 1);
////            disableRow(recko->getCurrentRow(), false);
////            recko->incrementRow();
//        }
//    }
}

void ReckoUI::on_pbPotvrdi1(){
    if (quess()){
        disableRow(recko->getCurrentRow() - 1);
        bodovi = 12;
        emit gameEnds();
        return;
    }
    else{
        disableRow(recko->getCurrentRow() - 1);
        disableRow(recko->getCurrentRow(), false);
        recko->incrementRow();
    };
}
void ReckoUI::on_pbPotvrdi2(){
    if (quess()){
        disableRow(recko->getCurrentRow() - 1);
        bodovi = 10;
        emit gameEnds();
        return;
    }
    else{
        disableRow(recko->getCurrentRow() - 1);
        disableRow(recko->getCurrentRow(), false);
        recko->incrementRow();
    };
}
void ReckoUI::on_pbPotvrdi3(){
    if (quess()){
        disableRow(recko->getCurrentRow() - 1);
        bodovi = 8;
        emit gameEnds();
        return;
    }
    else{
        disableRow(recko->getCurrentRow() - 1);
        disableRow(recko->getCurrentRow(), false);
        recko->incrementRow();
    };
}
void ReckoUI::on_pbPotvrdi4(){
    if (quess()){
        disableRow(recko->getCurrentRow() - 1);
        bodovi = 6;
        emit gameEnds();
        return;
    }
    else{
        disableRow(recko->getCurrentRow() - 1);
        disableRow(recko->getCurrentRow(), false);
        recko->incrementRow();
    };
}
void ReckoUI::on_pbPotvrdi5(){
    if (quess()){
        disableRow(recko->getCurrentRow() - 1);
        bodovi = 4;
        emit gameEnds();
        return;
    }
    else{
        disableRow(recko->getCurrentRow() - 1);
//        disableRow(recko->getCurrentRow(), false);
//        recko->incrementRow();
        bodovi = 0;
        emit gameEnds();
    };
}

bool ReckoUI::quess(){
    QHBoxLayout* horizontalLayout =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(recko->getCurrentRow() - 1)->
                                       layout()->itemAt(0)->layout());

    int hits = 0;
    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());

        if (lineEdit) {
            QString userInput = lineEdit->text();

            if(userInput.compare(recko->wordle.at(j), Qt::CaseInsensitive) == 0){
                lineEdit->setStyleSheet("background-color: green;");
                hits++;
            }
            else if (recko->wordle.contains(userInput.toUpper())) {
                lineEdit->setStyleSheet("background-color: yellow;");
            }
        }
    }

    if (hits == 5){
        return true;
    }
    return false;
}

void ReckoUI::colorRow(QString result){
    QHBoxLayout* horizontalLayout =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(recko->getCurrentRow() - 1)->
                                       layout()->itemAt(0)->layout());

    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());

        if (lineEdit) {
            if(result.at(j) == "G"){
                lineEdit->setStyleSheet("background-color: green;");
            } else if(result.at(j) == "Y"){
                lineEdit->setStyleSheet("background-color: yellow;");
            }
        }
    }
}

void ReckoUI::writeWord(QString word){
    QHBoxLayout* horizontalLayout =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(recko->getCurrentRow() - 1)->
                                       layout()->itemAt(0)->layout());

    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->setText(word.at(j));
        }
    }
}

QString ReckoUI::getWord(){
    QHBoxLayout* horizontalLayout =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(recko->getCurrentRow() - 1)->
                                       layout()->itemAt(0)->layout());
    QString word = "";
    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());

        if (lineEdit) {
            QString userInput = lineEdit->text();
            word.append(userInput);
        }
    }
    qDebug() << word << endl;
    return word.toUpper();
}

void ReckoUI::disableRow(int index, bool disable){
    QHBoxLayout* Row =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(index)->
                                       layout()->itemAt(0)->layout());
    QPushButton* Button =
            qobject_cast<QPushButton*>(ui->verticalLayout->
                                       itemAt(index)->
                                       layout()->itemAt(1)->widget());

    for (int j = 0; j < Row->count(); ++j) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(Row->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->setDisabled(disable);
        }
    }

    Button->setDisabled(disable);
}
void ReckoUI::setUpRows(){

    for(unsigned i = 1; i < 5; i++){
        disableRow(i);
    }
    disableSolution();
}
void ReckoUI::updateTime()
{
    if (time >= 0){
        ui->leTimer->setText(QString::number(time));
    }

    if(time--==0){
        emit timesUp();
    }


}
void ReckoUI::on_timesUp()
{
    bodovi = 0;
    qDebug() << "Isteklo vreme";
    emit gameEnds();
}
void ReckoUI::on_gameEnds(){
    tajmer->stop();
    ukupni_bodovi += bodovi;
    ui->leBodovi->setText(QString::number(ukupni_bodovi));
    showSolution();
    qDebug() << "Game ends";

}
void ReckoUI::disableSolution(){
    QHBoxLayout* Row =
            qobject_cast<QHBoxLayout*>(ui->resenje->layout());


    for (int j = 0; j < Row->count(); ++j) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(Row->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->setDisabled(true);
        }
    }

}
void ReckoUI::showSolution(){
    QHBoxLayout* Row =
            qobject_cast<QHBoxLayout*>(ui->resenje->layout());
    for (int j = 0; j < Row->count(); ++j) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(Row->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->setDisabled(false);
            lineEdit->setText(recko->wordle.at(j));
            lineEdit->setDisabled(true);
        }
    }

}

void ReckoUI::onReadyRead() {
    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }
    }
}

void ReckoUI::processServerMessage(QString serverMessage){
    if (serverMessage.startsWith("RESULT:")) {
        QString result = serverMessage.mid(7);
        qDebug() << "Received result: " << result;
        colorRow(result);
        disableRow(recko->getCurrentRow() - 1);
        if(result != "GGGGG"){
            if(turn){
                disableRow(recko->getCurrentRow(), false);
            }
            recko->incrementRow();
        }
    } else if (serverMessage.startsWith("POINTS:")) {
        QString pointsString = serverMessage.mid(7);
        bool conversionSuccess = false;
        int points = pointsString.toInt(&conversionSuccess);

        if (conversionSuccess) {
            qDebug() << "Received points: " << points;
            if(turn){
                player1Points += points;
            } else {
                player2Points += points;
            }
        }
     } else if(serverMessage.startsWith("OP_WORD:")){
            QString opWord = serverMessage.mid(8);
            writeWord(opWord);

     } else {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void ReckoUI::sendMessage(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();

}


