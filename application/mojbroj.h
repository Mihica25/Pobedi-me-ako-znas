#ifndef MOJBROJ_H
#define MOJBROJ_H

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
};

#endif // MOJBROJ_H
