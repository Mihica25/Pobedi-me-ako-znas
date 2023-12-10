#include "mainwindow.h"
#include <QApplication>
#include "reckoui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ReckoUI wordlewindow;
    wordlewindow.show();
    return a.exec();
}
