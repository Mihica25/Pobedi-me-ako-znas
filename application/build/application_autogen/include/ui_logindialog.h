/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
  public:
    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(240, 320);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", nullptr));
    } // retranslateUi
};

namespace Ui
{
class loginDialog : public Ui_loginDialog
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
