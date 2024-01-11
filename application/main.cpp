#include "koznaui.h"
#include "mainwindow.h"
#include "memorija.h"
#include "mojbroj.h"
#include "pocetniekran.h"
#include "podrundaui.h"
#include "pogodistaui.h"
#include "reckoui.h"
#include <QApplication>

int
main (int argc, char *argv[])
{
  QApplication a (argc, argv);

  PocetniEkran pe;
  pe.show ();

  return a.exec ();
}
