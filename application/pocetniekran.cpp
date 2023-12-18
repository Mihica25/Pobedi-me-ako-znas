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
            initConntroler();
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

void PocetniEkran::initConntroler(){
//    if (tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState){
//        qDebug() << "Dobar je soket";
//    }
////    tcpSocket->waitForReadyRead(-1);
////    opponentName = QString::fromUtf8(tcpSocket->readAll());
////    tcpSocket->waitForReadyRead(-1);
////    turn = (QString::fromUtf8(tcpSocket->readAll()) == "true");

    ReckoUI* recko = new ReckoUI(nullptr, tcpSocket, playerName, opponentName, "true", 0, 0);
    this->close();
    recko->show();
    connect(recko, &ReckoUI::gameEnds, this, &PocetniEkran::on_reckoEnds, Qt::UniqueConnection);
}

void PocetniEkran::on_reckoEnds(){
    return;
}
