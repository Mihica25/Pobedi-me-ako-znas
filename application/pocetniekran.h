#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>
#include "logindialog.h"
#include <QDebug>
#include <QTcpSocket>
#include "reckoui.h"
#include "mojbroj.h"
#include "pogodistaui.h"
#include "koznaui.h"
#include "memorija.h"
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
    void on_mojbrojEnds();
    void on_koZnaEnds();
    void on_podrundaEnded();
    void on_pogodiStaEnds();
    void on_memorijaEnds();
    void onReadyRead();

private:
    Ui::PocetniEkran *ui;
    QTcpSocket* tcpSocket;
    QString playerName = "";
    QString opponentName = "";
    bool turn;
    int player1Points = 0;
    int player2Points = 0;
    ReckoUI* recko;
    Mojbroj* mojbroj;
    PogodiStaUI* pogodiSta;
    KoZnaui* kozna;
    void initConntroler();

    bool connectToServer();
    void processServerMessage(const QString& serverMessage);
};
#endif // POCETNIEKRAN_H
