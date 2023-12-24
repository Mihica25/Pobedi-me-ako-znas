#ifndef MOJBROJ_H
#define MOJBROJ_H

#include "mojbrojlogic.h"
#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsBlurEffect>
#include <QTimer>

#include <QTcpSocket>

namespace Ui {
class Mojbroj;
}

class Mojbroj : public QWidget
{
    Q_OBJECT

public:
    explicit Mojbroj(QWidget *parent = nullptr);
    explicit Mojbroj(QWidget *parent = nullptr, QTcpSocket* tcpSocket = nullptr, QString player1 = "", QString player2 = "", bool red = false, int player1Points = 0, int player2Points = 0);
    ~Mojbroj();

private:
    Ui::Mojbroj *ui;
    MojBrojLogic *m_mojbroj;
    QTimer *timer;
    int time;

    int bodovi = 0;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    QTcpSocket* server = nullptr;
    QString player1 = "";
    QString player2 = "";
    bool turn = false;
    bool playerNo = false;
    int player1Points = 0;
    int player2Points = 0;
    int submit = 0;

    void initGame();
    void deinitGame();
    void setNumbers();
    void setButtonStatus(bool enabled);


    void processServerMessage(QString serverMessage);
    void sendMessage(QTcpSocket* socket, QString msg);

private slots:
    void buttonPressedNum();
    void buttonPressedOp();
    void buttonPressedSubmit();
    void buttonPressedNextRound();
    void del();

public slots:
    void on_timesUp();
    void on_gameEnd();
    void updateTime();
    //server
    void onReadyRead();

signals:
    void timesUp();
    void gameEnd();

};

#endif // MOJBROJ_H
