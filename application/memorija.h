#ifndef MEMORIJA_H
#define MEMORIJA_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include "cardwidget.h"

namespace Ui {
class Memorija;
}

class Memorija : public QWidget
{
    Q_OBJECT

public:
    explicit Memorija(QWidget *parent = nullptr);
    ~Memorija();

private slots:
    void onCardClicked(int cardId);

private:
    Ui::Memorija *ui;
    const int numRows = 4;
    const int numCols = 5;
    const int totalPairs = 10;
    int pairsFound=0;
    QVector<int> cardIds;
    QVector<int> turnedCards;
    QMap<int, CardWidget*> cardIdToWidget;

    void initializeGame();
    QVector<int> generateCardIds();
    void hideUnmatchedCards();
    bool checkForMatch();
    void resetTurnedCards();
    void shuffleQVector(QVector<int> &vector);
};

#endif // MEMORIJA_H