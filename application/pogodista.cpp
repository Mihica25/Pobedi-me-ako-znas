#include "pogodista.h"
#include <QDebug>
#include <typeinfo>

PogodiSta::PogodiSta()
{
    loadRandomImage();
}

PogodiSta::PogodiSta(int index, QString info_m, QString answ)
{
    loadRandomImage(index);
    info = info_m;
    answer = answ;
}

void PogodiSta::setAnswer(const QString &newAnswer)
{
    answer = newAnswer;
}

QString PogodiSta::getAnswer() const
{
    return answer;
}

void PogodiSta::setInfo(const QString &newInfo)
{
    info = newInfo;
}

QString PogodiSta::getInfo() const
{
    return info;
}

QPixmap PogodiSta::getGuessingImage() const
{
    return guessingImage;
}

void PogodiSta::loadRandomImage(const int index)
{
    QDir imageDir(":/guess_img/resources/guessing_images/");
    QFileInfoList images = imageDir.entryInfoList(QDir::Files);
    if (!images.isEmpty())
    {
        QString imagePath;
        if (index == -1)
        {
            int randomIndex = QRandomGenerator::global()->bounded(images.size());
            imagePath = images[randomIndex].filePath();
            QStringList data = images[randomIndex].fileName().split(",");
            answer = data[0];
            info = "\"" + data[1].split(".")[0] + "\"";
        }
        else
        {
            imagePath = images[index].filePath();
        }
        guessingImage.load(imagePath);
        qDebug() << imagePath << " " << QString::number(index);
    }
}

int PogodiSta::calculatePoints(int roundNumber)
{
    return 5 * roundNumber;
}
