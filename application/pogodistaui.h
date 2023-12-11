#ifndef POGODISTAUI_H
#define POGODISTAUI_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include "pogodista.h"

namespace Ui {
class PogodiStaUI;
}

class PogodiStaUI : public QWidget
{
    Q_OBJECT

public:
    explicit PogodiStaUI(QWidget *parent = nullptr);
    ~PogodiStaUI();

    void startGame();

private slots:
    void updateTimer();
    void onGuessSubmit();


private:
    Ui::PogodiStaUI *ui;
    PogodiSta *pogodiSta;
    QPixmap updatedImage;
    QTimer *gameTimer;
    int gameTime;
    const int pixelStep = 8;
    int pixelSize;
    int roundNumber;
    int points;

    void setBackground();
    QPixmap pixelateImage(const QPixmap original, int pixelSize);
    void sleep(int time);
};

#endif // POGODISTAUI_H
