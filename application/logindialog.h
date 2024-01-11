#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui
{
class loginDialog;
}

class loginDialog : public QDialog
{
  Q_OBJECT

public:
  explicit loginDialog (QWidget *parent = nullptr);
  ~loginDialog ();

  QString getName () const;

private:
  QLineEdit *nameLineEdit;
  QPushButton *okButton;
  QPushButton *cancelButton;
};

#endif // LOGINDIALOG_H
