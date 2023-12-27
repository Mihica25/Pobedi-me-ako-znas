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
    PogodiSta(int index, QString info_m, QString answ);

    QString getAnswer() const;

    QString getInfo() const;

    QPixmap getGuessingImage() const;

    int calculatePoints(int roundNumber);

    void setAnswer(const QString &newAnswer);

    void setInfo(const QString &newInfo);
private:
    QString answer;
    QString info;
    QPixmap guessingImage;

    void loadRandomImage(const int index = -1);
};

#endif // POGODISTA_H
