#ifndef MOJBROJ_H
#define MOJBROJ_H

#include "mojbrojlogic.h"
#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsBlurEffect>

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

    void initGame();
    void deinitGame();
    void setNumbers();
    void setButtonStatus(bool enabled);


private slots:
    void pressedStart();
    void buttonPressedNum();
    void buttonPressedOp();
    void buttonPressedSubmit();
    void buttonPressedNextRound();
    void del();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

 private:
    QGraphicsBlurEffect *blurEffect;
};

#endif // MOJBROJ_H
