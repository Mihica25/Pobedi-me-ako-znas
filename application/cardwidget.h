#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>

class CardWidget : public QWidget{
    Q_OBJECT

public:
    explicit CardWidget(int id, int idR,QWidget *parent = nullptr);

    int getId() const;
    void reset();
    void hide();

signals:
    void clicked(int idR);

public slots:
    void reveal();
    void hideWithDelay(int delay);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    int cardId;
    QPixmap cardImage;
    bool isRevealed;
    int idReveal;
};

#endif // CARDWIDGET_H
