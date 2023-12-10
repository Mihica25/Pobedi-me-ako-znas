#include "mojbrojlogic.h"
#include <iostream>
#include <cstdlib>  // For rand() function
#include <vector>
#include <regex>
#include <string>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <stack>
#include <cctype>

/*
    TODO:
    1. solver - closest number
    2. FIXME2 - 2 consecutive numbers
*/


MojBrojLogic::MojBrojLogic()
{
    currentRound = GamePhase::Round1;
    availableOperations = {"+", "-", "*", "/", "(", ")"};
}

void MojBrojLogic::startGame()
{
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    targetNumber = generateTargetNumber();
    availableNumbers = generateInitialNumbers();

    // TODO: Implement your timer logic here

    // Test
    //test();
}

void MojBrojLogic::endGame()
{
    // TODO: Implement timer destruction logic

    // Reset variables
    targetNumber = 0;
    availableNumbers.clear();
    currentExpression.clear();

    switch (currentRound)
    {
        case GamePhase::Round1:
            currentRound = GamePhase::Round2;
            startGame();
            break;
        case GamePhase::Round2:
            currentRound = GamePhase::End;
            // TODO: Implement updateScore and next game in the queue logic
            break;
        default:
            break;
    }
}

int MojBrojLogic::generateTargetNumber()
{
    // Generate a random number between 1 and 1000
    return rand() % 999 + 1;
}

std::vector<int> MojBrojLogic::generateInitialNumbers()
{
    std::vector<int> initialNumbers;

    for (int i = 0; i < 4; ++i)
    {
        int randomNumber = rand() % 9 + 1;
        initialNumbers.push_back(randomNumber);
    }

    int fifthNumberOptions[] = {10, 15, 20};
    int fifthNumber = fifthNumberOptions[rand() % 3];
    initialNumbers.push_back(fifthNumber);

    int sixthNumberOptions[] = {25, 50, 75, 100};
    int sixthNumber = sixthNumberOptions[rand() % 4];
    initialNumbers.push_back(sixthNumber);

    return initialNumbers;
}

void MojBrojLogic::chooseNumber(int number)
{
    auto it = std::find(availableNumbers.begin(), availableNumbers.end(), number);

    if (it != availableNumbers.end())
    {
        currentExpression.push_back(std::to_string(number));
        availableNumbers.erase(it);
    }
    else
    {
        std::cout << "Broj " << number << " nije dostupan. Izaberite drugi broj." << std::endl;
    }
}

void MojBrojLogic::chooseOperation(const std::string& operation)
{
    currentExpression.push_back(operation);
}

void MojBrojLogic::deleteLastInput()
{
    if (!currentExpression.empty())
    {
        std::string lastElement = currentExpression.back();

        // Pokušaj konverzije u broj
        char* endptr;
        int number = std::strtol(lastElement.c_str(), &endptr, 10);

        if (*endptr == '\0')\
        {
            // Ako je unesen broj
            availableNumbers.push_back(number);
        }

        currentExpression.pop_back();
    }
}

std::string MojBrojLogic::vectorToString(const std::vector<std::string>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), std::string());;
}

bool MojBrojLogic::validateExpression(const std::string& expression) const
{
    std::regex consecutiveOperationsRegex("[+\\-*\\/]{2,}");
    if (std::regex_search(expression, consecutiveOperationsRegex))
    {
        std::cout << "Neispravno zadat izraz: Dve ili više računskih operacija su zajedno." << std::endl;
        return false;
    }

    std::regex startEndOperationRegex("^[+\\-*\\/]|[+\\-*\\/]$");
    if (std::regex_search(expression, startEndOperationRegex))
    {
        std::cout << "Neispravno zadat izraz: Izraz počinje ili se završava računskom operacijom." << std::endl;
        return false;
    }

    std::stack<char> brackets;

    for (char token : expression)
    {
        if (token == '(')
        {
            brackets.push(token);
        } else if (token == ')')
        {
            if (brackets.empty())
            {
                std::cout << "Neispravno zadat izraz: Neuparena zagrada ')'" << std::endl;
                return false;
            } else
            {
                brackets.pop();
            }
        }
    }

    if (!brackets.empty())
    {
        std::cout << "Neispravno zadat izraz: Neuparena zagrada '('." << std::endl;
        return false;
    }

    return true;
}

int MojBrojLogic::evaluateExpression(const std::string& expression) const
{
    if (!validateExpression(expression))
    {
        std::cout << "Neispravan postupak." << std::endl;
        return -1;  // or another specific value
    }

    auto priority = [](char op)
    {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };

    auto applyOperation = [](int a, int b, char op)
    {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0; // Invalid operation
        }
    };

    std::stack<int> numbers;
    std::stack<char> operations;

    std::istringstream iss(expression);
    char token;

    while (iss >> token)
    {
        if (isdigit(token))
        {
            iss.putback(token);
            int number;
            iss >> number;
            numbers.push(number);
        } else if (token == '(')
        {
            // Ako je otvorena zagrada, stavi operaciju na stek
            operations.push(token);
        } else if (token == ')')
        {
            // Ako je zatvorena zagrada, izvrši operacije unutar zagrada
            while (!operations.empty() && operations.top() != '(')
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                char op = operations.top();
                operations.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operations.pop();  // Skloni otvorenu zagradu sa steka
        } else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            // Ako je operator, izvrši operacije sa operatorima većim prioriteta
            while (!operations.empty() && priority(operations.top()) >= priority(token))
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                char op = operations.top();
                operations.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operations.push(token);
        }
    }

    while (!operations.empty())
    {
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        char op = operations.top();
        operations.pop();
        numbers.push(applyOperation(a, b, op));
    }

    return numbers.top();
}

void MojBrojLogic::submitSolution(const std::string& solution, const std::string& indicator)
{
    if (indicator == "-179")
    {
        // TODO: player "X" -> points to opponent?
        std::cout<<"KORISNIK PREDAO PRAZAN POSTUPAK RESAVANJA"<<std::endl;
        endGame();
        return;
    } else if (indicator == "-219")
    {
        // TODO: player "X" -> points to opponent?
        std::cout<<"KORISNIK PREKINUO POSTUPAK RESAVANJA"<<std::endl;
        endGame();
        return;

    }


    int result = evaluateExpression(solution);

    if (result == -1)
    {
        // TODO: if solution can not be parsed -> points to opponent?
        endGame();
        return;
    }

    int difference = std::abs(result - targetNumber);

    // TODO: compare results with opponent
    std::cout << "Konacni postupak: " << solution << std::endl;
    std::cout << "Rastojanje od traženog broja je: " << difference << std::endl;
    std::cout << "---------------------------\n" << std::endl;

    endGame();
}

void MojBrojLogic::test()
{
    // Ispisujemo dobijene vrednosti u toku igre
    std::cout << "---------------------"<<std::endl;
    std::cout << "| Traženi broj: " << targetNumber << " |"<< std::endl;
    std::cout << "---------------------"<<std::endl;

    std::string indicator;
    std::string expression;
    std::string userInput;

    // Unos brojeva i operacija sve dok ne unesemo slovo X
    while (true)
    {
        // Prikazujemo trenutni izraz
        expression = vectorToString(currentExpression);
        std::cout << "Trenutni izraz: " << expression << std::endl;

        // Ispisujemo dostupne brojeve i operacije
        std::cout << "Dostupni brojevi: ";
        for (int num : availableNumbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        std::cout << "Dostupne operacije: ";
        for (const std::string& op : availableOperations)
        {
            std::cout << op << " ";
        }
        std::cout << std::endl;

        // Korisnik unosi broj, operaciju ili "del" za brisanje poslednjeg unosa
        std::cout << "Unesi broj, operaciju ili 'del' za brisanje poslednjeg unosa (X za izlaz - POTVRDI za potvrdu): ";
        std::cin >> userInput;
        std::cout << "---------------------------" << std::endl;

        // Konvertujemo korisnički unos u odgovarajući tip
        if (userInput == "POTVRDA")
        {
            // Korisnik predao odgovor ili je postupak zavrsen
            std::cout<<"POTVRDA"<<std::endl;
            if (currentExpression.empty())
                indicator = "-179";           // indikator za prazan postupak
            break;
        } else if (userInput == "X" || userInput == "x")
        {
            // Provera da li korisnik želi izlaz
            std::cout<<"IZLAZ"<<std::endl;
            indicator = "-219";     // indikator za izlaz
            break;
        } else if (userInput == "del") {
            // Ako je unet "del", brišemo poslednji unos
            deleteLastInput();
        } else {
            // Pokušaj konverzije u broj
            char* endptr;
            int number = std::strtol(userInput.c_str(), &endptr, 10);

            if (*endptr == '\0') {
                // input is a number

                // FIXME2: 2 consecutive numbers in an expression are 1 number (incorrect)
                // Current input is number, but is previos also a number?

                chooseNumber(number);

                if (availableNumbers.size() == 0)
                {
                    std::cout<<"POTVRDA(kraj postupka)"<<std::endl;
                    break;
                }
            } else if (userInput == "+" || userInput == "-" || userInput == "*" || userInput == "/" || userInput == "(" || userInput == ")" )
            {
                // input is an operation
                chooseOperation(userInput);
            } else
            {
                // input is not a number nor an operation
                std::cout << "Nevažeći unos. Unesi broj, operaciju ili 'del' za brisanje poslednjeg unosa." << std::endl;
            }
        }
    }

    expression = vectorToString(currentExpression);

    submitSolution(expression, indicator);
}
