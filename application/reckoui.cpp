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
    sendMessage(server, "Radi li soket :)");
    tajmer->start(1000);
}

ReckoUI::ReckoUI(QWidget *parent, QTcpSocket* tcpSocket,
                 QString player1, QString player2, bool turn,
                 int player1Points, int player2Points):
    QMainWindow(parent),
    ui(new Ui::ReckoUI),
    tajmer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    player1 = player1;
    player2 = player2;
    turn = turn;
    player1Points = player1Points;
    player2Points = player2Points;
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
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
    QString message = QString::fromUtf8(data);

    // Razlikovanje poruka na osnovu prefiksa
    if (message.startsWith("TURN:")) {
        QString turnMessage = message.mid(5);
        turn = (turnMessage == "true");
        qDebug() << turnMessage << endl;
    } else if (message.startsWith("OPPONENT USERNAME:")) {
        QString opponentUsernameMessage = message.mid(19);
        player2 = opponentUsernameMessage;
        qDebug() << player2 << endl;
    } else if (message.startsWith("ADD POINTS TO PLAYER1:")) {
        // Obrada poruke sa prefiksom "ADD POINTS TO PLAYER1:"
        QString addPointsToPlayer1Message = message.mid(23);  // Uzimanje dela poruke nakon prefiksa
        player1Points += addPointsToPlayer1Message.toInt();
        // Dalja obrada poruke "ADD POINTS TO PLAYER1:"
    } else if (message.startsWith("ADD POINTS TO PLAYER2:")) {
        // Obrada poruke sa prefiksom "ADD POINTS TO PLAYER2:"
        QString addPointsToPlayer2Message = message.mid(23);  // Uzimanje dela poruke nakon prefiksa
        player2Points += addPointsToPlayer2Message.toInt();
        // Dalja obrada poruke "ADD POINTS TO PLAYER2:"
    } else {
        return;
    }
}

void ReckoUI::sendMessage(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();

}
