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






    this->displayQuestion(numberOfQuestion);





}


KoZnaui::KoZnaui(QWidget *parent, QTcpSocket* tcpSocket,
                 QString player1, QString player2, bool red,
                 int player1Points, int player2Points):
    QMainWindow(parent),
    ui(new Ui::KoZnaui),
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

}

KoZnaui::~KoZnaui()
{
    delete ui;
}


QVector<QString> KoZnaui::getQuestion(int numberOfQuestion)
{
    QVector<QVector<QString>> questions;
    QVector<QString> question1;
    question1 << "Koji mesece ima tacno 28 dana?" << "Janaur" << "Februar" << "Mart" << "April" << "Februar";
    questions.append(question1);
    QVector<QString> question2;
    question2 << "Neutralna boja?" << "Bela" << "Plava" << "Crvena" << "Zelena" << "Bela";
    questions.append(question2);
    QVector<QString> question3;
    question3 << "Ko je rekorder evrolige po broju asistencija?" << "Markus Vilijams" << "Stefan Jovic" << "Milos Teodosic" << "Nik Kalates" << "Stefan Jovic";
    questions.append(question3);




    return  questions[numberOfQuestion];
}



void KoZnaui::displayQuestion(int questionNumber)
{
    enableUi();
    restartColor();

    QVector<QString> questions = this->getQuestion(questionNumber);




    ui->labQuestion->setText(questions[0]);
    ui->pushButtonAns1->setText(questions[1]);
    ui->pushButtonAns2->setText(questions[2]);
    ui->pushButtonAns3->setText(questions[3]);
    ui->pushButtonAns4->setText(questions[4]);



 }


void KoZnaui::on_pushButtonAns1(){

    disableUi();

    QString answer = ui->pushButtonAns1->text();
    if (guess(answer)){
        ui->pushButtonAns1->setStyleSheet("background-color: green");
      }
    else{
        ui->pushButtonAns1->setStyleSheet("background-color: red");
        displayAnswer();
       };
    time = 2;
}

void KoZnaui::on_pushButtonAns2(){

    disableUi();

    QString answer = ui->pushButtonAns2->text();
    if (guess(answer)){
        ui->pushButtonAns2->setStyleSheet("background-color: green");
      }
    else{
        ui->pushButtonAns2->setStyleSheet("background-color: red");
        displayAnswer();
       };
    time = 2;
}

void KoZnaui::on_pushButtonAns3(){
    disableUi();

    QString answer = ui->pushButtonAns3->text();
    if (guess(answer)){
        ui->pushButtonAns3->setStyleSheet("background-color: green");
      }
    else{
        ui->pushButtonAns3->setStyleSheet("background-color: red");
        displayAnswer();
       };
    time = 2;
}

void KoZnaui::on_pushButtonAns4(){

    disableUi();

    QString answer = ui->pushButtonAns4->text();
    if (guess(answer)){
        ui->pushButtonAns4->setStyleSheet("background-color: green");


      }
    else{
        ui->pushButtonAns4->setStyleSheet("background-color: red");
        displayAnswer();
       };
    time = 2;




}

bool KoZnaui::guess(QString answer)
{
    QString correctAns = this->getCorrectAnswer();

    if(correctAns == answer){
        return true;
    }
    else {
        return false;

    }

  }







void KoZnaui::displayAnswer()
{
    QString answer = getCorrectAnswer();

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


QString KoZnaui::getCorrectAnswer()
{
    QVector<QString> questions = this->getQuestion(numberOfQuestion);
    QString correctAns = questions[5];

    return correctAns;

}



void KoZnaui::on_timesUp()
{
    time = 45;
    ui->labelTimer->setText(QString::number(time));
    tajmer->start();
    //qDebug() << "Isteklo vreme";
    this->displayQuestion(++this->numberOfQuestion);
}

void KoZnaui::on_gameEnds(){
    tajmer->stop();
    ukupni_bodovi += bodovi;
    //ui->leBodovi->setText(QString::number(ukupni_bodovi));
    //showSolution();
    qDebug() << "Game ends";

}


void KoZnaui::updateTime()
{
    if (time >= 0){
        ui->labelTimer->setText(QString::number(time));
    }

    if(time--==0){
        if(numberOfQuestion == 2)
            emit gameEnds();
        else {

            emit timesUp();

        }

    }
}


void KoZnaui::disableUi()
{
    ui->pushButtonAns1->setDisabled(true);
    ui->pushButtonAns2->setDisabled(true);
    ui->pushButtonAns3->setDisabled(true);
    ui->pushButtonAns4->setDisabled(true);

}


void KoZnaui::enableUi()
{
    ui->pushButtonAns1->setEnabled(true);
    ui->pushButtonAns2->setEnabled(true);
    ui->pushButtonAns3->setEnabled(true);
    ui->pushButtonAns4->setEnabled(true);


}

void KoZnaui::restartColor()
{
    ui->pushButtonAns1->setStyleSheet("background-color: white");
    ui->pushButtonAns2->setStyleSheet("background-color: white");
    ui->pushButtonAns3->setStyleSheet("background-color: white");
    ui->pushButtonAns4->setStyleSheet("background-color: white");


}



void KoZnaui::startGame(){
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    tajmer->start(1000);
    if(turn){
        connect(ui->pushButtonAns1, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns1);
        connect(ui->pushButtonAns2, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns2);
        connect(ui->pushButtonAns3, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns3);
        connect(ui->pushButtonAns4, &QPushButton::clicked, this, &KoZnaui::on_pushButtonAns4);
    }


    return;
}


void KoZnaui::processServerMessage(QString serverMessage){
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













    




