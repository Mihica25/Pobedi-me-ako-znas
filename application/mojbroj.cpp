#include "mojbroj.h"
#include "ui_mojbroj.h"

Mojbroj::Mojbroj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mojbroj)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap bkgnd("/home/user/Desktop/pobedi-me-ako-znas/application/resources/moj_broj.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Mojbroj::~Mojbroj()
{
    delete ui;
}
