#include "mojbroj.h"
#include "ui_mojbroj.h"
#include "mojbrojlogic.h"

#include <QDebug>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QFont>

Mojbroj::Mojbroj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mojbroj)
{
    ui->setupUi(this);

    QPixmap bkgnd(":background/resources/moj_broj.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->lineEdit->setReadOnly(true);

    connect(ui->pushButton_num1,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_num2,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_num3,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_num4,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_num5,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_num6,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_sub,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_mul,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_div,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_leftBr,SIGNAL(released()),this,SLOT(buttonPressed()));
    connect(ui->pushButton_rightBr,SIGNAL(released()),this,SLOT(buttonPressed()));

    connect(ui->pushButton_del,SIGNAL(released()),this,SLOT(del()));

    initGame();
    setNumbers();

}

void Mojbroj::initGame()
{
    m_mojbroj = new MojBrojLogic();
}

Mojbroj::~Mojbroj()
{
    delete m_mojbroj;
    delete ui;
}

void Mojbroj::buttonPressed()
{
    //qDebug() << "test";
    QPushButton *button = (QPushButton*)sender();

    QString expression = ui->lineEdit->text() + button->text();
    ui->lineEdit->setText(expression);
}

void Mojbroj::del()
{
    QString expression = ui->lineEdit->text();

    if(!expression.isEmpty())
    {
        expression.chop(1);
        ui->lineEdit->setText(expression);
    }
}

void Mojbroj::setNumbers()
{
    // FIXME new generated numbers dont show up
    std::vector<int> initialNumbers = m_mojbroj->generateInitialNumbers();
    ui->pushButton_num1->setText(QString::number(initialNumbers[0]));
    ui->pushButton_num2->setText(QString::number(initialNumbers[1]));
    ui->pushButton_num3->setText(QString::number(initialNumbers[2]));
    ui->pushButton_num4->setText(QString::number(initialNumbers[3]));
    ui->pushButton_num5->setText(QString::number(initialNumbers[4]));
    ui->pushButton_num6->setText(QString::number(initialNumbers[5]));

    int targetNumber = m_mojbroj->generateTargetNumber();

    QFrame *frame = ui->frame_targetNum;
    QHBoxLayout *hb  = new QHBoxLayout(frame);
    QLabel *l = new QLabel(QString::number(targetNumber), frame);
    QFont font;
    font.setPointSize(20);
    l->setFont(font);
    hb->addStretch();
    hb->addWidget(l,0,Qt::AlignCenter);
    hb->addStretch();

}

