#ifndef POGODISTAUI_H
#define POGODISTAUI_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include "pogodista.h"
#include <QTcpSocket>

namespace Ui {
class PogodiStaUI;
}

class PogodiStaUI : public QWidget
{
    Q_OBJECT

public:
    explicit PogodiStaUI(QWidget *parent = nullptr);
    explicit PogodiStaUI(QWidget *parent, QTcpSocket* tcpSocket = nullptr,
                         QString player1 = "", QString player2 = "", bool red = false, int pogodiStapartija = -1,
                         int player1Points = 0, int player2Points = 0);
    ~PogodiStaUI();

    void startGame();
    static void sleep(int time);
    bool isReadyToStart = false;

signals:
    void gameEnds();

private slots:
    void updateTimer();
    // void updateAnswTimer();
    void onGuessSubmit();
    void on_gameEnds();
    void onReadyRead();

private:
    Ui::PogodiStaUI *ui;
    PogodiSta *pogodiSta = nullptr;;
    QPixmap updatedImage;
    QTcpSocket* server = nullptr;
    QTimer *gameTimer;
    int gameTime;
    // QTimer *answerTimer;
    int answerTime = 0;
    const int pixelStep = 8;
    int pixelSize;
    int roundNumber;
    int points;
    int pogodiStaPartija;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    bool playerNo = false;
    QString player1 = "";
    QString player2 = "";
    int player1Points = 0;
    int player2Points = 0;
    QString info;
    bool turn = false;

    void setBackground();
    QPixmap pixelateImage(const QPixmap original, int pixelSize);
    void sendMessage(QTcpSocket* socket, QString msg);
    void processServerMessage(QString serverMessage);
    void showSolution();
    void generateImage();
};

#endif // POGODISTAUI_H
