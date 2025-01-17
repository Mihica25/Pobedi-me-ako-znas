#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>
#include "logindialog.h"
#include <QDebug>
#include <QTcpSocket>
#include <QStackedWidget>
#include <QRect>
#include "reckoui.h"
#include "mojbroj.h"
#include "pogodistaui.h"
#include "koznaui.h"
#include "memorija.h"
#include <QString>
#include "infolog.h"
#include "resultdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PocetniEkran; }
QT_END_NAMESPACE

class PocetniEkran : public QMainWindow
{
    Q_OBJECT

public:
    PocetniEkran(QWidget *parent = nullptr);
    ~PocetniEkran();

    int getPlayer1Points();
    int getPlayer2Points();
    Ui::PocetniEkran *getUi();

public slots:
    void on_startGameButton_clicked();
    void on_najboljiRezultatiButton_clicked();
    void on_reckoEnds();
    void on_mojbrojEnds();
    void on_koZnaEnds();
    void on_podrundaEnded();
    void on_pogodiStaEnds();
    void on_memorijaEnds();
    void onReadyRead();
    void onReadyReadBestResults();
    void on_info();

private:
    Ui::PocetniEkran *ui;
    QTcpSocket* tcpSocket;
    QString playerName = "";
    QString opponentName = "";
    bool turn;
    int player1Points = 0;
    int player2Points = 0;
    InfoLog *il;
    ResultDialog* resultDialog;
    ReckoUI* recko;
    Mojbroj* mojbroj;
    PogodiStaUI* pogodiSta;
    KoZnaui* kozna;
    Memorija* memorija;
    void initConntroler();

    QStackedWidget* stackedWidget;

    bool connectToServer(QString message);
    void processServerMessage(const QString& serverMessage);
};
#endif // POCETNIEKRAN_H
