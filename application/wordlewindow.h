#ifndef WORDLEWINDOW_H
#define WORDLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class WordleWindow;
}

class WordleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WordleWindow(QWidget *parent = 0);
    ~WordleWindow();

private:
    Ui::WordleWindow *ui;
};

#endif // WORDLEWINDOW_H
