#ifndef PODRUNDA_H
#define PODRUNDA_H

#include <QObject>
#include <QTimer>

class Podrunda : public QObject
{
    Q_OBJECT
public:
    explicit Podrunda();
    std::pair<QString, double> getAnswerQuestion() const;
    void setAnswerQuestion(QString pitanje, double odgovor);

    std::pair<QString, double> answerQuestion;
    double guess;
    int dobio_poene;

signals:


public slots:



private:


};

#endif // PODRUNDA_H
