#ifndef KOZNA_H
#define KOZNA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KoZna; }
QT_END_NAMESPACE

class KoZna : public QMainWindow
{
    Q_OBJECT

public:
    KoZna(QWidget *parent = nullptr);
    ~KoZna();

private:
    Ui::KoZna *ui;
};
#endif // KOZNA_H
