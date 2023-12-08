#ifndef WORDLEWINDOW_H
#define WORDLEWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class WordleWindow;
}

class WordleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WordleWindow(QWidget *parent = 0);
    ~WordleWindow();

    void newWordle();
    void setUpBackground();
    void readQuizWords();
    void disableLineEdits();
    void disableHBoxLayout(int i);
    void enableHBoxLayout(int i);
    void gameStarted();

private slots:
    void handleEnterPressed();

private:
    Ui::WordleWindow *ui;
    QStringList quizWords;
    QString wordle = "";
    bool isGameFinished = false;
    int tryNumber = 0;
    bool guessed = false;
};

#endif // WORDLEWINDOW_H
