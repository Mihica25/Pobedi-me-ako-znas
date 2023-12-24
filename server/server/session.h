#ifndef SESSION_H
#define SESSION_H

#include <QTcpServer>
#include <QDebug>
#include "player.h"
#include <string>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QString>

class Session : public QObject
{
    Q_OBJECT

public:
    Session(Player *player1, Player *player2, QObject *parent = nullptr);
    ~Session();

    void sendMessageToPlayer1(QString message);
    void sendMessageToPlayer2(QString message);
    void sendMessageToBothPlayers(QString message);

private slots:
    void player1ReadyReadRecko();
    void player2ReadyReadRecko();

    void player1ReadyReadPodrunda();
    void player2ReadyReadPodrunda();
//    void player1ReadyRead();
//    void player2ReadyRead();

private:
    Player *player1;
    Player *player2;
    QString recko;

    void startGame();
    void startRecko();
    void startPodrunda();

    void processReckoMessage(const QString& msg);
    void processPodrundaMessage(const QString& msg, const int num);
    QString checkReckoSolution(const QString& word);
    int checkPodrundaWinner();

    //int podrunda_resenje;

};

#endif // SESSION_H
