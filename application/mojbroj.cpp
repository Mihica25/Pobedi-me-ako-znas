#include "mojbroj.h"
#include "ui_mojbroj.h"
#include "mojbrojlogic.h"

#include <QDebug>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QFont>
#include <QTimer>

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
    ui->lineEdit_result->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_result_2->setReadOnly(true);

    QFont font;
    font.setPointSize(14);
    ui->lineEdit_result->setFont(font);
    ui->lineEdit_result->setStyleSheet("color : red");
    ui->lineEdit_result_2->setFont(font);
    ui->lineEdit_result_2->setStyleSheet("color : red");

    ui->lineEdit_2->hide();
    ui->lineEdit_result_2->hide();

    connect(ui->pushButton_num1,SIGNAL(released()),this,SLOT(buttonPressedNum()));
    connect(ui->pushButton_num2,SIGNAL(released()),this,SLOT(buttonPressedNum()));
    connect(ui->pushButton_num3,SIGNAL(released()),this,SLOT(buttonPressedNum()));
    connect(ui->pushButton_num4,SIGNAL(released()),this,SLOT(buttonPressedNum()));
    connect(ui->pushButton_num5,SIGNAL(released()),this,SLOT(buttonPressedNum()));
    connect(ui->pushButton_num6,SIGNAL(released()),this,SLOT(buttonPressedNum()));

    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(buttonPressedOp()));
    connect(ui->pushButton_sub,SIGNAL(released()),this,SLOT(buttonPressedOp()));
    connect(ui->pushButton_mul,SIGNAL(released()),this,SLOT(buttonPressedOp()));
    connect(ui->pushButton_div,SIGNAL(released()),this,SLOT(buttonPressedOp()));
    connect(ui->pushButton_leftBr,SIGNAL(released()),this,SLOT(buttonPressedOp()));
    connect(ui->pushButton_rightBr,SIGNAL(released()),this,SLOT(buttonPressedOp()));

    connect(ui->pushButton_submit,SIGNAL(released()),this,SLOT(buttonPressedSubmit()));

    connect(ui->pushButton_del,SIGNAL(released()),this,SLOT(del()));

    initGame();

/*  TIMER
    QTimer *timer = new QTimer(this);
    timer->start(10000);
    connect(timer, &QTimer::timeout, this, &Mojbroj::deinitGame);
*/
}

void Mojbroj::initGame()
{
    m_mojbroj = new MojBrojLogic();
    m_mojbroj->startGame();
    setNumbers();
}

void Mojbroj::deinitGame()
{
    ui->pushButton_num1->setText("");
    ui->pushButton_num2->setText("");
    ui->pushButton_num3->setText("");
    ui->pushButton_num4->setText("");
    ui->pushButton_num5->setText("");
    ui->pushButton_num6->setText("");

}

Mojbroj::~Mojbroj()
{
    delete m_mojbroj;
    delete ui;
}

void Mojbroj::buttonPressedNum()
{
    //qDebug() << "test";
    QPushButton *button = (QPushButton*)sender();

    QString expression = ui->lineEdit->text() + button->text();
    ui->lineEdit->setText(expression);

    button->setEnabled(false);
}

void Mojbroj::buttonPressedOp()
{
    QPushButton *button = (QPushButton*)sender();

    QString expression = ui->lineEdit->text() + button->text();
    ui->lineEdit->setText(expression);

}

void Mojbroj::buttonPressedSubmit()
{
    ui->pushButton_num1->setEnabled(false);
    ui->pushButton_num2->setEnabled(false);
    ui->pushButton_num3->setEnabled(false);
    ui->pushButton_num4->setEnabled(false);
    ui->pushButton_num5->setEnabled(false);
    ui->pushButton_num6->setEnabled(false);
    ui->pushButton_add->setEnabled(false);
    ui->pushButton_sub->setEnabled(false);
    ui->pushButton_mul->setEnabled(false);
    ui->pushButton_div->setEnabled(false);
    ui->pushButton_leftBr->setEnabled(false);
    ui->pushButton_rightBr->setEnabled(false);
    ui->pushButton_del->setEnabled(false);
    ui->pushButton_submit->setEnabled(false);

    ui->lineEdit_2->show();
    ui->lineEdit_result_2->show();

    QString expression = ui->lineEdit->text();
    qDebug() << expression;
    int result = m_mojbroj->submitSolution(expression, "1");
    ui->lineEdit_result->setText(QString::number(result));

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
    QVector<int> initialNumbers = m_mojbroj->availableNumbers;
    ui->pushButton_num1->setText(QString::number(initialNumbers[0]));
    ui->pushButton_num2->setText(QString::number(initialNumbers[1]));
    ui->pushButton_num3->setText(QString::number(initialNumbers[2]));
    ui->pushButton_num4->setText(QString::number(initialNumbers[3]));
    ui->pushButton_num5->setText(QString::number(initialNumbers[4]));
    ui->pushButton_num6->setText(QString::number(initialNumbers[5]));
    //qDebug() << initialNumbers[0];
    //qDebug() << initialNumbers[5];
    int targetNumber = m_mojbroj->targetNumber;

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

