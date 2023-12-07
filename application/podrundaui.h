#ifndef PODRUNDAUI_H
#define PODRUNDAUI_H

#include <QWidget>

namespace Ui {
class podrundaui;
}

class podrundaui : public QWidget
{
    Q_OBJECT

public:
    explicit podrundaui(QWidget *parent = nullptr);
    ~podrundaui();

private:
    Ui::podrundaui *ui;
};

#endif // PODRUNDAUI_H
