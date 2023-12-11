#ifndef POGODISTA_H
#define POGODISTA_H

#include <QDir>
#include <QFileInfoList>
#include <QRandomGenerator>
#include <QPixmap>
#include <QString>

class PogodiSta : public QObject
{
    Q_OBJECT

public:
    PogodiSta();


    QString getAnswer() const;

    QString getInfo() const;

    QPixmap getGuessingImage() const;

    int calculatePoints(int roundNumber);

private:
    QString answer;
    QString info;
    QPixmap guessingImage;

    void loadRandomImage();
};

#endif // POGODISTA_H
