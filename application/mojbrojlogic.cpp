#include "mojbrojlogic.h"

#include <QRandomGenerator>
#include <QRegularExpression>
#include <QStack>
#include <QTextStream>
#include <QDebug>

/*
    TODO:
    1. solver - closest number
*/

//Done
MojBrojLogic::MojBrojLogic()
{
    currentRound = GamePhase::Round1;
    availableOperations = {"+", "-", "*", "/", "(", ")"};
}

//Done
void MojBrojLogic::startGame()
{
    targetNumber = generateTargetNumber();
    availableNumbers = generateInitialNumbers();

    // Test
    //test();
}

//Done
bool MojBrojLogic::endGame()
{
    // TODO: Implement timer destruction logic

    // Reset variables
    targetNumber = 0;
    availableNumbers.clear();
    currentExpression.clear();

    //FIXME: returns
    switch (currentRound)
    {
        case GamePhase::Round1:
            currentRound = GamePhase::Round2;
            qDebug() << "Kraj 1. runde";
            startGame();
            return false;
        case GamePhase::Round2:
            currentRound = GamePhase::End;
            qDebug() << "Kraj 2. runde";
            // TODO: Implement updateScore and next game in the queue logic
            return true;
        default:
            return true;
    }

    return true;
}

//Done - added QRandomGenerator
int MojBrojLogic::generateTargetNumber()
{
    return QRandomGenerator::global()->bounded(1,1000);
}

//Done - added QRadnomGenerator
QVector<int> MojBrojLogic::generateInitialNumbers()
{
    QVector<int> initialNumbers;

    for (int i = 0; i < 4; ++i)
    {
        int randomNumber = QRandomGenerator::global()->bounded(1,10);
        initialNumbers.append(randomNumber);
    }

    int fifthNumberOptions[] = {10, 15, 20};
    int fifthNumber = QRandomGenerator::global()->bounded(3);
    initialNumbers.append(fifthNumberOptions[fifthNumber]);

    int sixthNumberOptions[] = {25, 50, 75, 100};
    int sixthNumber = QRandomGenerator::global()->bounded(3);
    initialNumbers.append(sixthNumberOptions[sixthNumber]);

    return initialNumbers;
}

//Done - changed method
void MojBrojLogic::chooseNumber(int number)
{
    if(availableNumbers.contains(number))
    {
        currentExpression += QString::number(number);
        availableNumbers.removeOne(number);
    } else
    {
        qDebug() << "Broj" << number << "nije dostupan. Izaberite drugi!";
    }
}

//Done
void MojBrojLogic::chooseOperation(const QString& operation)
{
    currentExpression.append(operation);
}

//Done - .back not .at
QPair<QString,QString> MojBrojLogic::deleteLastInput()
{
    if (!currentExpression.isEmpty())
    {
        QString lastElement = currentExpression.back();
        currentExpression.removeLast();

        bool isInt;
        int intValue = lastElement.toInt(&isInt);

        if(isInt)
        {
            availableNumbers.append(intValue);
        }

        QPair<QString, QString> pair(vectorToString(currentExpression),lastElement);
        return pair;

    }

    QPair<QString, QString> pair(vectorToString(currentExpression),"");
    return pair;
}

// Done - changed method
QString MojBrojLogic::vectorToString(const QVector<QString>& vec)
{
    QString result;
    for (const QString& str : vec)
    {
        result += str;
    }

    return result;
}
\
//Done - QRegularExpression and QStack
bool MojBrojLogic::validateExpression(const QString& expression) const
{
    QRegularExpression consecutiveOperationsRegex("[+\\-*\\/]{2,}");
    if (consecutiveOperationsRegex.match(expression).hasMatch())
    {
        qDebug() << "Neispravno zadat izraz: Dve ili više računskih operacija su zajedno.";
        return false;
    }


    QRegularExpression startEndOperationRegex("^[+\\-*\\/]|[+\\-*\\/]$");
    if (startEndOperationRegex.match(expression).hasMatch())
    {
        qDebug() << "Neispravno zadat izraz: Izraz počinje ili se završava računskom operacijom.";
        return false;
    }

    QStack<QChar> brackets;

    for (const QChar token : expression)
    {
        if (token == '(')
        {
            brackets.push(token);
        } else if (token == ')')
        {
            if (brackets.isEmpty())
            {
                qDebug() << "Neispravno zadat izraz: Neuparena zagrada ')'";
                return false;
            } else
            {
                brackets.pop();
            }
        }
    }

    if (!brackets.isEmpty())
    {
        qDebug() << "Neispravno zadat izraz: Neuparena zagrada '('.";
        return false;
    }

    return true;
}

//FIXME
int MojBrojLogic::evaluateExpression(const QString& expression) const
{

    if (!validateExpression(expression))
    {
        qDebug() << "Neispravan postupak.";
        return -1;  // or another specific value
    }

    auto priority = [](QChar op)
    {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };

    auto applyOperation = [](int a, int b, QChar op)
    {
        switch (op.toLatin1()) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0; // Invalid operation
        }
    };

    QStack<int> numbers;
    QStack<QChar> operations;

    QTextStream stream(expression.toUtf8());
    QChar token;

    while (!stream.atEnd())
    {
        stream >> token;
        if (token.isDigit())
        {
            stream.seek(stream.pos()-1);
            int number;
            stream >> number;
            numbers.push(number);
        } else if (token == '(')
        {
            operations.push(token);
        } else if (token == ')')
        {
            while (!operations.isEmpty() && operations.top() != '(')
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                QChar op = operations.top();
                operations.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operations.pop();
        } else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            while (!operations.isEmpty() && priority(operations.top()) >= priority(token))
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                QChar op = operations.top();
                operations.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operations.push(token);
        }
    }

    while (!operations.isEmpty())
    {
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        QChar op = operations.top();
        operations.pop();
        numbers.push(applyOperation(a, b, op));
    }

    return numbers.top();
}

//Done
int MojBrojLogic::submitSolution(const QString& solution, const QString& indicator)
{
    if (indicator == "-179")
    {
        // TODO: player "X" -> points to opponent?
        qDebug() << "KORISNIK PREDAO PRAZAN POSTUPAK RESAVANJA";
        //endGame();
        return -179;
    } else if (indicator == "-219")
    {
        // TODO: player "X" -> points to opponent?
        qDebug() << "KORISNIK PREKINUO POSTUPAK RESAVANJA";
       // endGame();
        return -219;
    }


    int result = evaluateExpression(solution);

    if (result == -1)
    {
        // TODO: if solution can not be parsed -> points to opponent?
        //endGame();
        return -1;
    }

    int difference = qAbs(result - targetNumber);

    // TODO: compare results with opponent
    qDebug() << "Konacni postupak: " << solution;
    qDebug() << "Rezultat: " << result;
    qDebug() << "Rastojanje od traženog broja je: " << difference;
    qDebug() << "---------------------------\n";

    //endGame();

    return result;
}

//FIXME - test
void MojBrojLogic::test()
{
    /*

    // Ispisujemo dobijene vrednosti u toku igre
    std::cout << "---------------------"<<std::endl;
    std::cout << "| Traženi broj: " << targetNumber << " |"<< std::endl;
    std::cout << "---------------------"<<std::endl;

    QString indicator;
    QString expression;
    QString userInput;

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
        for (const QString& op : availableOperations)
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
            if (currentExpression.isEmpty())
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

    */
}
