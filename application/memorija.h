#ifndef MEMORIJA_H
#define MEMORIJA_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QTcpSocket>
#include <QString>
#include "cardwidget.h"

namespace Ui {
class Memorija;
}

class Memorija : public QWidget
{
    Q_OBJECT

public:
    explicit Memorija(QWidget *parent = nullptr);
    explicit Memorija(QWidget *parent = nullptr, QTcpSocket* tcpSocket = nullptr, QString player1 = "", QString player2 = "", bool red = false, int player1Points = 0, int player2Points = 0);
    ~Memorija();


signals:
    void gameEnd();

public slots:
    void onReadyRead();

private slots:
    void onCardClicked(int cardId);

private:
    Ui::Memorija *ui;
    Memorija* memorija = nullptr;
    bool multiplayer = false;
    QTcpSocket* server = nullptr;
    QString player1 = "";
    QString player2 = "";
    const int numRows = 4;
    const int numCols = 5;
    const int totalPairs = 10;
    bool turn = false;
    bool playerNo = false;
    int player1Points = 0;
    int player2Points = 0;
    int pairsFound=0;
    QVector<int> turnedCards;
    QVector<int> turnedCardsOp;
    QMap<int, CardWidget*> cardIdToWidget;


    void setUpBackground();
    void startMemorija();
    void initializeGame(QVector<int> &cardIds);
    void hideUnmatchedCards();
    void hideUnmatchedCardsOp();
    bool checkForMatch();
    bool checkForMatchOp();
    void resetTurnedCards();
    void opponentsView(int card);
    void switchTurns(bool isPlayersTurn);

    void blockWholeWindow(bool block);

    void sendMessage(QTcpSocket* socket, QString msg);
    void processServerMessage(QString serverMessage);
};

#endif // MEMORIJA_H
