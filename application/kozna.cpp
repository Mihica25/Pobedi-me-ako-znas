#include "kozna.h"
#include "ui_kozna.h"

KoZna::KoZna(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KoZna)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap bkgnd(":/background/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

KoZna::~KoZna()
{
    delete ui;
}

