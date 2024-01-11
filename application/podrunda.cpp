#include "podrunda.h"
#include <QTimer>

Podrunda::Podrunda ()
{
  std::pair<QString, double> getAnswerQuestion ();
  void setAnswerQuestion (QString pitanje, double odgovor);

  std::pair<QString, double> answerQuestion;
  double guess;
  int dobio_poene;
}

std::pair<QString, double>
Podrunda::getAnswerQuestion () const
{
  return answerQuestion;
}

void
Podrunda::setAnswerQuestion (QString pitanje, double odgovor)
{
  answerQuestion.first = pitanje;
  answerQuestion.second = odgovor;
}
