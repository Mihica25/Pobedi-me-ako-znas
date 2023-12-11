#ifndef MOJBROJLOGIC_H
#define MOJBROJLOGIC_H

#include <QVector>
#include <QString>

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
    void endGame();
    void chooseNumber(int number);
    void chooseOperation(const QString& operation);
    int submitSolution(const QString& solution, const QString& indicator);
    void deleteLastInput();

    void test();

    int targetNumber;
    QVector<int> availableNumbers;

private:
    QVector<QString> availableOperations;
    QVector<QString> currentExpression;
    GamePhase currentRound;

    int generateTargetNumber();
    QVector<int> generateInitialNumbers();

    QString vectorToString(const QVector<QString>& vec);
    bool validateExpression(const QString& expression) const;
    int evaluateExpression(const QString& expression) const;

};

#endif // MOJBROJLOGIC_H
