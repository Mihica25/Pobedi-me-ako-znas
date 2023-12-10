#ifndef MOJBROJLOGIC_H
#define MOJBROJLOGIC_H

#include <vector>
#include <string>

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
    void chooseOperation(const std::string& operation);
    void submitSolution(const std::string& solution, const std::string& indicator);
    void deleteLastInput();

    void test();

    std::vector<std::string> availableOperations;
    std::vector<std::string> currentExpression;
    GamePhase currentRound;

    int generateTargetNumber();
    std::vector<int> generateInitialNumbers();

    std::string vectorToString(const std::vector<std::string>& vec);
    bool validateExpression(const std::string& expression) const;
    int evaluateExpression(const std::string& expression) const;

private:
    int targetNumber;
    std::vector<int> availableNumbers;

};

#endif // MOJBROJLOGIC_H
