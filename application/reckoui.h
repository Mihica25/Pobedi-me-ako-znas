#ifndef RECKOUI_H
#define RECKOUI_H

#include <QMainWindow>
#include "recko.h"
#include <string>
#include <QString>
#include <QTimer>

namespace Ui {
class ReckoUI;
}

class ReckoUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReckoUI(QWidget *parent = nullptr);
    ~ReckoUI();

    void setUpBackground();
    bool quess();

signals:
    void timesUp();
    void gameEnds();

public slots :
    void on_timesUp();
    void updateTime();
    void on_gameEnds();


private:
    Ui::ReckoUI *ui;
    Recko* recko;
    QTimer* tajmer;
    int time;
    int bodovi = 0;
    int ukupni_bodovi = 0;

    void on_pbPotvrdi1();
    void on_pbPotvrdi2();
    void on_pbPotvrdi3();
    void on_pbPotvrdi4();
    void on_pbPotvrdi5();

    void disableRow(int index,bool disable = true);
    void setUpRows();
    void disableSolution();
    void showSolution();
};

#endif // RECKOUI_H
