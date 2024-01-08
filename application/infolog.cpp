#include "infolog.h"
#include "ui_infolog.h"

InfoLog::InfoLog(QWidget *parent) : QMainWindow(parent), ui(new Ui::InfoLog)
{

    ui->setupUi(this);

    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(palette);

    connect(ui->tb1, &QToolButton::clicked, this, &InfoLog::cancel);
}

InfoLog::~InfoLog()
{
    delete ui;
}

void InfoLog::cancel()
{
    this->close();
}
