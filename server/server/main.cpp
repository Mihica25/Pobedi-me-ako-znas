#include "server.h"
#include <QApplication>

int
main (int argc, char *argv[])
{
  QApplication a (argc, argv);

  Server *server = new Server ();
  server->startServer (8000);

  return a.exec ();
}
