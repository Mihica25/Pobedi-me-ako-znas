#include "koznaui.h"
#include "ui_kozna.h"
#include <cstring>
#include <iostream>
#include <QDebug>




KoZnaui::KoZnaui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KoZnaui),tajmer(new QTimer(this))
{
    ui->setupUi(this);


    QPixmap bkgnd(":/background/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    connect(ui->pushButtonAns1, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns1);
    connect(ui->pushButtonAns2, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns2);
    connect(ui->pushButtonAns3, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns3);
    connect(ui->pushButtonAns4, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns4);

    numberOfQuestion = 0;

    time = 45;
    ui->labelTimer->setText(QString::number(time));

    connect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &KoZnaui::timesUp, this, &KoZnaui::on_timesUp);
    connect(this, &KoZnaui::gameEnds, this, &KoZnaui::on_gameEnds);

    tajmer->start(1000);

    ui->poeni1->setText("0");
    ui->poeni2->setText("0");

    //this->displayQuestion(numberOfQuestion);

}


KoZnaui::KoZnaui(QWidget *parent, QTcpSocket* tcpSocket,
                 QString player11, QString player22, bool red,
                 int player1Points1, int player2Points2):
    QMainWindow(parent),
    ui(new Ui::KoZnaui),
    tajmer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    player1 = player11;
    player2 = player22;
    playerId = red;
    qDebug() << red << endl;
    playerNo = playerId;
    player1Points = player1Points1;
    player2Points = player2Points2;
    ui->setupUi(this);
    ui->poeni1->setText(QString::number(player1Points));
    ui->poeni2->setText(QString::number(player2Points));


    QPixmap bkgnd(":/background/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->label->setText(player1);


    qDebug()<< "SEND" << endl;

    sendMessage(server, "SEND:hhhuhuuhhu\n");
    sendMessage(server, "P1:" + QString::number(player1Points) + "\n");
    sendMessage(server, "P2:" + QString::number(player2Points) + "\n");




    connect(ui->pushButtonAns1, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns1Multiplayer);
    connect(ui->pushButtonAns2, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns2Multiplayer);
    connect(ui->pushButtonAns3, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns3Multiplayer);
    connect(ui->pushButtonAns4, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns4Multiplayer);
    connect(ui->DALJE1, &QPushButton::clicked, this, &KoZnaui::on_DALJE);


    numberOfQuestion = 0;
    time = 45;
    ui->labelTimer->setText(QString::number(time));

    connect(tajmer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &KoZnaui::timesUp, this, &KoZnaui::on_timesUp);
    connect(this, &KoZnaui::gameEnds, this, &KoZnaui::on_gameEnds);

    tajmer->start(1000);

    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    //player1Points = 0;
    //player2Points = 0;

}

int KoZnaui::getPlayer1Points(){
    return player1Points;
}

int KoZnaui::getPlayer2Points(){
    return player2Points;
}
KoZnaui::~KoZnaui()
{
    delete ui;
}


void KoZnaui::displayQuestion(int questionNumber)
{
    time = 45;

    enableUi();
    restartColor();

    ui->labQuestion->setText(pitanja.at(questionNumber).value(0));
    ui->pushButtonAns1->setText(pitanja.at(questionNumber).value(1));
    ui->pushButtonAns2->setText(pitanja.at(questionNumber).value(2));
    ui->pushButtonAns3->setText(pitanja.at(questionNumber).value(3));
    ui->pushButtonAns4->setText(pitanja.at(questionNumber).value(4));
}


void KoZnaui::generisiPitanja(QString pitanje){
    qDebug() << "pitanje" << pitanje;


    QStringList svaPitanja = pitanje.split("/");
    brojPitanja = svaPitanja.size();

    for(const auto&  jednoPitanje : svaPitanja){
        QStringList podeljenoPitanje = jednoPitanje.split("_");
        qDebug() << "pitanje" << podeljenoPitanje.size() << "\n";

        pitanja.append(podeljenoPitanje);
    }
    qDebug() << "pitanje" << pitanja.at(numberOfQuestion).value(0) << "\n";

    disableUi();

    displayQuestion(numberOfQuestion);
}


void KoZnaui::on_pushButtonAns1(){

    disableUi();

    QString answer = ui->pushButtonAns1->text();
    qDebug()<< answer << "\n";
    if (guess(answer)){
        ui->pushButtonAns1->setStyleSheet("background-color: green");
    }
    else {
        ui->pushButtonAns1->setStyleSheet("background-color: red");
        displayAnswer();
    }
    time = 2;
}

void KoZnaui::on_pushButtonAns2(){

    disableUi();

    QString answer = ui->pushButtonAns2->text();
    qDebug()<< answer << "\n";

    if(guess(answer)) {
        ui->pushButtonAns2->setStyleSheet("background-color: green");
    }
    else {
        ui->pushButtonAns2->setStyleSheet("background-color: red");
        displayAnswer();
    }
    time = 2;
}


void KoZnaui::on_pushButtonAns3(){
    disableUi();

    QString answer = ui->pushButtonAns3->text();
    qDebug()<< answer << "\n";
    if (guess(answer)) {
        ui->pushButtonAns3->setStyleSheet("background-color: green");
    }
    else {
        ui->pushButtonAns3->setStyleSheet("background-color: red");
        displayAnswer();
    };
    time = 2;
}


void KoZnaui::on_pushButtonAns4() {

    disableUi();

    QString answer = ui->pushButtonAns4->text();
    qDebug()<< answer << "\n";
    if (guess(answer)){
        ui->pushButtonAns4->setStyleSheet("background-color: green");
    }
    else{
        ui->pushButtonAns4->setStyleSheet("background-color: red");
        displayAnswer();
    };
    //time = 2;
}


void KoZnaui::on_pushButtonAns1Multiplayer(){
    disableUi();

    QString answer = ui->pushButtonAns1->text();
    qDebug()<< answer << "\n";

    if (guess(answer)){
        ui->pushButtonAns1->setStyleSheet("background-color: green");
            sendMessage(server, "ANSWER:true,10,\n");
    }
    else {
        ui->pushButtonAns1->setStyleSheet("background-color: red");
        sendMessage(server, "ANSWER:false,5,\n");
        displayAnswer();
    }
    //time = 2;
}


void KoZnaui::on_pushButtonAns2Multiplayer(){
    disableUi();

    QString answer = ui->pushButtonAns2->text();
    qDebug()<< answer << "\n";
    if (guess(answer)){
        ui->pushButtonAns2->setStyleSheet("background-color: green");
        sendMessage(server, "ANSWER:true,10,\n");
        //sendMessage(server, "POINTS:10\n");
    }
    else{
        ui->pushButtonAns2->setStyleSheet("background-color: red");
        sendMessage(server, "ANSWER:false,5,\n");
        //sendMessage(server, "POINTS:5\n");
        displayAnswer();
    }
    //time = 2;
}


void KoZnaui::on_pushButtonAns3Multiplayer(){
    disableUi();

    QString answer = ui->pushButtonAns3->text();
    qDebug()<< answer << "\n";

    if (guess(answer)){
        ui->pushButtonAns3->setStyleSheet("background-color: green");
        sendMessage(server, "ANSWER:true,10,\n");
    }
    else{
        ui->pushButtonAns3->setStyleSheet("background-color: red");
        sendMessage(server, "ANSWER:false,5,\n");
        displayAnswer();
    }
    //time = 2;
}


void KoZnaui::on_pushButtonAns4Multiplayer(){
    disableUi();

    QString answer = ui->pushButtonAns4->text();
    if (guess(answer)){
        ui->pushButtonAns4->setStyleSheet("background-color: green");
        sendMessage(server, "ANSWER:true,10,\n");
    }
    else{
        ui->pushButtonAns4->setStyleSheet("background-color: red");
        sendMessage(server, "ANSWER:false,5,\n");
        displayAnswer();
     };
    //time = 2;
}


void KoZnaui::on_DALJE(){
    disableUi();

    displayAnswer();
    //QString answer = ui->DALJE1->text();
   // qDebug()<< answer << "\n";
    sendMessage(server, "ANSWER:DALJE,0,\n");
    //sendMessage(server, "POINTS:10\n");
}


bool KoZnaui::guess(QString answer) {
    QString correctAns = getCorrectAnswer();

    if(correctAns == answer){
        return true;
    }
    else {
        return false;
    }
}


void KoZnaui::displayAnswer() {
    QString answer = getCorrectAnswer();

    qDebug()<<answer<<"\n";

    if(ui->pushButtonAns1->text() == answer){
        ui->pushButtonAns1->setStyleSheet("background-color: green");
    }

    if(ui->pushButtonAns2->text() == answer){
        ui->pushButtonAns2->setStyleSheet("background-color: green");
    }
    if(ui->pushButtonAns3->text() == answer){
        ui->pushButtonAns3->setStyleSheet("background-color: green");
    }
    if(ui->pushButtonAns4->text() == answer){
        ui->pushButtonAns4->setStyleSheet("background-color: green");
    }
}


QString KoZnaui::getCorrectAnswer() {
    QString correctAns = pitanja.at(numberOfQuestion).value(5);

    return correctAns;
}


void KoZnaui::on_timesUp() {
    time = 45;
    ui->labelTimer->setText(QString::number(time));
    tajmer->start();
    //qDebug() << "Isteklo vreme";
    displayQuestion(++numberOfQuestion);
}


void KoZnaui::on_gameEnds(){
    tajmer->stop();
    ukupni_bodovi += bodovi;
    //ui->leBodovi->setText(QString::number(ukupni_bodovi));
    //showSolution();
    qDebug() << "Game ends";
    sendMessage(server, "END\n");
}


void KoZnaui::updateTime() {
    if (time >= 0){
        ui->labelTimer->setText(QString::number(time));
    }

    if(time--==0){
        if(numberOfQuestion == 6)
            emit gameEnds();
        else {
            emit timesUp();
        }
    }
}


void KoZnaui::disableUi() {
    ui->pushButtonAns1->setDisabled(true);
    ui->pushButtonAns2->setDisabled(true);
    ui->pushButtonAns3->setDisabled(true);
    ui->pushButtonAns4->setDisabled(true);
    ui->DALJE1->setDisabled(true);


}


void KoZnaui::enableUi() {
    ui->pushButtonAns1->setEnabled(true);
    ui->pushButtonAns2->setEnabled(true);
    ui->pushButtonAns3->setEnabled(true);
    ui->pushButtonAns4->setEnabled(true);
    ui->DALJE1->setEnabled(true);
}


void KoZnaui::restartColor() {
    ui->pushButtonAns1->setStyleSheet("background-color: white");
    ui->pushButtonAns2->setStyleSheet("background-color: white");
    ui->pushButtonAns3->setStyleSheet("background-color: white");
    ui->pushButtonAns4->setStyleSheet("background-color: white");
    ui->poeni1->setStyleSheet("background-color: white");
    ui->poeni2->setStyleSheet("background-color: white");
}

//to da sredim mozda mi ne treba
void KoZnaui::startGame(){
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    tajmer->start(1000);
    if(playerId){
        connect(ui->pushButtonAns1, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns1Multiplayer);
        connect(ui->pushButtonAns2, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns2Multiplayer);
        connect(ui->pushButtonAns3, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns3Multiplayer);
        connect(ui->pushButtonAns4, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns4Multiplayer);
    }
    return;
}


void KoZnaui::processServerMessage(QString serverMessage){
    qDebug()<<"usao u pre pitanje";
    if (serverMessage.startsWith("PITANJE:")) {
        qDebug()<<"usao u pitanje";
        generisiPitanja(serverMessage.mid(8));
    }

    if (serverMessage.startsWith("ANSWERP1:")) {
        if(serverMessage.mid(9) == "true"){
            ui->poeni1->setStyleSheet("background-color: green");

        }
        else if(serverMessage.mid(9) == "false"){
            ui->poeni1->setStyleSheet("background-color: red");
        }
    }

    if (serverMessage.startsWith("ANSWERP22:")) {
        qDebug() <<"poruka o odgovoru" << serverMessage.mid(10);
        if(serverMessage.mid(10) == "true"){
            ui->poeni2->setStyleSheet("background-color: green");

        }
        else{
            ui->poeni2->setStyleSheet("background-color: red");
        }
    }

    if (serverMessage.startsWith("PREBACI")) {
        time = 2;
    }

    if (serverMessage.startsWith("POENI1:")) {
        qDebug() << "usaoo" << endl;
        //poeni11 = serverMessage.mid(7).toInt();
        qDebug()<< "Vrednost po pit"<< numberOfQuestion << serverMessage.mid(7).toInt()<< endl;
        //qDebug() << serverMessage.mid(7) << endl;

        player1Points = serverMessage.mid(7).toInt();
        ui->poeni1->setText(serverMessage.mid(7));
    }

    if (serverMessage.startsWith("POENI2:")) {
        //qDebug() << player2Points << endl;
        qDebug() << "usaoo" << endl;
        qDebug() <<"Vrednosto po pitanjima:" << numberOfQuestion << serverMessage.mid(7).toInt() << endl;
        //qDebug() << po << endl;

        player2Points = serverMessage.mid(7).toInt();
        ui->poeni2->setText(serverMessage.mid(7));
    }

    if (serverMessage.startsWith("PODRUNDA")) {
        time = 20;

        disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        podrunda = new Podrundaui(nullptr, server, player1, player2, player1Points, player2Points);
        podrunda->show();
        connect(podrunda, &Podrundaui::gameEnded, this, &KoZnaui::on_podrundaEnds, Qt::UniqueConnection);
    }
    if(serverMessage.startsWith("END")) {
        disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        emit mGameEnds();
    }
}


void KoZnaui::on_podrundaEnds(){
    qDebug() << "PODRUNDA ENDS\n";
    time = 3;
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    //podrunda->close();

    player1Points = getPlayer1Points();
    player2Points = getPlayer2Points();
    QString poeni_prvog = QString::number(getPlayer1Points());
    QString poeni_drugog = QString::number(getPlayer2Points());
    ui->poeni1->setVisible(true);
    ui->poeni2->setVisible(true);

    QApplication::processEvents();

    ui->poeni1->setText(poeni_prvog);
    ui->poeni2->setText(poeni_drugog);

    qDebug() << "poeni 1 podrunda" << podrunda->getPlayer1Points();
    qDebug() << "poeni 1 kozna" << getPlayer1Points();
    qDebug() << "poeni 2 podrunda" << podrunda->getPlayer2Points();
    qDebug() << "poeni 2 kozna" << player2Points;

    podrunda->~Podrundaui();
    return;
}


void KoZnaui::onReadyRead() {
    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }
    }
}


void KoZnaui::sendMessage(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();
}
