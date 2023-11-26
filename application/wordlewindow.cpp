#include "wordlewindow.h"
#include "ui_wordlewindow.h"


WordleWindow::WordleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordleWindow)
{
    ui->setupUi(this);
}

WordleWindow::~WordleWindow()
{
    delete ui;
}
