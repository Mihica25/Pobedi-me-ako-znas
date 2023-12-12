#include "podrundaui.h"
#include "ui_podrundaui.h"
#include "podrunda.h"
#include <QDebug>

Podrundaui::Podrundaui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Podrundaui)

{
    getUi()->setupUi(this);
    setBackground();

    Podrunda podrunda;

    connect(getUi()->pbOdgovori , &QPushButton::clicked, this, &Podrundaui::on_pbOdgovori);

    timer = new QTimer(this);
    time = 20;
    getUi()->labTimer->setText(QString::number(time));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, &Podrundaui::timesUp, this, &Podrundaui::on_timesUp);
    connect(this, &Podrundaui::gameEnded, this, &Podrundaui::on_gameEnded);


    timer->start(1000);
    this->getQuestion();

}


Podrundaui::~Podrundaui()
{
    delete ui;
}


Ui::Podrundaui *Podrundaui::getUi()
{
    return ui;
}


void Podrundaui::setBackground()
{
    getUi()->setupUi(this);
    QPixmap bkgnd(":background/resources/ko_zna.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


void Podrundaui::on_pbOdgovori()
{
    disableUI();
    displayAnswer();
}


void Podrundaui::getQuestion()
{
    podrunda.setAnswerQuestion("Koliko slova ima azbuka?", 30);
    displayQuestion();
}


void Podrundaui::displayQuestion()
{
    enableUI();
    const QString pitanje = podrunda.getAnswerQuestion().first;
    getUi()->labPitanje->setText(pitanje);
    getUi()->labPitanje->setAlignment(Qt::AlignCenter);
    getUi()->labPitanje->setStyleSheet("background-color::yellow;");
}


void Podrundaui::displayAnswer()
{
    if(isNumberGuessed())
    {
        const QString tacno = "Bravo, odgovorili ste tacno!";
        getUi()->labTacanOdgovor->setText(tacno);
        getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
        getUi()->labTacanOdgovor->setStyleSheet("background-color:green");

    }
    else
    {
        double correctAnswer = podrunda.getAnswerQuestion().second;
        double absDiff = qAbs(correctAnswer - podrunda.guess);
        QString razlika = QString::number(absDiff);
        const QString netacno = "Nazalost, pogresili ste za " + razlika + "!";
        getUi()->labTacanOdgovor->setText(netacno);
        getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
        getUi()->labTacanOdgovor->setStyleSheet("background-color:red");

    }

    timer->stop();
    getUi()->labTimer->clear();

    adjustResultLabel();
    disableUI();
}


void Podrundaui::disableUI()
{
    getUi()->pbOdgovori->setDisabled(true);
    getUi()->teOdgovor->setDisabled(true);
}


void Podrundaui::enableUI()
{
    getUi()->pbOdgovori->setEnabled(true);
    getUi()->teOdgovor->setEnabled(true);
    getUi()->teOdgovor->setAlignment(Qt::AlignCenter);
}


void Podrundaui::notifyServer()
{
}


bool Podrundaui::isNumberGuessed()
{
    podrunda.guess = getUi()->teOdgovor->toPlainText().toDouble();
    double correctAnswer = podrunda.getAnswerQuestion().second;
    if (podrunda.guess == correctAnswer)
        return true;
    else
        return false;
}


void Podrundaui::updateTime()
{
    if (time >= 0){
        getUi()->labTimer->setText(QString::number(time));
        getUi()->labTimer->setAlignment(Qt::AlignCenter);
    }

    if(--time == 0){
        emit timesUp();
    }
}


void Podrundaui::on_timesUp()
{
    emit gameEnded();
}


void Podrundaui::on_gameEnded(){
    timer->stop();

    QString nula = "0";
    getUi()->labTimer->setText(nula);
    getUi()->labTimer->setAlignment(Qt::AlignCenter);
    getUi()->labTimer->setStyleSheet("background-color:red");

    double numAnswer = podrunda.getAnswerQuestion().second;
    QString correctAnswer = QString::number(numAnswer);
    const QString poruka = "Niste odgovorili na pitanje! Tacan odgovor je: " + correctAnswer;
    getUi()->labTacanOdgovor->setText(poruka);
    getUi()->labTacanOdgovor->setAlignment(Qt::AlignCenter);
    getUi()->labTacanOdgovor->setStyleSheet("background-color:red");
    adjustResultLabel();

    disableUI();
}

void Podrundaui::adjustResultLabel()
{
    QFontMetrics metrics(getUi()->labTacanOdgovor->font());
    QSize textSize = metrics.size(Qt::TextSingleLine, getUi()->labTacanOdgovor->text());
    getUi()->labTacanOdgovor->setFixedSize(textSize);
}
