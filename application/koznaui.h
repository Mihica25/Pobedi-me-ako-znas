#ifndef KOZNAUI_H
#define KOZNAUI_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class KoZnaui; }
QT_END_NAMESPACE

class KoZnaui : public QMainWindow
{
    Q_OBJECT

public:
    KoZnaui(QWidget *parent = nullptr);
    ~KoZnaui();
    QVector<QString> getQuestion(int numberOfQuestion);
    void displayQuestion(int questionNumber);

public slots:
    void on_timesUp();
    void on_gameEnds();
    void updateTime();

private:
    Ui::KoZnaui *ui;
    QTimer* tajmer;
    int numberOfQuestion;
    int time;
    int bodovi = 0;
    int ukupni_bodovi = 0;

    void displayAnswer();
    void disableUi();
    void enableUi();
    void restartColor();


    QString getCorrectAnswer();
    bool guess(QString answer);

    void on_pushButtonAns1();
    void on_pushButtonAns2();
    void on_pushButtonAns3();
    void on_pushButtonAns4();






signals:
    void timesUp();
    void gameEnds();





};
#endif // KOZNAUI_H


