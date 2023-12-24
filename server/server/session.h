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
#include <QRandomGenerator>

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
    void player1ReadyReadMojBroj();
    void player2ReadyReadMojBroj();
//    void player1ReadyRead();
//    void player2ReadyRead();

private:
    Player *player1;
    Player *player2;
    QString recko;

    QString targetNumber;
    QString initialNumbers;
    QString player1_res;
    QString player2_res;
    int submit;

    void startGame();
    void startRecko();
    void startMojBroj();

    void processReckoMessage(const QString& msg);
    QString checkReckoSolution(const QString& word);
    void processMojBrojMessage(const QString& msg);
    void checkMojBrojSolution(const QString& pt1, const QString& pt2);

    QString generateTargetNumber();
    QString generateInitialNumbers();

};

#endif // SESSION_H
