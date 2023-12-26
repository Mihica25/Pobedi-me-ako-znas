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
                 QString p1Username, QString p2Username, bool red,
                 int p1Points, int p2Points):
    QMainWindow(parent),
    ui(new Ui::ReckoUI),
    recko(new Recko()),
    tajmer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    player1 = p1Username;
    player2 = p2Username;
    turn = red;
    qDebug() << red << endl;
    playerNo = turn;
    player1Points = p1Points;
    player2Points = p2Points;
    ui->setupUi(this);
    setUpBackground();
    setUpRows();
    time = 60;
    ui->leTimer->setText(QString::number(time));

    startGame();
}

void ReckoUI::startGame(){
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &ReckoUI::timesUp, this, &ReckoUI::on_mTimesUp);
    tajmer->start(1000);
    if(turn){
        connect(ui->pbPotvrdi1 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi1Multiplayer);
        connect(ui->pbPotvrdi2 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi2Multiplayer);
        connect(ui->pbPotvrdi3 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi3Multiplayer);
        connect(ui->pbPotvrdi4 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi4Multiplayer);
        connect(ui->pbPotvrdi5 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi5Multiplayer);
    } else {
        disableRow(0);
    }
    return;
}

void ReckoUI::restartGame(){
    disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    disconnect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    disconnect(this, &ReckoUI::timesUp, this, &ReckoUI::on_mTimesUp);
    time = 60;
    ui->leTimer->setText(QString::number(time));
    if(turn){
        disconnect(ui->pbPotvrdi1 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi1Multiplayer);
        disconnect(ui->pbPotvrdi2 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi2Multiplayer);
        disconnect(ui->pbPotvrdi3 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi3Multiplayer);
        disconnect(ui->pbPotvrdi4 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi4Multiplayer);
        disconnect(ui->pbPotvrdi5 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi5Multiplayer);
        disableRow(0);
    } else {
        disableRow(0, false);
    }
    setUpRows();
    clearAllRows();
    turn = !turn;
    recko->setCurrentRow(1);
    startGame();

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



void ReckoUI::on_pbPotvrdi1Multiplayer(){
    qDebug() << "U onBt1 smo" << endl;
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
}
void ReckoUI::on_pbPotvrdi2Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
}
void ReckoUI::on_pbPotvrdi3Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
}
void ReckoUI::on_pbPotvrdi4Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
}
void ReckoUI::on_pbPotvrdi5Multiplayer(){
    QString word = getWord();
    sendMessage(server, "WORD:" + word.toUtf8() + "\n");
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
    if(index > 4){
        return;
    }
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

void ReckoUI::clearAllRows(){
    for(unsigned i = 0; i < 5; i++){
        clearRow(i);
    }
    clearSolution();
}

void ReckoUI::clearRow(int index){
    QHBoxLayout* Row =
            qobject_cast<QHBoxLayout*>(ui->verticalLayout->
                                       itemAt(index)->
                                       layout()->itemAt(0)->layout());
    for (int j = 0; j < Row->count(); ++j) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(Row->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->clear();
            lineEdit->setStyleSheet("");
        }
    }
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

void ReckoUI::on_mTimesUp()
{
    sendMessage(server, "TIMES_UP\n");
    qDebug() << "Isteklo vreme";
    QTimer::singleShot(3000, this, &ReckoUI::restartGame);
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

void ReckoUI::clearSolution(){
    QHBoxLayout* Row =
            qobject_cast<QHBoxLayout*>(ui->resenje->layout());


    for (int j = 0; j < Row->count(); ++j) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(Row->itemAt(j)->widget());

        if (lineEdit) {
            lineEdit->clear();
            lineEdit->setStyleSheet("");
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
                qDebug() << QString::number(recko->getCurrentRow()) << endl;
                disableRow(recko->getCurrentRow(), false);
            }
            recko->incrementRow();
        }
    } else if (serverMessage.startsWith("POINTS:")) {
        QString pointsString = serverMessage.mid(7);
        bool conversionSuccess = false;
        int points = pointsString.toInt(&conversionSuccess);
        qDebug() << "Current points for player 1: " << player1Points << endl;
        qDebug() << "Current points for player 2: " << player2Points << endl;
        if (conversionSuccess) {
            qDebug() << "Received points: " << points;
            if(turn == playerNo){
                player1Points += points;
            } else {
                player2Points += points;
            }
        }
        qDebug() << "Current points for player 1: " << player1Points << endl;
        qDebug() << "Current points for player 2: " << player2Points << endl;
     } else if(serverMessage.startsWith("OP_WORD:")){
            QString opWord = serverMessage.mid(8);
            writeWord(opWord);

     } else if(serverMessage.startsWith("CORRECT_WORD:")){
            QString opWord = serverMessage.mid(13);
            writeWord(opWord);
    } else if(serverMessage.startsWith("GAME1_ENDED")){
        qDebug() << "First game just ended up :(" << endl;
//        restartGame();
        tajmer->stop();
        QTimer::singleShot(3000, this, &ReckoUI::restartGame);

    } else if("GAME2_ENDED"){
        qDebug() << "Second game just ended up :(" << endl;
        tajmer->stop();
        QTimer::singleShot(3000, this, &ReckoUI::endGame);
    } else {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void ReckoUI::endGame(){
    qDebug() << "Game 2 has ended :(" << endl;
    disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    disconnect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    disconnect(this, &ReckoUI::timesUp, this, &ReckoUI::on_mTimesUp);
    if(turn){
        disconnect(ui->pbPotvrdi1 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi1Multiplayer);
        disconnect(ui->pbPotvrdi2 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi2Multiplayer);
        disconnect(ui->pbPotvrdi3 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi3Multiplayer);
        disconnect(ui->pbPotvrdi4 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi4Multiplayer);
        disconnect(ui->pbPotvrdi5 , &QPushButton::clicked, this, &ReckoUI::on_pbPotvrdi5Multiplayer);
    }
    this->close();
    emit mGameEnds();
}

void ReckoUI::sendMessage(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();

}

int ReckoUI::getPlayer1Points(){
    return player1Points;
}

int ReckoUI::getPlayer2Points(){
    return player2Points;
}
