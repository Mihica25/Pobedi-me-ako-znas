#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>
#include "logindialog.h"
#include <QDebug>
#include <QTcpSocket>
#include "reckoui.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class PocetniEkran; }
QT_END_NAMESPACE

class PocetniEkran : public QMainWindow
{
    Q_OBJECT

public:
    PocetniEkran(QWidget *parent = nullptr);
    ~PocetniEkran();

public slots:
    void on_startGameButton_clicked();
    void on_reckoEnds();

private:
    Ui::PocetniEkran *ui;
    QTcpSocket* tcpSocket;
    QString playerName = "";
    QString opponentName = "";
    bool turn = false;
    int player1Points = 0;
    int player2Points = 0;

    void initConntroler();

    bool connectToServer();
};
#endif // POCETNIEKRAN_H
