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
        QString playerName = loginDialog.getName();

        // Povezivanje sa serverom
        if (connectToServer(playerName)) {
            // Uspesna konekcija
            qDebug() << "Uspesno povezivanje sa serverom!";
        } else {
            // Neuspesna konekcija
            qDebug() << "Neuspesna konekcija sa serverom!";
        }
    }
}

// Proveriti sta je upozorenje koje dobijamo prilikom konektovanja na server ->
// QMetaObject::connectSlotsByName: No matching signal for on_startGameButton_clicked()
bool PocetniEkran::connectToServer(const QString &playerName)
{
    // Adresa i port servera
    QString serverAddress = "localhost";
    int serverPort = 8000;

    // Kreiranje socket-a za komunikaciju sa serverom
    QTcpSocket tcpSocket;
    tcpSocket.connectToHost(serverAddress, serverPort);

    // Provera da li je uspostavljena konekcija
    if (tcpSocket.waitForConnected()) {

    // Nisam napisao logiku sa serverske strane koja bi trebalo da prihvati ime igraca
    // i kreira instancu klase Player. U klasi Player trebam dodati polje player_name i
    // izbrisati logiku sa player_id (ili mozda ne, moramo razmisliti da li nam je potreban)
//        QString message = playerName;
//        tcpSocket.write(message.toUtf8());
//        tcpSocket.flush();

        return true;  // Uspesna konekcija
    } else {
        qDebug() << "Greska, neuspesna konekcija sa serverom!";
        return false;  // Neuspesna konekcija
    }
}
