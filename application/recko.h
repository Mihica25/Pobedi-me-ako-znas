#ifndef RECKO_H
#define RECKO_H

#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

class Recko {

public:
    Recko();

    void readQuizWords();
    void newWordle();
    void incrementRow();
    int getCurrentRow();
    void setCurrentRow(int row);


    QString wordle = "";

private:
    QStringList quizWords;
    int currentRow = 1;
//    QVector<char> currentCombination;

};

#endif // RECKO_H
