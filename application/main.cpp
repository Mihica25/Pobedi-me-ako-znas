#include "mainwindow.h"
#include <QApplication>
#include "wordlewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    WordleWindow ww;
    ww.show();
    return a.exec();
}
