#include "mojbroj.h"
#include "ui_mojbroj.h"
#include "mojbrojlogic.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QFont>
#include <QTimer>

Mojbroj::Mojbroj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mojbroj),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    QPixmap bkgnd(":background/resources/moj_broj.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //TIMER
    time = 30;
    ui->label_time->setText(QString::number(time));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &Mojbroj::timesUp, this, &Mojbroj::on_timesUp);
    connect(this, &Mojbroj::gameEnd, this, &Mojbroj::on_gameEnd);

    ui->label_round->hide();
    ui->label_time->hide();

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

    ui->pushButton_nextGame->hide();

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

    connect(ui->pushButton_nextRound,SIGNAL(released()),this,SLOT(buttonPressedNextRound()));

    connect(ui->pushButton_del,SIGNAL(released()),this,SLOT(del()));

}

void Mojbroj::initGame()
{
    timer->start(1000);
    qDebug() << "POCETAK IGRE";

    ui->label_round->show();
    ui->label_time->show();

    setButtonStatus(true);
    m_mojbroj = new MojBrojLogic();
    m_mojbroj->startGame();
    setNumbers();
}

void Mojbroj::deinitGame()
{
    if(m_mojbroj->endGame())
    {
        return;    //end of the game
    }

    setNumbers();
/*
    ui->pushButton_num1->setText("");
    ui->pushButton_num2->setText("");
    ui->pushButton_num3->setText("");
    ui->pushButton_num4->setText("");
    ui->pushButton_num5->setText("");
    ui->pushButton_num6->setText("");   */

    ui->lineEdit->setText("");
    ui->lineEdit_result->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_result_2->setText("");
    ui->lineEdit_2->hide();
    ui->lineEdit_result_2->hide();

    setButtonStatus(true);
}

Mojbroj::~Mojbroj()
{
    delete m_mojbroj;
    delete ui;
}

void Mojbroj::buttonPressedNum()
{

    QVector<QString> currentExpression = m_mojbroj->currentExpression;
    if(!currentExpression.isEmpty())
    {
        QString lastElement = currentExpression.back();

        bool isInt;
        lastElement.toInt(&isInt);

        if (isInt)
        {
            return;
        }
    }
        //inace nije broj pa ga dodajemo
    QPushButton *button = (QPushButton*)sender();
    QString number = button->text();

    m_mojbroj->chooseNumber(number.toInt());

    QString expression = ui->lineEdit->text() + number;
    ui->lineEdit->setText(expression);

    button->setEnabled(false);
}

void Mojbroj::buttonPressedOp()
{
    QPushButton *button = (QPushButton*)sender();
    QString operation = button->text();

    m_mojbroj->chooseOperation(operation);

    QString expression = ui->lineEdit->text() + operation;
    ui->lineEdit->setText(expression);
}

void Mojbroj::buttonPressedSubmit()
{
    timer->stop();
    qDebug() << "TAJMER SE ZAUSTAVIO";

    setButtonStatus(false);

    // Connect with opponent
    ui->lineEdit_2->show();
    ui->lineEdit_result_2->show();

    QString expression = ui->lineEdit->text();
    qDebug() << expression;

    QString indicator = "1";
    if (expression.isEmpty())
    {
        indicator = "-179";
    }
    int result = m_mojbroj->submitSolution(expression, indicator);
    ui->lineEdit_result->setText(QString::number(result));

    QString round = ui->label_round->text();
    if (round == "Round 1")
    {
        ui->pushButton_nextRound->show();
        //bodovi1
    } else
    {
        ui->pushButton_nextGame->show();
        //bodovi2
    }
}

void Mojbroj::buttonPressedNextRound()
{
    QPushButton *newRound = ui->pushButton_nextRound;
    if (newRound->text() == "ZAPOCNI IGRU")
    {
        newRound->hide();
        newRound->setText("NOVA RUNDA");
        initGame();
        return;
    }

    deinitGame();
    newRound->hide();
    time = 30;
    ui->label_time->setText(QString::number(time));
    timer->start();

    ui->label_round->setText("Round 2");
}

void Mojbroj::del()
{
    QPair<QString,QString> pair = m_mojbroj->deleteLastInput();
    qDebug() << "OBRISANO: " << pair.second;
    ui->lineEdit->setText(pair.first);

    QHBoxLayout *horizontalLayout = ui->horizontalLayout_numbers;
    for (int i = 0; i < horizontalLayout->count(); i++)
    {
        QPushButton *button = qobject_cast<QPushButton*>(horizontalLayout->itemAt(i)->widget());
        if (button && !button->isEnabled() && button->text()==pair.second)
        {
            qDebug() << "VRACEN BROJ: " << pair.second;
            button->setEnabled(true);
        }
    }
    //iteracija krox Hlayout za dugmice
    /*
    QVector<QString> expression = m_mojbroj->currentExpression;
    QString expression = ui->lineEdit->text();

    if(!expression.isEmpty())
    {
        expression.chop(1);
        ui->lineEdit->setText(expression);
    } */
}

void Mojbroj::setNumbers()
{
    QVector<int> initialNumbers = m_mojbroj->availableNumbers;
    ui->pushButton_num1->setText(QString::number(initialNumbers[0]));
    ui->pushButton_num2->setText(QString::number(initialNumbers[1]));
    ui->pushButton_num3->setText(QString::number(initialNumbers[2]));
    ui->pushButton_num4->setText(QString::number(initialNumbers[3]));
    ui->pushButton_num5->setText(QString::number(initialNumbers[4]));
    ui->pushButton_num6->setText(QString::number(initialNumbers[5]));

    int targetNumber = m_mojbroj->targetNumber;

    ui->textEdit->clear();
    ui->textEdit->setText(QString::number(targetNumber));
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void Mojbroj::setButtonStatus(bool enabled)
{
    ui->pushButton_num1->setEnabled(enabled);
    ui->pushButton_num2->setEnabled(enabled);
    ui->pushButton_num3->setEnabled(enabled);
    ui->pushButton_num4->setEnabled(enabled);
    ui->pushButton_num5->setEnabled(enabled);
    ui->pushButton_num6->setEnabled(enabled);
    ui->pushButton_add->setEnabled(enabled);
    ui->pushButton_sub->setEnabled(enabled);
    ui->pushButton_mul->setEnabled(enabled);
    ui->pushButton_div->setEnabled(enabled);
    ui->pushButton_leftBr->setEnabled(enabled);
    ui->pushButton_rightBr->setEnabled(enabled);
    ui->pushButton_del->setEnabled(enabled);
    ui->pushButton_submit->setEnabled(enabled);
}

//TIMER
void Mojbroj::on_timesUp()
{
    qDebug() << "ISTEKLO VREME poziv na 2.rundu";
    buttonPressedSubmit();

    //bodovi1 u buttonPressedSubmit?
}

void Mojbroj::on_gameEnd()
{
    buttonPressedSubmit();
    //bodovi2 u buttonPressedSubmit?
    //ukupna dodela? (na server?)
    qDebug() << "on_gameEnd kraj 2.runde i cele igre";
}

void Mojbroj::updateTime()
{
    if (time >= 0)
    {
        ui->label_time->setText(QString::number(time));
    }

    if (time-- == 0)
    {
        qDebug() << ui->label_round->text();
        if(ui->label_round->text() == "Round 2")
        {
            qDebug() << "poziv za on_gameEnd";
            emit gameEnd();
        } else
        {
            qDebug() << "poziv za on_timesUp";
            emit timesUp();
        }
    }
}
