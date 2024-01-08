#ifndef MOJBROJLOGIC_H
#define MOJBROJLOGIC_H

#include <QPair>
#include <QString>
#include <QVector>

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
    ~MojBrojLogic() = default;

    bool endGame();
    void chooseNumber(int number);
    void chooseOperation(const QString &operation);
    int submitSolution(const QString &solution, const QString &indicator);
    QPair<QString, QString> deleteLastInput();

    QVector<int> availableNumbers;
    QVector<QString> currentExpression;
    GamePhase getCurrentRound();
    int getTargetNumber();
    void setTargetNumber(int tn);

  private:
    QVector<QString> availableOperations;
    GamePhase currentRound;
    int targetNumber;

    QString vectorToString(const QVector<QString> &vec);
    bool validateExpression(const QString &expression) const;
    int evaluateExpression(const QString &expression) const;
};

#endif // MOJBROJLOGIC_H
