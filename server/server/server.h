#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "lobby.h"
#include <QDebug>

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

};

#endif // SERVER_H
