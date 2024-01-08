/********************************************************************************
** Form generated from reading UI file 'resultdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTDIALOG_H
#define UI_RESULTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ResultDialog
{
public:

    void setupUi(QDialog *ResultDialog)
    {
        if (ResultDialog->objectName().isEmpty())
            ResultDialog->setObjectName(QString::fromUtf8("ResultDialog"));
        ResultDialog->resize(483, 534);

        retranslateUi(ResultDialog);

        QMetaObject::connectSlotsByName(ResultDialog);
    } // setupUi

    void retranslateUi(QDialog *ResultDialog)
    {
        ResultDialog->setWindowTitle(QApplication::translate("ResultDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultDialog: public Ui_ResultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTDIALOG_H
