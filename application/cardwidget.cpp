#include "cardwidget.h"
#include <QPainter>
#include <QTimer>

CardWidget::CardWidget(int id,int idR, QWidget *parent):
    QWidget(parent),
    cardId(id),
    isRevealed(false),
    idReveal(idR)
{
    QString imagePath = "/home/user/Desktop/pobedi-me-ako-znas/application/resources/kartice_memorija/image" + QString::number(id) + ".jpg";
    cardImage = QPixmap(imagePath);

    //set size
}

int CardWidget::getId() const {
    return cardId;
}

void CardWidget::hideWithDelay(int delay){
    isRevealed = false;
    QTimer::singleShot(delay, this, &CardWidget::hide);
}

void CardWidget::hide(){
    isRevealed = false;
    repaint();
}

void CardWidget::reveal(){
    isRevealed = true;
    repaint();
}

void CardWidget::mousePressEvent(QMouseEvent *event){
    if(!isRevealed){
        reveal();
        emit clicked(idReveal);
    }
    QWidget::mousePressEvent(event);
}

void CardWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    if (isRevealed){
        painter.drawPixmap(0,0,width(),height(),cardImage);
    } else {
        painter.fillRect(0,0,width(),height(),Qt::green);
    }

    QWidget::paintEvent(event);
}
