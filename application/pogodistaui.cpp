#include "pogodistaui.h"
#include "ui_pogodistaui.h"

PogodiStaUI::PogodiStaUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PogodiStaUI)
    , pogodiSta(new PogodiSta())
    , gameTimer(new QTimer(this))
{
    ui->setupUi(this);
    setBackground();
    startGame();
}

PogodiStaUI::~PogodiStaUI()
{
    delete ui;
}

void PogodiStaUI::startGame()
{
    pixelSize = 40;
    roundNumber = 6;
    gameTime = 60;
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &PogodiStaUI::updateTimer);

    gameTimer->start(1000);
    ui->lbInfo->setText(pogodiSta->getInfo());
    connect(ui->leInsert, &QLineEdit::returnPressed, this, &PogodiStaUI::onGuessSubmit);
}

void PogodiStaUI::updateTimer()
{
    ui->lbTimer->setText(QString::number(gameTime));
    if(gameTime == 0){
        gameTimer->stop();
        ui->leInsert->setEnabled(false);
        sleep(1500);
        ui->lbImage->setPixmap(pogodiSta->getGuessingImage());

    }
    else if(gameTime % 12 == 0){
        gameTimer->stop();
        ui->leInsert->setEnabled(false);
        ui->leInsert->setStyleSheet("background-color: lightgrey;");
        sleep(1500);
        QPixmap updatedImage = pixelateImage(pogodiSta->getGuessingImage(), pixelSize);
        ui->lbImage->setPixmap(updatedImage);
        roundNumber -= 1;
        sleep(1500);
        pixelSize -= pixelStep;
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
    QString attempt = ui->leInsert->text().toLower();
    if(attempt == pogodiSta->getAnswer()) {
        gameTimer->stop();
        points = pogodiSta->calculatePoints(roundNumber);
        sleep(1500);
        ui->lbImage->setPixmap(pogodiSta->getGuessingImage());
        qDebug() << QString::number(points);
    }
}

void PogodiStaUI::setBackground()
{
    QPixmap bkgrnd(":/background/resources/pogodi_sta.png");
    bkgrnd = bkgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgrnd);
    this->setPalette(palette);
}

QPixmap PogodiStaUI::pixelateImage(const QPixmap original, int pixelSize)
{
    QPixmap pixelated = original;
    QPainter painter(&pixelated);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);
    painter.drawPixmap(pixelated.rect(), original, original.rect());

    for (int y = 0; y < pixelated.height(); y += pixelSize) {
        for (int x = 0; x < pixelated.width(); x += pixelSize) {
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
