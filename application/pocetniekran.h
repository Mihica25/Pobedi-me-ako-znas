#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>
#include "logindialog.h"
#include <QDebug>
#include <QTcpSocket>

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

private:
    Ui::PocetniEkran *ui;

    bool connectToServer(const QString &playerName);
};
#endif // POCETNIEKRAN_H
