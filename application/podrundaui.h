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

    int player1Points = 0;
    int player2Points = 0;


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

    Ui::Podrundaui *getUi();
    void on_pbOdgovori();
    void getQuestion();
    void displayQuestion();
    void getGuess();
    void displayAnswer();
    void notifyServer(QTcpSocket* socket, QString msg);
    void disableUI();
    void enableUI();
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
