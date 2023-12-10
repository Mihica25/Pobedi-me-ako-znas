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

    void setNumbers();
    void initGame();

private slots:
    void buttonPressed();
    void del();
};

#endif // MOJBROJ_H
