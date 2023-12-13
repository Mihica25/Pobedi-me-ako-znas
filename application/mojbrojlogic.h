#ifndef MOJBROJLOGIC_H
#define MOJBROJLOGIC_H

#include <QVector>
#include <QString>
#include <QPair>

enum class GamePhase
{
    Round1,
    Round2,
    End
};

class MojBrojLogic
{
public:
    MojBrojLogic();
    ~MojBrojLogic()=default;

    void startGame();
    bool endGame();
    void chooseNumber(int number);
    void chooseOperation(const QString& operation);
    int submitSolution(const QString& solution, const QString& indicator);
    QPair<QString,QString> deleteLastInput();

    void test();

    int targetNumber;
    QVector<int> availableNumbers;
    QVector<QString> currentExpression;

private:
    QVector<QString> availableOperations;
    GamePhase currentRound;

    int generateTargetNumber();
    QVector<int> generateInitialNumbers();

    QString vectorToString(const QVector<QString>& vec);
    bool validateExpression(const QString& expression) const;
    int evaluateExpression(const QString& expression) const;

};

#endif // MOJBROJLOGIC_H
