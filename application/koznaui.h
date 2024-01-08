#ifndef KOZNAUI_H
#define KOZNAUI_H

#include "podrundaui.h"
#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QTcpSocket>
#include <QTimer>
#include <QVector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui
{
class KoZnaui;
}
QT_END_NAMESPACE

class KoZnaui : public QMainWindow
{
    Q_OBJECT

  public:
    KoZnaui(QWidget *parent = nullptr);
    explicit KoZnaui(QWidget *parent = nullptr, QTcpSocket *tcpSocket = nullptr, QString player1 = "",
                     QString player2 = "", bool red = false, int player1Points = 0, int player2Points = 0);
    ~KoZnaui();
    QVector<QString> getQuestion(int numberOfQuestion);
    void displayQuestion(int questionNumber);
    void generisiPitanja(QString pitanje);

    Podrundaui *podrunda;
    int getPlayer1Points();
    int getPlayer2Points();

    QString getPlayer1();
    QString getPlayer2();

    int getTime();

    void disableUi();
    void enableUi();

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

    void on_podrundaEnds();

    Ui::KoZnaui *getUI();

  private:
    Ui::KoZnaui *ui;

    QTimer *tajmer;
    int numberOfQuestion;
    int time;
    int bodovi = 0;
    int brojPitanja = 0;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    QTcpSocket *server = nullptr;
    QTcpSocket *serverp = nullptr;
    QString player1 = "";
    QString player2 = "";
    bool playerId = false;
    bool playerNo = false;
    int player1Points = 0;
    int player2Points = 0;
    QVector<QStringList> pitanja;

    void displayAnswer();
    void restartColor();
    void startGame();
    void sendMessage(QTcpSocket *socket, QString msg);
    void processServerMessage(QString serverMessage);

    QString getCorrectAnswer();
    bool guess(QString answer);

  signals:
    void timesUp();
    void gameEnds();
    void mGameEnds();
    void podrundaEnds();
};
#endif // KOZNAUI_H
