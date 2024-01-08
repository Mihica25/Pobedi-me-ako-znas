#ifndef SERVER_H
#define SERVER_H

#include "lobby.h"
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTextStream>

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
    QString currentDir;
    void sendMessage(QTcpSocket *socket, QString msg);

    struct GameResult
    {
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
