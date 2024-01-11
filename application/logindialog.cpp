#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog (QWidget *parent) : QDialog (parent)
{
  nameLineEdit = new QLineEdit (this);
  okButton = new QPushButton ("OK", this);
  cancelButton = new QPushButton ("Cancel", this);

  QVBoxLayout *layout = new QVBoxLayout (this);
  layout->addWidget (nameLineEdit);
  layout->addWidget (okButton);
  layout->addWidget (cancelButton);

  connect (okButton, &QPushButton::clicked, this, &loginDialog::accept);
  connect (cancelButton, &QPushButton::clicked, this, &loginDialog::reject);
}

loginDialog::~loginDialog ()
{
  delete nameLineEdit;
  delete okButton;
  delete cancelButton;
}

QString
loginDialog::getName () const
{
  return nameLineEdit->text ();
}
