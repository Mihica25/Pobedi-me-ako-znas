#ifndef POCETNIEKRAN_H
#define POCETNIEKRAN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PocetniEkran; }
QT_END_NAMESPACE

class PocetniEkran : public QMainWindow
{
    Q_OBJECT

public:
    PocetniEkran(QWidget *parent = nullptr);
    ~PocetniEkran();

private:
    Ui::PocetniEkran *ui;
};
#endif // POCETNIEKRAN_H
