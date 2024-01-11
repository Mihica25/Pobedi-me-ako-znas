#include "server.h"

Server::Server (QObject *parent)
	: QObject (parent), tcpServer (nullptr), lobby (nullptr)
{
  tcpServer = new QTcpServer (this);
  lobby = new Lobby (this);
  currentDir = QDir::currentPath ();
  connect (tcpServer, &QTcpServer::newConnection, this,
		   &Server::newClientConnection);
}

Server::~Server ()
{
  if (tcpServer->isListening ())
	{
	  tcpServer->close ();
	}

  delete lobby;
  delete tcpServer;
}

void
Server::startServer (int port)
{
  if (tcpServer->listen (QHostAddress::Any, port))
	{
	  qDebug () << "Server started on port:" << tcpServer->serverPort ();
	  qDebug () << "Max connections:" << tcpServer->maxPendingConnections ();
	}
  else
	{
	  qDebug () << "Server failed to start.";
	}
}

void
Server::newClientConnection ()
{
  QTcpSocket *clientSocket = tcpServer->nextPendingConnection ();

  if (clientSocket)
	{

	  clientSocket->waitForReadyRead ();
	  QString message = clientSocket->readAll ();

	  if (message == "SEND_BEST_RESULTS")
		{
		  qDebug () << "Server received request for best results." << endl;
		  sendBestResults (clientSocket);
		  return;
		}
	  qDebug () << "New client connected."
				<< " Username: " << message;

	  Player *newPlayer = new Player (clientSocket, message, this);

	  lobby->addPlayer (newPlayer);
	}
}

void
Server::sendMessage (QTcpSocket *socket, QString msg)
{

  qDebug () << "Sending msg: " << msg;
  socket->write (msg.toUtf8 ());
  socket->flush ();
}

QList<Server::GameResult>
Server::loadResults ()
{
  QList<GameResult> results;
  QString resPath = currentDir + "/../server/resources/results.txt";
  QFile file (resPath);
  if (file.open (QIODevice::ReadOnly | QIODevice::Text))
	{
	  QTextStream stream (&file);
	  while (!stream.atEnd ())
		{
		  QString line = stream.readLine ();
		  QStringList parts = line.split (",");
		  if (parts.size () == 5)
			{
			  GameResult result;
			  result.player1Name = parts[0];
			  result.player1Points = parts[1].toInt ();
			  result.player2Name = parts[2];
			  result.player2Points = parts[3].toInt ();
			  result.dateTime
				  = QDateTime::fromString (parts[4], "yyyy-MM-ddTHH:mm:ss");
			  results.append (result);
			}
		}
	  file.close ();
	}
  return results;
}

void
Server::printResults (const QList<Server::GameResult> &results)
{
  qDebug () << "Printing results:";
  for (const auto &result : results)
	{
	  qDebug () << "Player 1 Name: " << result.player1Name;
	  qDebug () << "Player 1 Points: " << result.player1Points;
	  qDebug () << "Player 2 Name: " << result.player2Name;
	  qDebug () << "Player 2 Points: " << result.player2Points;
	  qDebug () << "Date and Time: "
				<< result.dateTime.toString ("yyyy-MM-ddTHH:mm:ss");
	  qDebug () << "---------------------";
	}
}

void
Server::sendBestResults (QTcpSocket *socket)
{
  qDebug () << "sendBestResults()" << endl;
  QList<Server::GameResult> results = loadResults ();

  std::sort (results.begin (), results.end (),
			 [] (const Server::GameResult &a, const Server::GameResult &b) {
			   return (a.player1Points + a.player2Points)
					  > (b.player1Points + b.player2Points);
			 });

  if (results.size () > 10)
	{
	  results = results.mid (0, 10);
	}

  QString messageToSend = "BEST_RESULTS:";
  for (const auto &result : results)
	{
	  messageToSend
		  += result.player1Name + "," + QString::number (result.player1Points)
			 + "," + result.player2Name + ","
			 + QString::number (result.player2Points) + ","
			 + result.dateTime.toString ("yyyy-MM-ddTHH:mm:ss") + "\n";
	}

  qDebug () << messageToSend << endl;
  socket->write (messageToSend.toUtf8 ());
  socket->waitForBytesWritten ();

  socket->disconnectFromHost ();
}
