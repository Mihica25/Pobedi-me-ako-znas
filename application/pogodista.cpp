#include "pogodista.h"

PogodiSta::PogodiSta() {
    loadRandomImage();
}

QString PogodiSta::getAnswer() const
{
    return answer;
}

QString PogodiSta::getInfo() const
{
    return info;
}

QPixmap PogodiSta::getGuessingImage() const
{
    return guessingImage;
}


void PogodiSta::loadRandomImage()
{
    QDir imageDir(":/guess_img/resources/guessing_images/");
    QFileInfoList images = imageDir.entryInfoList(QDir::Files);
    if (!images.isEmpty()){
        int randomIndex = QRandomGenerator::global()->bounded(images.size());
        QString imagePath = images[randomIndex].filePath();
        QStringList data = images[randomIndex].fileName().split(",");
        answer = data[0];
        info = "\"" + data[1].split(".")[0] + "\"";
        guessingImage.load(imagePath);
    }
}

int PogodiSta::calculatePoints(int roundNumber)
{
    return 5 * roundNumber;
}
