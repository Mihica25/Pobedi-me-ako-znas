#ifndef INFOLOG_H
#define INFOLOG_H

#include <QDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class InfoLog;
}
QT_END_NAMESPACE

class InfoLog : public QMainWindow
{
  Q_OBJECT

public:
  InfoLog (QWidget *parent = nullptr);
  ~InfoLog ();

public slots:
  void cancel ();

private:
  Ui::InfoLog *ui;
};
#endif // INFOLOG_H
