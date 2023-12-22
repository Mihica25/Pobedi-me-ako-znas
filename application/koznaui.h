#ifndef KOZNAUI_H
#define KOZNAUI_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QTimer>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class KoZnaui; }
QT_END_NAMESPACE

class KoZnaui : public QMainWindow
{
    Q_OBJECT

public:
    KoZnaui(QWidget *parent = nullptr);
    explicit KoZnaui(QWidget *parent = nullptr, QTcpSocket* tcpSocket = nullptr, QString player1 = "", QString player2 = "", bool red = false, int player1Points = 0, int player2Points = 0);
    ~KoZnaui();
    QVector<QString> getQuestion(int numberOfQuestion);
    void displayQuestion(int questionNumber);

public slots:
    void on_timesUp();
    void on_gameEnds();
    void updateTime();

private:
    Ui::KoZnaui *ui;
    QTimer* tajmer;
    int numberOfQuestion;
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

    void displayAnswer();
    void disableUi();
    void enableUi();
    void restartColor();
    void startGame();
    void sendMessage(QTcpSocket* socket, QString msg);
    void processServerMessage(QString serverMessage);
    void onReadyRead();



    QString getCorrectAnswer();
    bool guess(QString answer);

    void on_pushButtonAns1();
    void on_pushButtonAns2();
    void on_pushButtonAns3();
    void on_pushButtonAns4();






signals:
    void timesUp();
    void gameEnds();





};
#endif // KOZNAUI_H


