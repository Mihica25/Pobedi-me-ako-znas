#include "pocetniekran.h"
#include "ui_pocetniekran.h"


PocetniEkran::PocetniEkran(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PocetniEkran)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap bkgnd(":/background/resources/start_menu.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    connect(ui->pokreniIgruButton, &QPushButton::clicked, this, &PocetniEkran::on_startGameButton_clicked);

}

PocetniEkran::~PocetniEkran()
{
    delete ui;
}

void PocetniEkran::on_startGameButton_clicked()
{
    // Prikazi CustomDialog za unos imena
    loginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted) {
        playerName = loginDialog.getName();

        // Povezivanje sa serverom
        if (connectToServer()) {
            // Uspesna konekcija
            qDebug() << "Uspesno povezivanje sa serverom!";
            ui->pokreniIgruButton->setText("Ceka se protivnik");
            qDebug() << "Namestili smo tekst";
            connect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyRead);
        } else {
            // Neuspesna konekcija
            qDebug() << "Neuspesna konekcija sa serverom!";
        }
    }
}

// Proveriti sta je upozorenje koje dobijamo prilikom konektovanja na server ->
// QMetaObject::connectSlotsByName: No matching signal for on_startGameButton_clicked()
bool PocetniEkran::connectToServer()
{
    // Adresa i port servera
    QString serverAddress = "localhost";
    int serverPort = 8000;

    // Kreiranje socket-a za komunikaciju sa serverom
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(serverAddress, serverPort);

    // Provera da li je uspostavljena konekcija
    if (tcpSocket->waitForConnected()) {

        QString message = playerName;
        tcpSocket->write(message.toUtf8());
        tcpSocket->flush();

        return true;  // Uspesna konekcija
    } else {
        qDebug() << "Greska, neuspesna konekcija sa serverom!";
        return false;  // Neuspesna konekcija
    }
}

void PocetniEkran::onReadyRead(){
    QByteArray data = tcpSocket->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }
    }
}

void PocetniEkran::processServerMessage(const QString& serverMessage) {
        if (serverMessage.startsWith("OP_NAME:")) {
            opponentName = serverMessage.mid(8);
            qDebug() << "Received opponent name: " << opponentName;
        } else if (serverMessage.startsWith("TURN:")) {
            turn = (serverMessage.mid(5) == "true");
            qDebug() << "Received turn message: " << serverMessage.mid(5);
        } else if (serverMessage.startsWith("START")){
            disconnect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyRead);
            initConntroler();
        }
        else {
            qDebug() << "Unknown server message: " << serverMessage;
        }
}

void PocetniEkran::initConntroler(){
/*
    ReckoUI* recko = new ReckoUI(nullptr, tcpSocket, playerName, opponentName, turn, 0, 0);
    this->close();
    recko->show();
    connect(recko, &ReckoUI::gameEnds, this, &PocetniEkran::on_reckoEnds, Qt::UniqueConnection);
    */
    Podrundaui* podrunda = new Podrundaui(nullptr, tcpSocket, playerName, opponentName, 0, 0);
    this->close();
    podrunda->show();
    connect(podrunda, &Podrundaui::gameEnded, this, &PocetniEkran::on_podrundaEnded, Qt::UniqueConnection);
}

void PocetniEkran::on_reckoEnds(){
    return;
}

void PocetniEkran::on_podrundaEnded(){
    return;
}

