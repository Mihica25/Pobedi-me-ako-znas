#include "pocetniekran.h"
#include "ui_pocetniekran.h"

PocetniEkran::PocetniEkran(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PocetniEkran)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap bkgnd(":/background/resources/start_menu.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

PocetniEkran::~PocetniEkran()
{
    delete ui;
}

