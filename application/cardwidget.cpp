#include "cardwidget.h"
#include <QPainter>
#include <QTimer>

CardWidget::CardWidget(int id,int idR, QWidget *parent):
    QWidget(parent),
    cardId(id),
    isRevealed(false),
    idReveal(idR)
{
    QString imagePath = ":kartice/resources/kartice_memorija/image" + QString::number(id) + ".jpg";
    cardImage = QPixmap(imagePath);

    setFixedSize(150,150);
}

int CardWidget::getId() const {
    return cardId;
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
        QColor color = QColor("limegreen");
        painter.fillRect(0,0,width(),height(),color);
    }

    QWidget::paintEvent(event);
}
