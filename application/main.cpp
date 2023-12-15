#include "mainwindow.h"
#include <QApplication>
#include "kozna.h"
#include "mojbroj.h"
#include "podrundaui.h"
#include "pocetniekran.h"
#include "reckoui.h"
#include "pogodistaui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ReckoUI wordlewindow;
    wordlewindow.show();

    KoZna kz;
    kz.show();


    Mojbroj mb;
    mb.show();

    Podrundaui pr;
    pr.show();

    PocetniEkran pe;
    pe.show();

    PogodiStaUI ps;
    ps.show();


    return a.exec();
}
