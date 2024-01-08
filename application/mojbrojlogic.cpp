#include "mojbrojlogic.h"

#include <QDebug>
#include <QRandomGenerator>
#include <QRegularExpression>
#include <QStack>
#include <QTextStream>

MojBrojLogic::MojBrojLogic()
{
    currentRound = GamePhase::Round1;
    availableOperations = {"+", "-", "*", "/", "(", ")"};
}

GamePhase MojBrojLogic::getCurrentRound()
{
    return currentRound;
}

int MojBrojLogic::getTargetNumber()
{
    return targetNumber;
}

void MojBrojLogic::setTargetNumber(int tn)
{
    targetNumber = tn;
}

bool MojBrojLogic::endGame()
{
    targetNumber = 0;
    availableNumbers.clear();
    currentExpression.clear();

    switch (currentRound)
    {
    case GamePhase::Round1:
        currentRound = GamePhase::Round2;
        return false;
    case GamePhase::Round2:
        currentRound = GamePhase::End;
        return true;
    default:
        return true;
    }

    return true;
}

void MojBrojLogic::chooseNumber(int number)
{
    if (availableNumbers.contains(number))
    {
        currentExpression += QString::number(number);
        availableNumbers.removeOne(number);
    }
    else
    {
        qDebug() << "Broj" << number << "nije dostupan. Izaberite drugi!";
    }
}

void MojBrojLogic::chooseOperation(const QString &operation)
{
    currentExpression.append(operation);
}

QPair<QString, QString> MojBrojLogic::deleteLastInput()
{
    if (!currentExpression.isEmpty())
    {
        QString lastElement = currentExpression.back();
        currentExpression.removeLast();

        bool isInt;
        int intValue = lastElement.toInt(&isInt);

        if (isInt)
        {
            availableNumbers.append(intValue);
        }

        QPair<QString, QString> pair(vectorToString(currentExpression), lastElement);
        return pair;
    }

    QPair<QString, QString> pair(vectorToString(currentExpression), "");
    return pair;
}

QString MojBrojLogic::vectorToString(const QVector<QString> &vec)
{
    QString result;
    for (const QString &str : vec)
    {
        result += str;
    }

    return result;
}

bool MojBrojLogic::validateExpression(const QString &expression) const
{
    QRegularExpression consecutiveOperationsRegex("[+\\-*\\/]{2,}");
    if (consecutiveOperationsRegex.match(expression).hasMatch())
    {
        return false;
    }

    QRegularExpression startEndOperationRegex("^[+\\-*\\/]|[+\\-*\\/]$");
    if (startEndOperationRegex.match(expression).hasMatch())
    {
        return false;
    }

    QStack<QChar> brackets;

    for (const QChar token : expression)
    {
        if (token == '(')
        {
            brackets.push(token);
        }
        else if (token == ')')
        {
            if (brackets.isEmpty())
            {
                return false;
            }
            else
            {
                brackets.pop();
            }
        }
    }

    if (!brackets.isEmpty())
    {
        return false;
    }

    return true;
}

int MojBrojLogic::evaluateExpression(const QString &expression) const
{

    if (!validateExpression(expression))
    {
        return -1;
    }

    auto priority = [](QChar op) {
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    };

    auto applyOperation = [](int a, int b, QChar op) {
        switch (op.toLatin1())
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0; // Invalid operation
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
            stream.seek(stream.pos() - 1);
            int number;
            stream >> number;
            numbers.push(number);
        }
        else if (token == '(')
        {
            operations.push(token);
        }
        else if (token == ')')
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
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/')
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

// Done
int MojBrojLogic::submitSolution(const QString &solution, const QString &indicator)
{
    if (indicator == "-1179")
    {
        return -1179;
    }

    int result = evaluateExpression(solution);

    if (result == -1)
    {
        return -1951;
    }

    int difference = qAbs(result - targetNumber);

    qDebug() << "Konacni postupak: " << solution;
    qDebug() << "Rezultat: " << result;
    qDebug() << "Rastojanje od traženog broja je: " << difference;
    qDebug() << "---------------------------\n";

    return result;
}
