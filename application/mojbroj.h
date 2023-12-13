#ifndef MOJBROJ_H
#define MOJBROJ_H

#include "mojbrojlogic.h"
#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsBlurEffect>
#include <QTimer>

namespace Ui {
class Mojbroj;
}

class Mojbroj : public QWidget
{
    Q_OBJECT

public:
    explicit Mojbroj(QWidget *parent = nullptr);
    ~Mojbroj();

private:
    Ui::Mojbroj *ui;
    MojBrojLogic *m_mojbroj;
    QTimer *timer;
    int time;

    void initGame();
    void deinitGame();
    void setNumbers();
    void setButtonStatus(bool enabled);

    //QGraphicsBlurEffect *blurEffect;
   // bool enterEventEnabled;

private slots:
    //void pressedStart();
    void buttonPressedNum();
    void buttonPressedOp();
    void buttonPressedSubmit();
    void buttonPressedNextRound();
    void del();

//protected:
  //  bool eventFilter(QObject *watched, QEvent *event) override;

public slots:
    void on_timesUp();
    void on_gameEnd();
    void updateTime();

signals:
    void timesUp();
    void gameEnd();

};

#endif // MOJBROJ_H
