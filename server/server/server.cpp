#include "server.h"

Server::Server(QObject *parent) : QObject(parent), tcpServer(nullptr), lobby(nullptr)
{
    // Inicijalizacija servera i lobby-ja
    tcpServer = new QTcpServer(this);
    lobby = new Lobby(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newClientConnection);
}

Server::~Server()
{
    // Osigurajte da se resursi oslobode prilikom uništavanja objekta
    if (tcpServer->isListening()) {
        tcpServer->close();
    }

    delete lobby;
}

void Server::startServer(int port)
{
    if (tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port:" << tcpServer->serverPort();
        qDebug() << "Max connections:" << tcpServer->maxPendingConnections();
    } else {
        qDebug() << "Server failed to start.";
    }
}

void Server::newClientConnection()
{
    // Čekaj na novu konekciju
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();

    if (clientSocket) {
        qDebug() << "New client connected.";
        sendMessage(clientSocket, "Welcome :)");
        // Kreiraj instancu Player-a
        Player* newPlayer = new Player(clientSocket, this);

        // Dodaj novog igrača u lobi
        lobby->addPlayer(newPlayer);
    }
}

void Server::sendMessage(QTcpSocket* socket,QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();

}
