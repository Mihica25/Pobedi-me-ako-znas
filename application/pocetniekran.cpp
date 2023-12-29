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

    player1Points = 0;
    player2Points = 0;

    connect(ui->pokreniIgruButton, &QPushButton::clicked, this, &PocetniEkran::on_startGameButton_clicked);
    connect(ui->najboljiRezultatiButton, &QPushButton::clicked, this, &PocetniEkran::on_najboljiRezultatiButton_clicked);

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
        if (connectToServer(playerName)) {
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

void PocetniEkran::on_najboljiRezultatiButton_clicked(){
    if (connectToServer("SEND_BEST_RESULTS")){
        qDebug() << "Uspesno povezivanje sa serverom!";
        connect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyReadBestResults);
    } else {
        qDebug() << "Neuspesna konekcija sa serverom!";
    }
}

// Proveriti sta je upozorenje koje dobijamo prilikom konektovanja na server ->
// QMetaObject::connectSlotsByName: No matching signal for on_startGameButton_clicked()
bool PocetniEkran::connectToServer(QString message)
{
    // Adresa i port servera
    QString serverAddress = "localhost";
    int serverPort = 8000;

    // Kreiranje socket-a za komunikaciju sa serverom
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(serverAddress, serverPort);

    // Provera da li je uspostavljena konekcija
    if (tcpSocket->waitForConnected()) {

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

    recko = new ReckoUI(nullptr, tcpSocket, playerName, opponentName, turn, 0, 0);
    this->close();
    recko->show();
    connect(recko, &ReckoUI::mGameEnds, this, &PocetniEkran::on_reckoEnds, Qt::UniqueConnection);
}

void PocetniEkran::on_reckoEnds(){
    qDebug() << "PocetniEkran::on_reckoEnds()" << endl;
    qDebug() << "Player1: " << recko->getPlayer1Points() << endl;
    qDebug() << "Player2: " << recko->getPlayer2Points() << endl;
    mojbroj= new Mojbroj(nullptr, tcpSocket, playerName, opponentName, turn, recko->getPlayer1Points(), recko->getPlayer2Points());
    recko->close(); //dodato
    mojbroj->show();
    connect(mojbroj, &Mojbroj::mGameEnds, this, &PocetniEkran::on_mojbrojEnds, Qt::UniqueConnection);

    return;
}

void PocetniEkran::on_mojbrojEnds(){
    qDebug() << "PocetniEkran::on_mojbrojEnds()" << endl;
    qDebug() << "Player1: " << mojbroj->getPlayer1Points() << endl;
    qDebug() << "Player2: " << mojbroj->getPlayer2Points() << endl;
    kozna = new KoZnaui(nullptr, tcpSocket, playerName, opponentName, turn, mojbroj->getPlayer1Points(), mojbroj->getPlayer2Points());
    mojbroj->close();
    kozna->show();
    connect(kozna, &KoZnaui::mGameEnds, this, &PocetniEkran::on_koZnaEnds, Qt::UniqueConnection);



    //naredna igra
}

void PocetniEkran::on_koZnaEnds(){
    qDebug() << "PocetniEkran::on_koznaEnds()" << endl;
    qDebug() << "Player1: " << kozna->getPlayer1Points() << endl;
    qDebug() << "Player2: " << kozna->getPlayer2Points() << endl;
    pogodiSta = new PogodiStaUI(nullptr, tcpSocket, playerName, opponentName, turn, 0, kozna->getPlayer1Points(), kozna->getPlayer2Points());
    kozna->close();
    pogodiSta->show();
    connect(pogodiSta, &PogodiStaUI::mGameEnds, this, &PocetniEkran::on_pogodiStaEnds);
}

void PocetniEkran::on_podrundaEnded(){
    return;
}

void PocetniEkran::on_memorijaEnds(){
    qDebug() << "PocetniEkran::on_memorijaEnds()" << endl;
    qDebug() << "Player1: " << memorija->getPlayer1Points() << endl;
    qDebug() << "Player2: " << memorija->getPlayer2Points() << endl;
}



void PocetniEkran::on_pogodiStaEnds()
{
    qDebug() << "PocetniEkran::on_pogodiStaEnds()" << endl;
    qDebug() << "Player1: " << pogodiSta->getPlayer1Points() << endl;
    qDebug() << "Player2: " << pogodiSta->getPlayer2Points() << endl;
    memorija = new Memorija(nullptr, tcpSocket, playerName, opponentName, turn, pogodiSta->getPlayer1Points(), pogodiSta->getPlayer2Points());
    pogodiSta->close();
    memorija->show();
    connect(memorija, &Memorija::mGameEnds, this, &PocetniEkran::on_memorijaEnds);


}

void PocetniEkran::onReadyReadBestResults(){
    QByteArray data = tcpSocket->readAll();
    QString msg = QString::fromUtf8(data);

    qDebug() << msg << endl;
    disconnect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyReadBestResults);
}

