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
    void player1ReadyReadKoZna();
    void player2ReadyReadKoZna();
//    void player1ReadyRead();
//    void player2ReadyRead();

private:
    Player *player1;
    Player *player2;
    QString recko;


    void startGame();
    void startRecko();
    void startKoZna();

    void processReckoMessage(const QString& msg);
    QString checkReckoSolution(const QString& word);
    void processKoZnaMessage(const QString& msg);
    QString checkKoZnaSolution(const QString& word);

};

#endif // SESSION_H
