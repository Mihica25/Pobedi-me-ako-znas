#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>
#include "logindialog.h"
#include <QDebug>
#include <QTcpSocket>
#include "reckoui.h"
#include <QString>
#include "podrundaui.h"

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
    void on_podrundaEnded();
    void onReadyRead();

private:
    Ui::PocetniEkran *ui;
    QTcpSocket* tcpSocket;
    QString playerName = "";
    QString opponentName = "";
    bool turn;
    int player1Points = 0;
    int player2Points = 0;

    void initConntroler();

    bool connectToServer();
    void processServerMessage(const QString& serverMessage);
};
#endif // POCETNIEKRAN_H
