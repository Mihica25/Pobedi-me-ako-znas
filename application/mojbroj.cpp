#include "mojbroj.h"
#include "ui_mojbroj.h"
#include "mojbrojlogic.h"

#include <QDebug>
#include <QFont>
#include <QGraphicsBlurEffect>
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

 /*   blurEffect = new QGraphicsBlurEffect(this);
    blurEffect->setBlurRadius(5);
    setGraphicsEffect(blurEffect);
*/
    //TIMER
    time = 30;
    ui->label_time->setText(QString::number(time));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &Mojbroj::timesUp, this, &Mojbroj::on_timesUp);
    connect(this, &Mojbroj::gameEnd, this, &Mojbroj::on_gameEnd);

    timer->start(1000);
    qDebug() << "POCETAK IGRE";

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

    ui->pushButton_nextRound->hide();
    ui->pushButton_nextGame->hide();

    ui->textEdit_startGame->hide(); //remove if there is no blur effect
/*    QTextEdit *start= ui->textEdit_startGame;
    start->setText("START GAME");
    start->append("\t\t(press enter)");
    start->setReadOnly(true);
    start->setAlignment(Qt::AlignCenter);

    qApp->installEventFilter(this);
*/
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

    initGame();
  //  deinitGame();
/*  TIMER
    QTimer *timer = new QTimer(this);
    timer->start(10000);
    connect(timer, &QTimer::timeout, this, &Mojbroj::deinitGame);
*/
}

void Mojbroj::initGame()
{
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

/*
void Mojbroj::pressedStart()
{

    setButtonStatus(true);

    blurEffect->setEnabled(false);
    ui->textEdit_startGame->hide();
    initGame();
}
*/
void Mojbroj::buttonPressedNum()
{

    QVector<QString> currentExpression = m_mojbroj->currentExpression;
    if(!currentExpression.isEmpty())
    {
        QString lastElement = currentExpression.back();

        bool isInt;
        int intValue = lastElement.toInt(&isInt);

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
// : 25+4*3***4+
//0: 1 010100010

void Mojbroj::buttonPressedNextRound()
{
    deinitGame();
    ui->pushButton_nextRound->hide();

    time = 30;
    ui->label_time->setText(QString::number(time));
    timer->start();

    ui->label_round->setText("Round 2");
}

//FIXME
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

    ui->textEdit->clear();
    ui->textEdit->setText(QString::number(targetNumber));
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

/*
bool Mojbroj::eventFilter(QObject *watched, QEvent *event)
{
    if(enterEventEnabled && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if(keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
        {
            pressedStart();
            enterEventEnabled = false;
            return true;
        }
    }

    return QObject::eventFilter(watched,event);
}
*/

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
