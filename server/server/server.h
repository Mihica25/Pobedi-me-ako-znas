#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "lobby.h"
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QList>
#include <QTextStream>
#include <QDataStream>


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    ~Server();

    void startServer(int port);

private slots:
    void newClientConnection();

private:
    QTcpServer *tcpServer;
    Lobby *lobby;

    void sendMessage(QTcpSocket* socket,QString msg);
//    QTcpSocket* waitForNewConnection();

    struct GameResult {
            QString player1Name;
            int player1Points;
            QString player2Name;
            int player2Points;
            QDateTime dateTime;
    };

    QList<GameResult> loadResults();
    void printResults(const QList<GameResult> &results);
    void sendBestResults(QTcpSocket *socket);


};

#endif // SERVER_H
