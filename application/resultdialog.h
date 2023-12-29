#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateTime>
#include <QVector>
#include <QDateTime>
#include <iostream>
#include <QDebug>

namespace Ui {
class ResultDialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(QWidget *parent = nullptr);
    ~ResultDialog();

    void showResults(QString &data);

    struct GameResult {
            QString player1Name;
            int player1Points;
            QString player2Name;
            int player2Points;
            QDateTime dateTime;
    };

private:
    QVBoxLayout *mainLayout;


    QVector<GameResult> parseBestResults(QString &data);
    void clearLayout(QLayout *layout);

};

#endif // RESULTDIALOG_H
