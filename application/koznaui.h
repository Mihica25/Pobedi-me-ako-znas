#ifndef KOZNAUI_H
#define KOZNAUI_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QTimer>
#include <QTcpSocket>
#include <QStringList>
#include <QVector>


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
    void generisiPitanja(QString pitanje);

public slots:
    void on_timesUp();
    void on_gameEnds();
    void updateTime();
    void onReadyRead();
    void on_pushButtonAns1();
    void on_pushButtonAns2();
    void on_pushButtonAns3();
    void on_pushButtonAns4();
    void on_pushButtonAns1Multiplayer();
    void on_pushButtonAns2Multiplayer();
    void on_pushButtonAns3Multiplayer();
    void on_pushButtonAns4Multiplayer();
    void on_DALJE();

private:
    Ui::KoZnaui *ui;
    QTimer* tajmer;
    int numberOfQuestion;
    int time;
    int bodovi = 0;
    int brojPitanja = 0;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    QTcpSocket* server = nullptr;
    QString player1 = "";
    QString player2 = "";
    bool playerId = false;
    bool playerNo = false;
    int player1Points = 0;
    int player2Points = 0;
    QVector<QStringList> pitanja;

    void displayAnswer();
    void disableUi();
    void enableUi();
    void restartColor();
    void startGame();
    void sendMessage(QTcpSocket* socket, QString msg);
    void processServerMessage(QString serverMessage);




    QString getCorrectAnswer();
    bool guess(QString answer);











signals:
    void timesUp();
    void gameEnds();





};
#endif // KOZNAUI_H


