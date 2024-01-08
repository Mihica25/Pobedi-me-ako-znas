#ifndef RECKOUI_H
#define RECKOUI_H

#include "recko.h"
#include <QMainWindow>
#include <QString>
#include <QTcpSocket>
#include <QTimer>
#include <string>

namespace Ui
{
class ReckoUI;
}

class ReckoUI : public QMainWindow
{
    Q_OBJECT

  public:
    explicit ReckoUI(QWidget *parent = nullptr);
    explicit ReckoUI(QWidget *parent = nullptr, QTcpSocket *tcpSocket = nullptr, QString p1Username = "",
                     QString p2Username = "", bool red = false, int p1Points = 0, int p2Points = 0);
    ~ReckoUI();

    void setUpBackground();
    bool quess();
    void startGame();
    int getPlayer1Points();
    int getPlayer2Points();

    QString getPlayer1();
    QString getPlayer2();

    Ui::ReckoUI *getUi();
    int getTime();

  signals:
    void timesUp();
    void gameEnds();
    void mGameEnds();

  public slots:
    void on_timesUp();
    void updateTime();
    void on_gameEnds();
    void onReadyRead();
    void on_mTimesUp();

  private:
    Ui::ReckoUI *ui;
    Recko *recko = nullptr;
    QTimer *tajmer;
    int time = 60;
    int bodovi = 0;
    int ukupni_bodovi = 0;
    bool multiplayer = false;
    QTcpSocket *server = nullptr;
    QString player1 = "";
    QString player2 = "";
    bool turn = false;
    bool playerNo = false;
    int player1Points = 0;
    int player2Points = 0;

    void on_pbPotvrdi1();
    void on_pbPotvrdi2();
    void on_pbPotvrdi3();
    void on_pbPotvrdi4();
    void on_pbPotvrdi5();

    void on_pbPotvrdi1Multiplayer();
    void on_pbPotvrdi2Multiplayer();
    void on_pbPotvrdi3Multiplayer();
    void on_pbPotvrdi4Multiplayer();
    void on_pbPotvrdi5Multiplayer();

    void disableRow(int index, bool disable = true);
    void setUpRows();
    void disableSolution();
    void showSolution(QString word);
    void sendMessage(QTcpSocket *socket, QString msg);
    void restartGame();
    QString getWord();
    void colorRow(QString result);
    void processServerMessage(QString serverMessage);
    void writeWord(QString word);
    void clearAllRows();
    void clearRow(int index);
    void clearSolution();
    void endGame();
};

#endif // RECKOUI_H
