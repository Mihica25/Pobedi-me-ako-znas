#include "mainwindow.h"
#include <QApplication>
#include "wordlewindow.h"
#include "kozna.h"
#include "mojbroj.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    WordleWindow ww;
    ww.show();

    KoZna kz;
    kz.show();


    Mojbroj mb;
    mb.show();

    return a.exec();
}
