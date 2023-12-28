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
    // Čekamo na novu konekciju
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();

    if (clientSocket) {

        clientSocket->waitForReadyRead();
        QString username = clientSocket->readAll();

        qDebug() << "New client connected." << " Username: " << username;

        // Kreiramo instancu Player-a
        Player* newPlayer = new Player(clientSocket, username, this);

        // Dodajemo novog igrača u lobi
        lobby->addPlayer(newPlayer);
    }
}


void Server::sendMessage(QTcpSocket* socket, QString msg)
{
    qDebug() << "Sending msg: " << msg;
    socket->write(msg.toUtf8());
    socket->flush();

}

