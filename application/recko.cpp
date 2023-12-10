#include "recko.h"

Recko::Recko()
{
    readQuizWords();
    newWordle();

}

void Recko::readQuizWords(){
    QFile quizWordsFile("/home/user/Desktop/pobedi-me-ako-znas/application/resources/QuizWords.txt");
    quizWordsFile.open(QIODevice::ReadOnly);
    QByteArray words = quizWordsFile.readAll();
    quizWords = QString(words).split(" ");
    quizWordsFile.close();
}

void Recko::newWordle(){
    srand(time(NULL));
    wordle = quizWords[rand() % quizWords.length()];
    qDebug() << "recko.cpp: " << wordle;
}

void Recko::incrementRow(){
    currentRow++;
}

int Recko::getCurrentRow(){
    return currentRow;
}