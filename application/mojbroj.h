#ifndef MOJBROJ_H
#define MOJBROJ_H

#include "mojbrojlogic.h"
#include <QWidget>

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


private slots:
    void buttonPressedNum();
    void buttonPressedOp();
    void del();
};

#endif // MOJBROJ_H
