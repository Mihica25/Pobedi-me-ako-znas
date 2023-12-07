#include "podrundaui.h"
#include "ui_podrundaui.h"

podrundaui::podrundaui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::podrundaui)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap bkgnd("/home/tamara/Desktop/pobedi-me-ako-znas/application/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

podrundaui::~podrundaui()
{
    delete ui;
}

