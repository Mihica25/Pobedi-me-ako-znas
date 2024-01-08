#include "pogodistaui.h"
#include "ui_pogodistaui.h"

PogodiStaUI::PogodiStaUI(QWidget *parent)
    : QWidget(parent), ui(new Ui::PogodiStaUI), pogodiSta(new PogodiSta()), gameTimer(new QTimer(this))
{
    ui->setupUi(this);
    ui->leInsert->setEnabled(false);
    setBackground();
    connect(gameTimer, &QTimer::timeout, this, &PogodiStaUI::updateTimer);
    startGame();
}

PogodiStaUI::PogodiStaUI(QWidget *parent, QTcpSocket *tcpSocket, QString player_1, QString player_2, bool red,
                         int pSPartija, int player1_points, int player2_points)
    : QWidget(parent), ui(new Ui::PogodiStaUI), gameTimer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    turn = red;
    qDebug() << "Red: " << turn;

    if (turn)
    {
        player1 = player_1;
        player2 = player_2;
    }
    else
    {
        player1 = player_2;
        player2 = player_1;
    }
    player1Points = player1_points;
    player2Points = player2_points;

    pogodiStaPartija = pSPartija;

    ui->setupUi(this);
    ui->leInsert->setEnabled(false);
    setBackground();

    connect(gameTimer, &QTimer::timeout, this, &PogodiStaUI::updateTimer);
    connect(server, &QTcpSocket::readyRead, this, &PogodiStaUI::onReadyRead);
    connect(this, &PogodiStaUI::gameEnds, this, &PogodiStaUI::on_gameEnds);

    startGame();
}

Ui::PogodiStaUI *PogodiStaUI::getUi()
{
    return ui;
}

int PogodiStaUI::getTime()
{
    return gameTime;
}

QString PogodiStaUI::getPlayer1()
{
    return player1;
}

QString PogodiStaUI::getPlayer2()
{
    return player2;
}

void PogodiStaUI::setPlayer1(QString playerr1)
{
    player1 = playerr1;
}

void PogodiStaUI::setPlayer2(QString playerr2)
{
    player2 = playerr2;
}

void PogodiStaUI::setPlayer1Points(int playerr1Points)
{
    player1Points = playerr1Points;
}

void PogodiStaUI::setPlayer2Points(int playerr2Points)
{
    player2Points = playerr2Points;
}

int PogodiStaUI::getRoundNumber()
{
    return roundNumber;
}

int PogodiStaUI::getPixelSize()
{
    return pixelSize;
}

PogodiStaUI::~PogodiStaUI()
{
    delete ui;
}

void PogodiStaUI::startGame()
{
    pixelSize = 32;
    gameTime = 60;
    roundNumber = 6;
    generateImage();
    if (pogodiStaPartija == 0)
    {
        connect(ui->leInsert, &QLineEdit::returnPressed, this, &PogodiStaUI::onGuessSubmit);
    }
    ui->lcdPoints1->display(player1Points);
    ui->lcdPoints2->display(player2Points);
    gameTimer->start(1000);
}

void PogodiStaUI::updateTimer()
{
    ui->lbTimer->setText(QString::number(gameTime));
    if (gameTime == 0)
    {
        gameTimer->stop();
        ui->leInsert->setEnabled(false);
        sleep(1500);
        showSolution();
    }
    else if (gameTime % 12 == 0)
    {
        gameTimer->stop();
        ui->leInsert->setEnabled(false);
        ui->leInsert->setStyleSheet("background-color: lightgrey;");
        sleep(1500);
        if (pixelSize == 0)
        {
            ui->lbImage->setPixmap(pogodiSta->getGuessingImage());
        }
        else
        {
            QPixmap updatedImage = pixelateImage(pogodiSta->getGuessingImage(), pixelSize);
            ui->lbImage->setPixmap(updatedImage);
            ui->lbInfo->setText(pogodiSta->getInfo());
        }
        roundNumber -= 1;
        sleep(1500);
        pixelSize -= pixelStep;
        ui->leInsert->setText("");
        ui->leInsert->setEnabled(true);
        ui->leInsert->setStyleSheet("background-color: none;");
        gameTimer->start();
    }

    gameTime -= 1;
}

void PogodiStaUI::onGuessSubmit()
{
    ui->leInsert->setEnabled(false);
    ui->leInsert->setStyleSheet("background-color: lightgrey;");
    QString attempt = ui->leInsert->text().trimmed().toLower();

    if (multiplayer)
    {
        sendMessage(server, "IMG_GUESS:" + attempt + "\n");
    }
    else
    {
        if (attempt == pogodiSta->getAnswer())
        {
            gameTimer->stop();
            points = pogodiSta->calculatePoints(roundNumber);
            sleep(1500);
            showSolution();
            qDebug() << QString::number(points);
        }
    }
}

void PogodiStaUI::on_gameEnds()
{
    if (pogodiStaPartija++ == 0)
    {
        delete pogodiSta;

        startGame();
    }
    else
    {
        sendMessage(server, "POGODISTA_END\n");
        delete pogodiSta;
    }
}

void PogodiStaUI::onReadyRead()
{
    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);
    qDebug() << "Received message: " + msg;
    QStringList receivedMessages = msg.split('\n');

    for (const QString &receivedMessage : receivedMessages)
    {
        if (!receivedMessage.isEmpty())
        {
            processServerMessage(receivedMessage);
        }
    }
}

void PogodiStaUI::setBackground()
{
    QPixmap bkgrnd(":/background/resources/pogodi_sta.png");
    bkgrnd = bkgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgrnd);
    this->setPalette(palette);
    ui->lePlayer1->setText(player1);
    ui->lePlayer2->setText(player2);
}

QPixmap PogodiStaUI::pixelateImage(const QPixmap original, int pixelSize)
{
    QPixmap pixelated = original;
    QPainter painter(&pixelated);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);
    painter.drawPixmap(pixelated.rect(), original, original.rect());

    for (int y = 0; y < pixelated.height(); y += pixelSize)
    {
        for (int x = 0; x < pixelated.width(); x += pixelSize)
        {
            QRect rect(x, y, pixelSize, pixelSize);
            QColor color = pixelated.toImage().pixelColor(x, y);
            painter.fillRect(rect, color);
        }
    }

    painter.end();
    return pixelated;
}

void PogodiStaUI::sleep(int time)
{
    QEventLoop loop;
    QTimer::singleShot(time, &loop, &QEventLoop::quit);
    loop.exec();
}

void PogodiStaUI::sendMessage(QTcpSocket *socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();
}

void PogodiStaUI::processServerMessage(QString serverMessage)
{
    if (serverMessage.startsWith("IMAGE_G:"))
    {
        QList<QString> parts = serverMessage.split(':');
        QString info;
        int index = -1;
        QString answ;
        if (parts.size() == 4)
        {
            index = parts[1].toInt();
            info = parts[2];
            answ = parts[3];
            qDebug() << "Received index: " << QString::number(index) << "and info: " << info;
        }
        pogodiSta = new PogodiSta(index, info, answ);
    }
    else if (serverMessage.startsWith("IMG_ANS:"))
    {
        gameTimer->stop();
        ui->leInsert->setEnabled(false);
        QStringList data = serverMessage.split(":");
        int correctPlayer = data[1].toInt();
        if (correctPlayer == 1)
        {
            player1Points += pogodiSta->calculatePoints(roundNumber);
        }
        else
        {
            player2Points += pogodiSta->calculatePoints(roundNumber);
        }
        pogodiSta->setAnswer(data[2]);
        ui->lcdPoints1->display(player1Points);
        ui->lcdPoints2->display(player2Points);

        showSolution();
    }
    else if (serverMessage.startsWith("POGODISTA_END"))
    {
        disconnect(server, &QTcpSocket::readyRead, this, &PogodiStaUI::onReadyRead);
        disconnect(gameTimer, &QTimer::timeout, this, &PogodiStaUI::updateTimer);
        disconnect(this, &PogodiStaUI::gameEnds, this, &PogodiStaUI::on_gameEnds);
        sleep(3000);
        emit mGameEnds();
    }
    else
    {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void PogodiStaUI::showSolution()
{
    ui->lbImage->setPixmap(pogodiSta->getGuessingImage());
    ui->lbInfo->setText(pogodiSta->getAnswer());
    emit gameEnds();
}

void PogodiStaUI::generateImage()
{
    sendMessage(server, "IMAGE_GEN\n");
}

int PogodiStaUI::getPlayer1Points()
{
    return player1Points;
}

int PogodiStaUI::getPlayer2Points()
{
    return player2Points;
}
