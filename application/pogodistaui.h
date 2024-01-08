#ifndef POGODISTAUI_H
#define POGODISTAUI_H

#include "pogodista.h"
#include <QDebug>
#include <QPainter>
#include <QTcpSocket>
#include <QTimer>
#include <QWidget>

namespace Ui
{
class PogodiStaUI;
}

class PogodiStaUI : public QWidget
{
    Q_OBJECT

  public:
    explicit PogodiStaUI(QWidget *parent = nullptr);
    explicit PogodiStaUI(QWidget *parent, QTcpSocket *tcpSocket = nullptr, QString player1 = "", QString player2 = "",
                         bool red = false, int pogodiStapartija = -1, int player1Points = 0, int player2Points = 0);
    ~PogodiStaUI();

    static void sleep(int time);
    bool isReadyToStart = false;
    int getPlayer1Points();
    int getPlayer2Points();
    void setPlayer1Points(int playerPoints1);
    void setPlayer2Points(int playerPoints2);
    QString getPlayer1();
    QString getPlayer2();
    void setPlayer1(QString player1);
    void setPlayer2(QString player2);
    int getTime();
    Ui::PogodiStaUI *getUi();
    int getRoundNumber();
    int getPixelSize();

  signals:
    void gameEnds();
    void mGameEnds();

  private slots:
    void updateTimer();
    void onGuessSubmit();
    void on_gameEnds();
    void onReadyRead();

  private:
    Ui::PogodiStaUI *ui;
    PogodiSta *pogodiSta = nullptr;
    QPixmap updatedImage;
    QTcpSocket *server = nullptr;
    QTimer *gameTimer;
    int gameTime;
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
    int player1Points;
    int player2Points;
    QString info;
    bool turn = false;

    void setBackground();
    QPixmap pixelateImage(const QPixmap original, int pixelSize);
    void sendMessage(QTcpSocket *socket, QString msg);
    void processServerMessage(QString serverMessage);
    void showSolution();
    void generateImage();
    void startGame();
};

#endif // POGODISTAUI_H
