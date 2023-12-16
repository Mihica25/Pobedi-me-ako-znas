#ifndef PODRUNDAUI_H
#define PODRUNDAUI_H

#include <QWidget>
#include "podrunda.h"
#include <QTimer>

namespace Ui {
class Podrundaui;
}

class Podrundaui : public QWidget
{
    Q_OBJECT

public:
    explicit Podrundaui(QWidget *parent = nullptr);
    ~Podrundaui();

private:
    Ui::Podrundaui *ui;
    Ui::Podrundaui *getUi();
    void on_pbOdgovori();
    void getQuestion();
    void displayQuestion();
    void displayAnswer();
    void notifyServer();
    void disableUI();
    void enableUI();
    bool isNumberGuessed();
    void setBackground();
    void adjustResultLabel();

    //std::pair<QString, double> getAnswerQuestion() const;
    //void setAnswerQuestion(QString pitanje, double odgovor);

    //std::pair<QString, double> answerQuestion;
    Podrunda podrunda;
    QTimer *timer;
    int time;

signals:
    void timesUp();
    void gameEnded();

public slots:
    void updateTime();
    void on_timesUp();
    void on_gameEnded();


};

#endif // PODRUNDAUI_H
