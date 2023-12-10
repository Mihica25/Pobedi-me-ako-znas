/********************************************************************************
** Form generated from reading UI file 'podrundaui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PODRUNDAUI_H
#define UI_PODRUNDAUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_podrundaui
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label_2;

    void setupUi(QWidget *podrundaui)
    {
        if (podrundaui->objectName().isEmpty())
            podrundaui->setObjectName(QString::fromUtf8("podrundaui"));
        podrundaui->resize(400, 300);
        podrundaui->setMinimumSize(QSize(400, 300));
        podrundaui->setMaximumSize(QSize(400, 300));
        label = new QLabel(podrundaui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 170, 111, 31));
        pushButton = new QPushButton(podrundaui);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 170, 80, 31));
        textEdit = new QTextEdit(podrundaui);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(150, 170, 91, 31));
        label_2 = new QLabel(podrundaui);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 271, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-color: white"));

        retranslateUi(podrundaui);

        QMetaObject::connectSlotsByName(podrundaui);
    } // setupUi

    void retranslateUi(QWidget *podrundaui)
    {
        podrundaui->setWindowTitle(QApplication::translate("podrundaui", "podrundaui", nullptr));
        label->setText(QApplication::translate("podrundaui", "Unesite odgovor:", nullptr));
        pushButton->setText(QApplication::translate("podrundaui", "Odgovori", nullptr));
        label_2->setText(QApplication::translate("podrundaui", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">PITANJE</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class podrundaui: public Ui_podrundaui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PODRUNDAUI_H
