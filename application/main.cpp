#include "mainwindow.h"
#include <QApplication>
#include "koznaui.h"
#include "mojbroj.h"
#include "podrundaui.h"
#include "pocetniekran.h"
#include "reckoui.h"
#include "pogodistaui.h"
#include "memorija.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PocetniEkran pe;
    pe.show();

    return a.exec();
}
