#ifndef MOJBROJLOGIC_HPP
#define MOJBROJLOGIC_HPP

#include <vector>
#include <string>

enum class GamePhase
{
    Round1,
    Round2,
    End
};

class MojBroj
{
public:
    MojBroj() = default;
    virtual ~MojBroj() = default;

    void startGame();
    void endGame();
    void chooseNumber(int number);
    void chooseOperation(const std::string& operation);
    void submitSolution(const std::string& solution);
    void deleteLastInput();

    void test();

private:
    int targetNumber;
    std::vector<int> availableNumbers;
    std::vector<std::string> availableOperations;
    std::string currentExpression;
    GamePhase currentRound = GamePhase::Round1;

    int generateTargetNumber();
    std::vector<int> generateInitialNumbers();

    bool validateExpression(const std::string& expression) const;
    int evaluateExpression(const std::string& expression) const;
};

#endif // MOJBROJLOGIC_HPP
