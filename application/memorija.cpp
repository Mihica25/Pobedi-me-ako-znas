#include "memorija.h"
#include "ui_memorija.h"
#include <QGridLayout>
#include <QMessageBox>

Memorija::Memorija(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memorija)
{
    ui->setupUi(this);

    hideTimer = new QTimer(this);
    connect(hideTimer,&QTimer::timeout,this, &Memorija::onHideTimerTimeout);

    QPixmap bkgnd("/home/user/Desktop/pobedi-me-ako-znas/application/resources/igra_memorije.png");
    bkgnd  = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QWidget *layoutWidget = ui->layoutWidget;

    //Create a new QGridLayout
    QGridLayout *gridLayout = new QGridLayout(layoutWidget);
    layoutWidget->setLayout(gridLayout);

    //Set uo the game board()
    initializeGame();
}

Memorija::~Memorija()
{
    delete ui;
}

void Memorija::initializeGame(){

    cardIds = generateCardIds();
    int index = 0;

    // Create and add CardWidget instances to the grid layout
    for (int row = 0; row < numRows; ++row){
        for (int col = 0; col < numCols; ++col){
            CardWidget *card = new CardWidget(cardIds[index]);
            cardWidgets.push_back(card);
            cardIdToWidget.insert(index,card);
            connect(card, &CardWidget::clicked, this, &Memorija::onCardClicked);
            ui->gridLayout->addWidget(card,row,col);
            ++index;
        }
    }
}

QVector<int> Memorija::generateCardIds(){
    QVector<int> ids;

    for(int i = 1; i <= 10; ++i){
        ids.append(i);
        ids.append(i);
    }

    std::random_shuffle(ids.begin(),ids.end());
    return ids;
}

void Memorija::onCardClicked(int cardId){
    if(turnedCards.size() < 2){
        CardWidget* card = cardIdToWidget.value(cardId);

        if(card){
            turnedCards.push_back(cardId);

            if(turnedCards.size() == 2){
                if(checkForMatch()){
                    turnedCards.clear();
                }else{
                   resetTurnedCards();
                }
            }
        }
    }
}

void Memorija::hideUnmatchedCards(){
    hideTimer->start(1000);
}

void Memorija::onHideTimerTimeout(){
    hideTimer->stop();
}
bool Memorija::checkForMatch(){
   int card1 = turnedCards[0];
   int card2 = turnedCards[1];

   return (card1 == card2);
}


void Memorija::resetTurnedCards(){
    int cardId1 = turnedCards[0];
    int cardId2 = turnedCards[1];

    CardWidget *card1 = cardIdToWidget.value(cardId1);
    CardWidget *card2 = cardIdToWidget.value(cardId2);

    if(card1 && card2){
        card1->hideWithDelay(1000);
        card2->hideWithDelay(1000);
    }

    hideTimer->start(1000);
}
