#include "pocetniekran.h"
#include "ui_pocetniekran.h"

PocetniEkran::PocetniEkran(QWidget *parent) : QMainWindow(parent), ui(new Ui::PocetniEkran)
{
    ui->setupUi(this);
    tcpSocket = nullptr;
    stackedWidget = nullptr;
    QPixmap bkgnd(":/background/resources/start_menu.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    player1Points = 0;
    player2Points = 0;

    opponentName = "";

    connect(ui->pokreniIgruButton, &QPushButton::clicked, this, &PocetniEkran::on_startGameButton_clicked);
    connect(ui->najboljiRezultatiButton, &QPushButton::clicked, this,
            &PocetniEkran::on_najboljiRezultatiButton_clicked);
    connect(ui->toolButton, &QToolButton::clicked, this, &PocetniEkran::on_info);
}

PocetniEkran::~PocetniEkran()
{
    delete tcpSocket;
    delete ui;
}

Ui::PocetniEkran *PocetniEkran::getUi()
{
    return ui;
}

int PocetniEkran::getPlayer1Points()
{
    return player1Points;
}

int PocetniEkran::getPlayer2Points()
{
    return player2Points;
}

void PocetniEkran::on_startGameButton_clicked()
{
    loginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted)
    {
        playerName = loginDialog.getName();

        if (connectToServer(playerName))
        {
            qDebug() << "Uspesno povezivanje sa serverom!";
            ui->pokreniIgruButton->setText("Ceka se protivnik");
            qDebug() << "Namestili smo tekst";
            connect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyRead);
        }
        else
        {
            qDebug() << "Neuspesna konekcija sa serverom!";
        }
    }
}

void PocetniEkran::on_najboljiRezultatiButton_clicked()
{
    if (connectToServer("SEND_BEST_RESULTS"))
    {
        qDebug() << "Uspesno povezivanje sa serverom!";
        connect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyReadBestResults);
    }
    else
    {
        qDebug() << "Neuspesna konekcija sa serverom!";
    }
}

void PocetniEkran::on_info()
{
    il = new InfoLog(this);
    il->show();
}

bool PocetniEkran::connectToServer(QString message)
{
    QString serverAddress = "localhost";
    int serverPort = 8000;

    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(serverAddress, serverPort);

    if (tcpSocket->waitForConnected())
    {

        tcpSocket->write(message.toUtf8());
        tcpSocket->flush();

        return true;
    }
    else
    {
        qDebug() << "Greska, neuspesna konekcija sa serverom!";
        return false;
    }
}

void PocetniEkran::onReadyRead()
{
    QByteArray data = tcpSocket->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString &receivedMessage : receivedMessages)
    {
        if (!receivedMessage.isEmpty())
        {
            processServerMessage(receivedMessage);
        }
    }
}

void PocetniEkran::processServerMessage(const QString &serverMessage)
{
    if (serverMessage.startsWith("OP_NAME:"))
    {
        opponentName = serverMessage.mid(8);
        qDebug() << "Received opponent name: " << opponentName;
    }
    else if (serverMessage.startsWith("TURN:"))
    {
        turn = (serverMessage.mid(5) == "true");
        qDebug() << "Received turn message: " << serverMessage.mid(5);
    }
    else if (serverMessage.startsWith("START"))
    {
        disconnect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyRead);
        initConntroler();
    }
    else
    {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void PocetniEkran::initConntroler()
{

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    recko = new ReckoUI(nullptr, tcpSocket, playerName, opponentName, turn, 0, 0);
    recko->setAutoFillBackground(true);
    stackedWidget->addWidget(recko);
    stackedWidget->removeWidget(this);
    stackedWidget->setCurrentWidget(recko);
    connect(recko, &ReckoUI::mGameEnds, this, &PocetniEkran::on_reckoEnds, Qt::UniqueConnection);
}

void PocetniEkran::on_reckoEnds()
{
    qDebug() << "PocetniEkran::on_reckoEnds()" << endl;
    qDebug() << "Player1: " << recko->getPlayer1Points() << endl;
    qDebug() << "Player2: " << recko->getPlayer2Points() << endl;
    mojbroj = new Mojbroj(nullptr, tcpSocket, playerName, opponentName, turn, recko->getPlayer1Points(),
                          recko->getPlayer2Points());
    mojbroj->setAutoFillBackground(true);
    stackedWidget->addWidget(mojbroj);
    stackedWidget->removeWidget(recko);
    stackedWidget->setCurrentWidget(mojbroj);
    connect(mojbroj, &Mojbroj::mGameEnds, this, &PocetniEkran::on_mojbrojEnds, Qt::UniqueConnection);

    return;
}

void PocetniEkran::on_mojbrojEnds()
{
    qDebug() << "PocetniEkran::on_mojbrojEnds()" << endl;
    qDebug() << "Player1: " << mojbroj->getPlayer1Points() << endl;
    qDebug() << "Player2: " << mojbroj->getPlayer2Points() << endl;
    kozna = new KoZnaui(nullptr, tcpSocket, playerName, opponentName, turn, mojbroj->getPlayer1Points(),
                        mojbroj->getPlayer2Points());
    kozna->setAutoFillBackground(true);
    stackedWidget->addWidget(kozna);
    stackedWidget->removeWidget(mojbroj);
    stackedWidget->setCurrentWidget(mojbroj);
    connect(kozna, &KoZnaui::mGameEnds, this, &PocetniEkran::on_koZnaEnds, Qt::UniqueConnection);
}

void PocetniEkran::on_koZnaEnds()
{
    qDebug() << "PocetniEkran::on_koznaEnds()" << endl;
    qDebug() << "Player1: " << kozna->getPlayer1Points() << endl;
    qDebug() << "Player2: " << kozna->getPlayer2Points() << endl;
    pogodiSta = new PogodiStaUI(nullptr, tcpSocket, playerName, opponentName, turn, 0, kozna->getPlayer1Points(),
                                kozna->getPlayer2Points());
    pogodiSta->setAutoFillBackground(true);
    stackedWidget->addWidget(pogodiSta);
    stackedWidget->removeWidget(kozna);
    stackedWidget->setCurrentWidget(pogodiSta);
    connect(pogodiSta, &PogodiStaUI::mGameEnds, this, &PocetniEkran::on_pogodiStaEnds);
}

void PocetniEkran::on_podrundaEnded()
{
    return;
}

void PocetniEkran::on_memorijaEnds()
{
    qDebug() << "PocetniEkran::on_memorijaEnds()" << endl;
    qDebug() << "Player1: " << memorija->getPlayer1Points() << endl;
    qDebug() << "Player2: " << memorija->getPlayer2Points() << endl;

    stackedWidget->removeWidget(memorija);
    ui->setupUi(this);
    connect(ui->pokreniIgruButton, &QPushButton::clicked, this, &PocetniEkran::on_startGameButton_clicked);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyRead);
}

void PocetniEkran::on_pogodiStaEnds()
{
    qDebug() << "PocetniEkran::on_pogodiStaEnds()" << endl;
    qDebug() << "Player1: " << pogodiSta->getPlayer1Points() << endl;
    qDebug() << "Player2: " << pogodiSta->getPlayer2Points() << endl;
    memorija = new Memorija(nullptr, tcpSocket, playerName, opponentName, turn, pogodiSta->getPlayer1Points(),
                            pogodiSta->getPlayer2Points());
    memorija->setAutoFillBackground(true);
    stackedWidget->addWidget(memorija);
    stackedWidget->removeWidget(pogodiSta);
    stackedWidget->setCurrentWidget(memorija);
    connect(memorija, &Memorija::mGameEnds, this, &PocetniEkran::on_memorijaEnds);
}

void PocetniEkran::onReadyReadBestResults()
{
    QByteArray data = tcpSocket->readAll();
    QString msg = QString::fromUtf8(data);

    resultDialog = new ResultDialog(this);
    resultDialog->showResults(msg);

    qDebug() << msg << endl;
    disconnect(tcpSocket, &QTcpSocket::readyRead, this, &PocetniEkran::onReadyReadBestResults);
}
