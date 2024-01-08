#ifndef RECKO_H
#define RECKO_H

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QString>
#include <QTextStream>

class Recko
{

  public:
    Recko();

    void readQuizWords();
    void newWordle();
    void incrementRow();
    int getCurrentRow();
    void setCurrentRow(int row);

    QStringList getQuizWords();

    QString wordle = "";

  private:
    QStringList quizWords;
    int currentRow = 1;
};

#endif // RECKO_H
