#include "mainwindow.h"
#include <QApplication>
#include "koznaui.h"
#include "mojbroj.h"
#include "podrundaui.h"
#include "pocetniekran.h"
#include "reckoui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
  //  ReckoUI wordlewindow;
  //  wordlewindow.show();

    KoZnaui kz;
    kz.show();

    Mojbroj mb;
    mb.show();


    podrundaui pr;
    pr.show();

    PocetniEkran pe;
    pe.show();


    return a.exec();
}
