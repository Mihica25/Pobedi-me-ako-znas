#include "memorija.h"
#include "ui_memorija.h"
#include <QWidget>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QDebug>
#include <random>

Memorija::Memorija(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memorija)
{
    ui->setupUi(this);

    hideTimer = new QTimer(this);

    QPixmap bkgnd("/home/user/Desktop/pobedi-me-ako-znas/application/resources/igra_memorije.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    initializeGame();
}

Memorija::~Memorija()
{
    delete ui;
}


void Memorija::initializeGame()
{

    cardIds = generateCardIds();
    int indeks = 0;

    QGridLayout *gridLayout = ui->gridLayout;

    // Create instances of your CardWidget class and populate the grid
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {

            // Access the existing placeholder widget directly from the UI
            QWidget *placeholder = gridLayout->itemAtPosition(row, col)->widget();

            // Create an instance of your CardWidget class
            int cardId = cardIds[indeks];
            CardWidget *cardWidget = new CardWidget(cardId,indeks, placeholder);

            // Connect the cardClicked signal to the onCardClicked slot
            connect(cardWidget, &CardWidget::clicked, this, &Memorija::onCardClicked);

            // Map cardId to the corresponding CardWidget
            cardIdToWidget[indeks] = cardWidget;
            indeks++;
        }
    }
}

void Memorija::shuffleQVector(QVector<int> &vector){
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vector.begin(),vector.end(),g);
};

QVector<int> Memorija::generateCardIds(){
    QVector<int> ids;

    for(int i = 1; i <= 10; ++i){
        ids.append(i);
        ids.append(i);
    }

    shuffleQVector(ids);
    return ids;
}

void Memorija::onCardClicked(int idReveal){
    if (turnedCards.size() >= 2 || turnedCards.contains(idReveal)){
        return;
    }

    CardWidget *clickedCard = cardIdToWidget.value(idReveal,nullptr);

    if(!clickedCard){
        return;
    }

    clickedCard->reveal();

    turnedCards.append(idReveal);

    if(turnedCards.size() == 2){
        if(checkForMatch()){
            ++pairsFound;
        }else{
            hideUnmatchedCards();
        }
        resetTurnedCards();

        if(pairsFound == totalPairs){
            //TODO
        }
    }
}

void Memorija::hideUnmatchedCards(){
    hideTimer->start(1000);

    connect(hideTimer, &QTimer::timeout, this,[this](){
        for(int idReveale : turnedCards){
            cardIdToWidget.value(idReveale,nullptr)->hide();
        }
        hideTimer->stop();
    });
}

bool Memorija::checkForMatch(){
   int card1 =  cardIdToWidget.value(turnedCards[0],nullptr)->getId();
   int card2 = cardIdToWidget.value(turnedCards[1],nullptr)->getId();

   return (card1 == card2);
}


void Memorija::resetTurnedCards(){
    turnedCards.clear();
}
