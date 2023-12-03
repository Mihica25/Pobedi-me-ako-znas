#include "mojbrojlogic.hpp"
#include <iostream>
#include <cstdlib>  // For rand() function
#include <vector>
#include <regex>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <cctype>

/*
MojBroj::MojBroj() {
    // Constructor implementation, if any
}
*/

void MojBroj::startGame()
{
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    targetNumber = generateTargetNumber();
    availableNumbers = generateInitialNumbers();
    availableOperations = {"+", "-", "*", "/"};
    currentExpression = "";

    // TODO: Implement your timer logic here

    // Test
    test();
}


void MojBroj::endGame()
{
    // TODO: Implement timer destruction logic

    // Reset variables
    targetNumber = 0;
    availableNumbers.clear();

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


int MojBroj::generateTargetNumber()
{
    // Generate a random number between 1 and 1000
    return rand() % 999 + 1;
}

std::vector<int> MojBroj::generateInitialNumbers()
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


void MojBroj::chooseNumber(int number)
{
    auto it = std::find(availableNumbers.begin(), availableNumbers.end(), number);

    if (it != availableNumbers.end())
    {
        currentExpression += std::to_string(number);
        availableNumbers.erase(it);
    }
    else
    {
        std::cout << "Broj " << number << " nije dostupan. Izaberite drugi broj." << std::endl;
    }
}

void MojBroj::chooseOperation(const std::string& operation) {
    currentExpression += operation;
}

// FIXME: example: 5*20 --del--> 5*2 and returned available number is 0  (incorrect)
//                 5*20 --del--> 5*  and returned available number is 20 (correct)
void MojBroj::deleteLastInput()
{
    if (!currentExpression.empty())
    {
        char lastChar = currentExpression.back();

        if (std::isdigit(lastChar))
        {
            int lastNumber = lastChar - '0';
            availableNumbers.push_back(lastNumber);
        }

        currentExpression.pop_back();
    }
}

bool MojBroj::validateExpression(const std::string& expression) const
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

    return true;
}

int MojBroj::evaluateExpression(const std::string& expression) const {
    
    if (!validateExpression(expression))
    {
        std::cout << "Neispravan postupak." << std::endl;
        return -1;  // or another specific value
    }
   
   
    auto priority = [](char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };

    auto applyOperation = [](int a, int b, char op) {
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

    while (iss >> token) {
        if (isdigit(token)) {
            iss.putback(token);
            int number;
            iss >> number;
            numbers.push(number);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operations.empty() && priority(operations.top()) >= priority(token)) {
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

    while (!operations.empty()) {
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

void MojBroj::submitSolution(const std::string& solution)
{
    if (solution == "-1" || solution == "-2")
    {   
        // TODO: player "X" -> points to opponent?
        std::cout<<"KORISNIK PREKINUO ili PREDAO PRAZAN POSTUPAK RESAVANJA"<<std::endl;
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

    endGame();
}

void MojBroj::test()
{
    // Ispisujemo dobijene vrednosti u toku igre
    std::cout << "---------------------"<<std::endl;
    std::cout << "| Traženi broj: " << targetNumber << " |"<< std::endl;
    std::cout << "---------------------"<<std::endl;
    // FIXME: 2 consecutive numbers in an expression are 1 number (incorrect)

    // Unos brojeva i operacija sve dok ne unesemo slovo X
    while (true) {
        // Prikazujemo trenutni izraz
        std::cout << "Trenutni izraz: " << currentExpression << std::endl;

        // Ispisujemo dostupne brojeve i operacije
        std::cout << "Dostupni brojevi: ";
        for (int num : availableNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        std::cout << "Dostupne operacije: ";
        for (const std::string& op : availableOperations) {
            std::cout << op << " ";
        }
        std::cout << std::endl;

        // Korisnik unosi broj, operaciju ili "del" za brisanje poslednjeg unosa
        std::cout << "Unesi broj, operaciju ili 'del' za brisanje poslednjeg unosa (X za izlaz - POTVRDI za potvrdu): ";
        std::string userInput;
        std::cin >> userInput;

        // Konvertujemo korisnički unos u odgovarajući tip
        if (userInput == "POTVRDA")  {
            // Korisnik predao odgovor ili je postupak zavrsen
            std::cout<<"POTVRDA"<<std::endl;
            if (currentExpression == "")
                currentExpression = "-2";
            break;
        } else if (userInput == "X" || userInput == "x") {
            // Provera da li korisnik želi izlaz
            currentExpression.clear();
            currentExpression = "-1";
            std::cout<<"IZLAZ"<<std::endl;
            break;
        } else if (userInput == "del") {
            // Ako je unet "del", brišemo poslednji unos
            deleteLastInput();
        } else {
            // Pokušaj konverzije u broj
            char* endptr;
            int number = std::strtol(userInput.c_str(), &endptr, 10);

            if (*endptr == '\0') {
                // Ako je unesen broj
                chooseNumber(number);
                if (availableNumbers.size() == 0)
                {
                    std::cout<<"POTVRDA(kraj postupka)"<<std::endl;   
                    break;
                }
            } else if (userInput == "+" || userInput == "-" || userInput == "*" || userInput == "/") {
                // Ako je uneta operacija
                chooseOperation(userInput);
            } else {
                // Ako korisnik unese nešto što nije broj, operacija ili "del"
                std::cout << "Nevažeći unos. Unesi broj, operaciju ili 'del' za brisanje poslednjeg unosa." << std::endl;
            }
        }
    }

    submitSolution(currentExpression);
}
