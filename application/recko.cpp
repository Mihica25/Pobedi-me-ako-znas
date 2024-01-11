#include "recko.h"

Recko::Recko ()
{
  readQuizWords ();
  newWordle ();
}

void
Recko::readQuizWords ()
{
  QFile quizWordsFile ("/home/user/Desktop/pobedi-me-ako-znas/application/"
					   "resources/QuizWords.txt");
  quizWordsFile.open (QIODevice::ReadOnly);
  QByteArray words = quizWordsFile.readAll ();
  quizWords = QString (words).split (" ");
  quizWordsFile.close ();
}

void
Recko::newWordle ()
{
  srand (time (nullptr));
  wordle = quizWords[rand () % quizWords.length ()];
}

QStringList
Recko::getQuizWords ()
{
  return quizWords;
}

void
Recko::incrementRow ()
{
  currentRow++;
}

int
Recko::getCurrentRow ()
{
  return currentRow;
}

void
Recko::setCurrentRow (int row)
{
  currentRow = row;
}
