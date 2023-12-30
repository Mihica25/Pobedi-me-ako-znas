#ifndef PODRUNDAUI_H
#define PODRUNDAUI_H

#include <QWidget>
#include "podrunda.h"
#include <QTimer>
#include <string>
#include <QString>
#include <QTcpSocket>

namespace Ui {
class Podrundaui;
}

class Podrundaui : public QWidget
{
    Q_OBJECT

public:
    explicit Podrundaui(QWidget *parent = nullptr);
    explicit Podrundaui(QWidget *parent = nullptr, QTcpSocket* tcpSocket = nullptr, QString player1 = "", QString player2 = "", int player1Points = 0, int player2Points = 0);
    ~Podrundaui();

    void startGame();
    void resetGame();

    QString getPlayer1();
    QString getPlayer2();
    void setPlayer1(QString playerr1);
    void setPlayer2(QString playerr2);

    int getPlayer1Points();
    int getPlayer2Points();
    void setPlayer1Points(int playerr1Points);
    void setPlayer2Points(int playerr2Points);

    void disableUI();
    void enableUI();

    Ui::Podrundaui *getUi();
    int getTime();


private:
    Ui::Podrundaui *ui;

    Podrunda* podrunda = nullptr;
    QTimer* timer;
    int time = 60;
    int bodovi = 0;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    QTcpSocket* server = nullptr;
    QString player1 = "";
    QString player2 = "";
    int player1Points = 0;
    int player2Points = 0;

    void on_pbOdgovori();
    void getQuestion();
    void displayQuestion();
    void getGuess();
    void displayAnswer();
    void notifyServer(QTcpSocket* socket, QString msg);
    bool isNumberGuessed();
    void setBackground();
    void adjustResultLabel();

    void on_pbOdgovoriMultiplayer();
    void processServerMessage(QString serverMessage);

    //std::pair<QString, double> getAnswerQuestion() const;
    //void setAnswerQuestion(QString pitanje, double odgovor);

    //std::pair<QString, double> answerQuestion;
    //Podrunda podrunda;
    //QTimer *timer;
    //int time;

signals:
    void timesUp();
    void gameEnded();

public slots:
    void updateTime();
    void on_timesUp();
    void on_gameEnded();
    void onReadyRead();


};

#endif // PODRUNDAUI_H
