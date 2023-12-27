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

Mojbroj::Mojbroj(QWidget *parent, QTcpSocket* tcpSocket,
                 QString player1_, QString player2_, bool red,
                 int player1Points_, int player2Points_):
    QWidget(parent),
    ui(new Ui::Mojbroj),
    timer(new QTimer(this))
{
    server = tcpSocket;
    multiplayer = true;
    player1 = player1_;
    player2 = player2_;
    turn = red;
    playerNo = turn;
    player1Points = player1Points_;
    player2Points = player2Points_;
    ui->setupUi(this);


    ui->label_player1->setText(QString::number(player1Points));
    ui->label_player2->setText(QString::number(player2Points));

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
    ui->label_player1->hide();
    ui->label_player2->hide();

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
    connect(ui->pushButton_nextGame,SIGNAL(released()),this,SLOT(buttonPressedNextGame()));

    if(!turn)
    {
        ui->pushButton_nextRound->setEnabled(false);
    }

    connect(ui->pushButton_del,SIGNAL(released()),this,SLOT(del()));

    connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}


void Mojbroj::initGame()
{
    timer->start(1000);

    ui->label_round->show();
    ui->label_time->show();    
    ui->label_player1->show();
    ui->label_player2->show();

    setButtonStatus(true);
    m_mojbroj = new MojBrojLogic();

        // Ako sam ja zapoceo salji poruku da se Generisu novi
    if (turn)
    {
        // salje poruku serveru da generise brojeve
        sendMessage(server, "GENERATE:original\n");

    } else      //inace uzizmam iste
    {
        sendMessage(server, "GENERATE:copy\n");
    }

    turn = !turn;
}

void Mojbroj::deinitGame()
{
    if(m_mojbroj->endGame())
    {
        return;    //end of the game
    }

    //setNumbers();
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

    setButtonStatus(false);
    submit++;

    ui->lineEdit_2->show();
    ui->lineEdit_result_2->show();

    QString expression = ui->lineEdit->text();


    QString indicator = "1";
    if (expression.isEmpty())
    {
        indicator = "-1179";
    }
    int result = m_mojbroj->submitSolution(expression, indicator);

    if (result == -1179 || result == -1951)
        ui->lineEdit_result->setText("x");
    else
        ui->lineEdit_result->setText(QString::number(result));

    sendMessage(server, "EXPRESSION:" + player1 + "%" + expression + "%" + QString::number(result) + "\n");

    sendMessage(server, "RESULT:"+ player1 + "%" + QString::number(result) + "\n");

    QString round = ui->label_round->text();
    if (round == "Round 1")
    {
        ui->pushButton_nextRound->show();

        if(!turn)
        {
            ui->pushButton_nextRound->setEnabled(false);
        } else
        {
            ui->pushButton_nextRound->setEnabled(true);
        }
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
        // Ako sam ja zapoceo, salji poruku serveru da obavesti drugog igraca da i on poziva buttonPressedNextRound
        if(turn)
        {
            sendMessage(server, "START GAME:" + this->player2.toUtf8() + "\n");
        }

        newRound->hide();
        newRound->setText("NOVA RUNDA");
        initGame();
        return;
    } else if (turn)
    {
        if (submit != 2)
            return;

        sendMessage(server, "START GAME:" + this->player2.toUtf8() + "\n");

        sendMessage(server, "GENERATE:original\n");
    } else
    {
        sendMessage(server, "GENERATE:copy\n");
    }


    deinitGame();
    newRound->hide();
    time = 30;
    ui->label_time->setText(QString::number(time));
    timer->start();

    ui->label_round->setText("Round 2");
}

void Mojbroj::buttonPressedNextGame()
{
    ui->pushButton_nextGame->hide();
    sendMessage(server, "GAME END\n");
}

void Mojbroj::del()
{
    QPair<QString,QString> pair = m_mojbroj->deleteLastInput();

    ui->lineEdit->setText(pair.first);

    QHBoxLayout *horizontalLayout = ui->horizontalLayout_numbers;
    for (int i = 0; i < horizontalLayout->count(); i++)
    {
        QPushButton *button = qobject_cast<QPushButton*>(horizontalLayout->itemAt(i)->widget());
        if (button && !button->isEnabled() && button->text()==pair.second)
        {
            button->setEnabled(true);
        }
    }

}

void Mojbroj::setNumbers()
{
    //od servera primi brojeve sve i target i available
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

int Mojbroj::getPlayer1Points(){
    return player1Points;
}

int Mojbroj::getPlayer2Points(){
    return player2Points;
}

//TIMER
void Mojbroj::on_timesUp()
{
    buttonPressedSubmit();
}

void Mojbroj::on_gameEnd()
{
    buttonPressedSubmit();
}

void Mojbroj::updateTime()
{
    if (time >= 0)
    {
        ui->label_time->setText(QString::number(time));
    }

    if (time-- == 0)
    {

        if(ui->label_round->text() == "Round 2")
        {
            emit gameEnd();
        } else
        {
            emit timesUp();
        }
    }
}


//SERVER
void Mojbroj::onReadyRead() {
    QByteArray data = server->readAll();
    QString msg = QString::fromUtf8(data);

    QStringList receivedMessages = msg.split('\n');

    for (const QString& receivedMessage : receivedMessages) {
        if (!receivedMessage.isEmpty()) {
            processServerMessage(receivedMessage);
        }
    }
}

void Mojbroj::processServerMessage(QString serverMessage){

    //ako zapocinje sa generate poslati su brojevi i pozovi setnumbers
    if (serverMessage.startsWith("GENERATE:")) {

        QString result = serverMessage.mid(9);

        //PRIMILI SMO BROJEVE SADA IH OBRADIMO I SALJEMO U SETNUMBERS
        QStringList lines = result.split("-");
        int lines_size = lines.size();

        m_mojbroj->targetNumber = lines[0].toInt();

        QVector<int> availableNumbers;
        for (int i=1; i<lines_size; i++)
        {
            availableNumbers.append(lines[i].toInt());
        }
        m_mojbroj->availableNumbers = availableNumbers;

        setNumbers();

    } else if (serverMessage.startsWith("START GAME"))
    {
        //pozovi mu start
        buttonPressedNextRound();

    } else if (serverMessage.startsWith("EXPRESSION:"))
    {
        QString expression = serverMessage.mid(11);

        int index = expression.indexOf('%');
        QString left = expression.left(index);
        QString right = expression.mid(index+1);

        ui->lineEdit_2->setText(left);
        if (right.toInt() == -1179 || right.toInt() == -1951)
            ui->lineEdit_result_2->setText("x");
        else
            ui->lineEdit_result_2->setText(right);
        submit++;

    } else if (serverMessage.startsWith("POINTS:"))
    {
        QString points = serverMessage.mid(7);
        int index = points.indexOf("%");



        player1Points += points.left(index).toInt();
        player2Points += points.mid(index+1).toInt();

        ui->label_player1->setText(QString::number(player1Points));
        ui->label_player2->setText(QString::number(player2Points));

    } else if (serverMessage.startsWith("GAME END")){
        //dodato
        disconnect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        emit mGameEnds();
    } else {
        qDebug() << "Unknown server message: " << serverMessage;
    }
}

void Mojbroj::sendMessage(QTcpSocket* socket, QString msg)
{
    socket->write(msg.toUtf8());
    socket->flush();
}
