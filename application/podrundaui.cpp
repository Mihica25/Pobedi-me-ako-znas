#include "podrundaui.h"
#include "ui_podrundaui.h"
#include "podrunda.h"
#include <QDebug>

Podrundaui::Podrundaui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Podrundaui)
{
    getUi()->setupUi(this);
    setBackground();

    Podrunda podrunda;

    connect(getUi()->pbOdgovori , &QPushButton::clicked, this, &Podrundaui::on_pbOdgovori);

    timer = new QTimer(this);
    time = 20;
    getUi()->labTimer->setText(QString::number(time));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &Podrundaui::timesUp, this, &Podrundaui::on_timesUp);
    connect(this, &Podrundaui::gameEnded, this, &Podrundaui::on_gameEnded);


    timer->start(1000);
    this->getQuestion();
}

Podrundaui::Podrundaui(QWidget *parent, QTcpSocket* tcpSocket,
                 QString playerr1, QString playerr2,
                 int playerr1Points, int playerr2Points):
    QWidget(parent),
    ui(new Ui::Podrundaui),
    podrunda(new Podrunda()),
    timer(new QTimer(this))
{

    server = tcpSocket;
    multiplayer = true;
    player1 = playerr1;
    player2 = playerr2;

    player1Points = playerr1Points;
    player2Points = playerr2Points;
    getUi()->setupUi(this);
    setBackground();
    time = 20;
    getUi()->labTimer->setText(QString::number(time));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &Podrundaui::timesUp, this, &Podrundaui::on_timesUp);
    connect(this, &Podrundaui::gameEnded, this, &Podrundaui::on_gameEnded);

    //resetGame();

    getUi()->label->setText(player1);

    podrunda->guess = -1;

    startGame();
}


void Podrundaui::startGame()
{
    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    timer->start(1000);

    connect(getUi()->pbOdgovori , &QPushButton::clicked, this, &Podrundaui::on_pbOdgovoriMultiplayer);

    this->getQuestion();

    return;
}

int Podrundaui::getTime()
{
    return time;
}

QString Podrundaui::getPlayer1()
{
    return player1;
}


QString Podrundaui::getPlayer2()
{
    return player2;
}


void Podrundaui::setPlayer1(QString playerr1)
{
    player1 = playerr1;
}


void Podrundaui::setPlayer2(QString playerr2)
{
    player2 = playerr2;
}


int Podrundaui::getPlayer1Points()
{
    return player1Points;
}


int Podrundaui::getPlayer2Points()
{
    return player2Points;
}


void Podrundaui::setPlayer1Points(int playerr1Points)
{
    player1Points = playerr1Points;
}


void Podrundaui::setPlayer2Points(int playerr2Points)
{
    player2Points = playerr2Points;
}


void Podrundaui::resetGame()
{
    qDebug() << "udje u reset game\n";
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    disconnect(this, &Podrundaui::timesUp, this, &Podrundaui::on_timesUp);
    disconnect(this, &Podrundaui::gameEnded, this, &Podrundaui::on_gameEnded);

    //time = 60;
    getUi()->labTimer->clear();

    //timer->stop();
    getUi()->labTacanOdgovor->clear();
    enableUI();
}


Podrundaui::~Podrundaui()
{
    delete ui;
    delete podrunda;
    delete timer;
}


Ui::Podrundaui *Podrundaui::getUi()
{
    return ui;
}


void Podrundaui::setBackground()
{
    getUi()->setupUi(this);
    QPixmap bkgnd(":background/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


void Podrundaui::on_pbOdgovori()
{
    disableUI();
    displayAnswer();
}


void Podrundaui::on_pbOdgovoriMultiplayer()
{
    getGuess();
    QString pokusaj = QString::number(podrunda->guess);
    notifyServer(server, "ANSWER:" + pokusaj.toUtf8() + "\n");

    QString vreme = QString::number(time);
    notifyServer(server, "TIME:" + vreme.toUtf8() + "\n");

    //timer->stop();
    getUi()->labTimer->clear();

    adjustResultLabel();
    disableUI();
}


void Podrundaui::getQuestion()
{
    /*
    podrunda->setAnswerQuestion("Koliko slova ima azbuka?", 30);
    QString resenje = "30";
    */
    /*
    QString resenje = QString::number(podrunda->getAnswerQuestion().second);
    notifyServer(server, "RESENJE:" + resenje.toUtf8() + "\n");
    displayQuestion();
    */
    notifyServer(server, "PITANJE!\n");
}


void Podrundaui::displayQuestion()
{
    enableUI();
    const QString pitanje = podrunda->getAnswerQuestion().first;
    const QString resenje = QString::number(podrunda->getAnswerQuestion().second);
    getUi()->labPitanje->setText(pitanje);
    getUi()->labPitanje->setAlignment(Qt::AlignCenter);
    //getUi()->labPitanje->setStyleSheet("background-color::yellow;");

    //qDebug() << "Sending resenje: " << resenje;
    notifyServer(server, "RESENJE:" + resenje.toUtf8() + "\n");
}


void Podrundaui::displayAnswer()
{
    if(isNumberGuessed())
    {
        const QString tacno = "Bravo, odgovorili ste tacno!";
        getUi()->labTacanOdgovor->setText(tacno);
        getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
        getUi()->labTacanOdgovor->setStyleSheet("background-color:green");

    }
    else
    {
        double correctAnswer = podrunda->getAnswerQuestion().second;
        double absDiff = qAbs(correctAnswer - podrunda->guess);
        QString razlika = QString::number(absDiff);
        const QString netacno = "Nazalost, pogresili ste za " + razlika + "!";
        getUi()->labTacanOdgovor->setText(netacno);
        getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
        getUi()->labTacanOdgovor->setStyleSheet("background-color:red");

    }

    timer->stop();
    getUi()->labTimer->clear();

    adjustResultLabel();
    disableUI();
}


void Podrundaui::disableUI()
{
    getUi()->pbOdgovori->setDisabled(true);
    getUi()->teOdgovor->setDisabled(true);
}


void Podrundaui::enableUI()
{
    getUi()->pbOdgovori->setEnabled(true);
    getUi()->teOdgovor->setEnabled(true);
    getUi()->teOdgovor->setAlignment(Qt::AlignCenter);
}


void Podrundaui::notifyServer(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();
}


void Podrundaui::getGuess()
{
    podrunda->guess = getUi()->teOdgovor->toPlainText().toDouble();
    //timer->stop();
}


bool Podrundaui::isNumberGuessed()
{
    getGuess();
    double correctAnswer = podrunda->getAnswerQuestion().second;
    if (podrunda->guess == correctAnswer)
        return true;
    else
        return false;
}


void Podrundaui::updateTime()
{
    if (time >= 0)
    {
        getUi()->labTimer->setAlignment(Qt::AlignCenter);
        getUi()->labTimer->setText(QString::number(time));
    }

    if(--time == 0){
        emit timesUp();
    }
}


void Podrundaui::on_timesUp()
{
    if (podrunda->guess == -1)
    {
        QString pokusaj = QString::number(-2);
        notifyServer(server, "ANSWER:" + pokusaj.toUtf8() + "\n");

        QString vreme = QString::number(0);
        notifyServer(server, "TIME:" + vreme.toUtf8() + "\n");
    }

    emit gameEnded();
}


void Podrundaui::on_gameEnded(){
    timer->stop();

    QString nula = "0";
    getUi()->labTimer->setAlignment(Qt::AlignCenter);
    getUi()->labTimer->setText(nula);
    getUi()->labTimer->setStyleSheet("background-color:red");

    double numAnswer = podrunda->getAnswerQuestion().second;
    QString correctAnswer = QString::number(numAnswer);
    const QString poruka = "Niste odgovorili na pitanje! Tacan odgovor je: " + correctAnswer;
    getUi()->labTacanOdgovor->setText(poruka);
    getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
    getUi()->labTacanOdgovor->setStyleSheet("background-color:red");
    adjustResultLabel();

    disableUI();
    disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    qDebug() << "reset game\n";
    resetGame();
    this->close();
}


void Podrundaui::adjustResultLabel()
{
    QFontMetrics metrics(getUi()->labTacanOdgovor->font());
    QSize textSize = metrics.size(Qt::TextSingleLine, getUi()->labTacanOdgovor->text());
    getUi()->labTacanOdgovor->setFixedSize(textSize);
}


void Podrundaui::onReadyRead()
{
    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }
    }
}


void Podrundaui::processServerMessage(QString serverMessage)
{
    if (serverMessage.startsWith("PITANJE:"))
    {
        QString pitanje = serverMessage.mid(8);
        //qDebug() << pitanje << endl;
        QStringList pitanje_odgovor = pitanje.split(',');
        podrunda->setAnswerQuestion(pitanje_odgovor.value(0), pitanje_odgovor.value(1).toDouble());
        //qDebug() << "pitnje: " << pitanje_odgovor.value(0);
        QString resenje = pitanje_odgovor.value(1);
        //qDebug() << "odgovor: " << resenje;
        //notifyServer(server, "RESENJE:" + resenje.toUtf8() + "\n");
        displayQuestion();
    }
    else if (serverMessage.startsWith("POBEDNIK:"))
    {
        int pobednik = serverMessage.mid(9).toInt();
        if (pobednik == 11)
        {
            const QString poruka = "Bliži rešenju je igrač: " + player1 + ".";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:green");

            //player1Points += 10;
            podrunda->dobio_poene = 1;
        }
        else if (pobednik == 21)
        {
            const QString poruka = "Bliži rešenju je igrač: " + player2 + ".";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:red");

           // player2Points += 10;
            podrunda->dobio_poene = 2;
        }
        else if (pobednik == 12)
        {
            const QString poruka = "Igrač: " + player1 + " je brži.";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:green");

           // player1Points += 10;
            podrunda->dobio_poene = 1;
        }
        else if (pobednik == 22)
        {
            const QString poruka = "Igrač: " + player2 + " je brži.";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:red");

           // player2Points += 10;
            podrunda->dobio_poene = 2;
        }
        else if (pobednik == 0)
        {
            const QString poruka = "Oba odgovora su podjednako udaljena od rešenja.";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:green");

          //  player1Points += 10;
           // player2Points += 10;
            podrunda->dobio_poene = 0;
        }
        else if (pobednik == -1)
        {
            const QString poruka = "GRESKA";
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:red");
        }
        else
        {
            const QString poruka = QString::number(pobednik);
            getUi()->labTacanOdgovor->setText(poruka);
            getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
            getUi()->labTacanOdgovor->setStyleSheet("background-color:white");
        }

        //getUi()->labTacanOdgovor->setStyleSheet("background-color:white");
        adjustResultLabel();
        disableUI();
        time = 3;
    }
    else if(serverMessage.startsWith("POENI1"))
    {
        //player1Points += 10;
        QString poeni = serverMessage.mid(7);
        player1Points = poeni.toInt();
    }
    else if(serverMessage.startsWith("POENI2"))
    {
         //player2Points += 10;
        QString poeni = serverMessage.mid(7);
        player2Points = poeni.toInt();
    }
    else if(serverMessage.startsWith("POENI3"))
    {
         //player1Points += 10;
         //player2Points += 10;
        QString poeni1 = serverMessage.mid(7);
        player1Points = poeni1.toInt();
        QString poeni2 = serverMessage.mid(7);
        player2Points = poeni2.toInt();
    }
    else if(serverMessage.startsWith("ISTEKLO"))
    {
        qDebug() << "isteklo vreme\n";

        const QString poruka = "Vreme je isteklo!!!";
        getUi()->labTacanOdgovor->setText(poruka);
        getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
        getUi()->labTacanOdgovor->setStyleSheet("background-color:red");

        //player1Points = 0;
        //player2Points = 0;

        adjustResultLabel();
        disableUI();
        //time = 3;
    }
}
