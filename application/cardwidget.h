#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QMouseEvent>
#include <QPixmap>
#include <QWidget>

class CardWidget : public QWidget
{
  Q_OBJECT

public:
  explicit CardWidget (int id, int idR, QWidget *parent = nullptr);

  int getId () const;

signals:
  void clicked (int idR);

public slots:
  void reveal ();
  void hide ();

protected:
  void mousePressEvent (QMouseEvent *event) override;
  void paintEvent (QPaintEvent *event) override;

private:
  int cardId;
  QPixmap cardImage;
  bool isRevealed;
  int idReveal;
};

#endif // CARDWIDGET_H
