#include "lobby.h"

Lobby::Lobby(QObject *parent) : QObject(parent)
{
    players = QList<Player*>();
    reckoWordList = loadWordsFromFile(":/recko/resources/recko_words.txt");
}

Lobby::~Lobby()
{
    std::for_each(players.begin(), players.end(), [](Player* player) {
        delete player;
    });
    players.clear();
}


void Lobby::addPlayer(Player* player) {
    players.append(player);
    qDebug() << "Dodat je novi igrac u Lobby. Sada ih ima: " << getPlayersCount();

    if (getPlayersCount() >= 2) {
        auto* session = new Session(players[0], players[1],  chooseRandomWords(reckoWordList), this);

        players.removeFirst();
        players.removeFirst();
        qDebug() << "Uklonili smo igrace iz Lobby-ja nakon zavrsetka igre. Sada ih ima: " << getPlayersCount();
    }
}

const QList<Player*>& Lobby::getPlayers() const {
    return players;
}

int Lobby::getPlayersCount() const{
    return players.size();
}

QStringList Lobby::loadWordsFromFile(const QString &filePath) {
    QStringList words;

        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Nije moguće otvoriti fajl: " << file.errorString();
            return words;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();

        words = fileContent.split(" ");

        return words;
}

QStringList Lobby::chooseRandomWords(const QStringList &wordList) {
    QStringList chosenWords;

    if (wordList.size() < 2) {
        qDebug() << "Nedovoljno reči za izbor.";
        QStringList stringList;
        stringList << "NISKA" << "OBLAK";
        return stringList;
    }

    int index1 = QRandomGenerator::global()->bounded(wordList.size());
    int index2;
    do {
        index2 = QRandomGenerator::global()->bounded(wordList.size());
    } while (index2 == index1);

    chosenWords.append(wordList.at(index1));
    chosenWords.append(wordList.at(index2));

    return chosenWords;
}
