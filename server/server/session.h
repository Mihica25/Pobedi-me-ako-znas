#ifndef SESSION_H
#define SESSION_H

#include <QTcpServer>
#include <QDebug>
#include "player.h"
#include <string>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QRandomGenerator>
#include <QStringList>
#include <QVector>
#include <QFile>
#include <QDateTime>
#include <QList>


class Session : public QObject
{
    Q_OBJECT

public:
    Session(Player *player1, Player *player2, QStringList reckoChoosenWords, QObject *parent = nullptr);
    ~Session();

    void sendMessageToPlayer1(QString message);
    void sendMessageToPlayer2(QString message);
    void sendMessageToBothPlayers(QString message);
    Player* getPlayer1();
    Player* getPlayer2();


private slots:
    void player1ReadyReadRecko();
    void player2ReadyReadRecko();
    void player1ReadyReadMojBroj();
    void player2ReadyReadMojBroj();
    void player1ReadyReadKoZna();
    void player2ReadyReadKoZna();
    void player1ReadyReadPodrunda();
    void player2ReadyReadPodrunda();
    void player1ReadyReadPogodiSta();
    void player2ReadyReadPogodiSta();
    void player1ReadyReadMemorija();
    void player2ReadyReadMemorija();

private:
    Player *player1;
    Player *player2;
    QStringList reckoWords;
    QVector<int> generatedCards;
    QString recko;
    int reckoGameNo;
    int reckoPoints;
    int reckoWordNo;
    QString targetNumber;
    QString initialNumbers;
    QString player1_res;
    QString player2_res;
    int submit_mojbroj;
    int gameEnd_mojbroj;

    QString pitanjce;
    QString currentDir;
    QString answer1;
    QString answer2;
    int points1;
    int points2;
    QString pogodiSta;

    void startGame();
    void startRecko();
    void stopRecko();
    void startMojBroj();
    void stopMojBroj();
    void startPogodiSta();
    void startKoZna();
    void stopKoZna();
    void startPodrunda();
    void otvoriPodrundu();
    void stopPodrunda();
    void stopPogodiSta();
    void startMemorija();
    void stopMemorija();

    void shuffleQVector(QVector<int> &vector);
    QVector<int> generateCardIds();
    void processMemorijaMessage(const QString& request);
    void processReckoMessage(const QString& msg);
    QString checkReckoSolution(const QString& word);
    void processMojBrojMessage(const QString& msg);
    void checkMojBrojSolution(const QString& pt1, const QString& pt2);

    QString generateTargetNumber();
    QString generateInitialNumbers();
    void generateQuestions();

    void processPogodiStaMessage(const QString& msg, Player* player);
    void generatePogodiSta();

    void processKoZnaMessage(const QString& msg, int num);
    QString checkKoZnaSolution(const QString& word);
    int checkPodrundaWinner();
    void processPodrundaMessage(const QString& msg, const int num);

    void saveResult(const QString &player1Name, int player1Points, const QString &player2Name, int player2Points);

};

#endif // SESSION_H
