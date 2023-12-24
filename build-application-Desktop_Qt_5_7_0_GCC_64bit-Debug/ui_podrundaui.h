/********************************************************************************
** Form generated from reading UI file 'podrundaui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PODRUNDAUI_H
#define UI_PODRUNDAUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Podrundaui
{
public:
    QLabel *label;
    QPushButton *pbOdgovori;
    QTextEdit *teOdgovor;
    QLabel *labPitanje;
    QLabel *labTacanOdgovor;
    QLabel *labTimer;

    void setupUi(QWidget *Podrundaui)
    {
        if (Podrundaui->objectName().isEmpty())
            Podrundaui->setObjectName(QStringLiteral("Podrundaui"));
        Podrundaui->resize(500, 400);
        Podrundaui->setMinimumSize(QSize(500, 400));
        Podrundaui->setMaximumSize(QSize(500, 400));
        label = new QLabel(Podrundaui);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 260, 111, 41));
        pbOdgovori = new QPushButton(Podrundaui);
        pbOdgovori->setObjectName(QStringLiteral("pbOdgovori"));
        pbOdgovori->setGeometry(QRect(310, 260, 80, 41));
        teOdgovor = new QTextEdit(Podrundaui);
        teOdgovor->setObjectName(QStringLiteral("teOdgovor"));
        teOdgovor->setGeometry(QRect(200, 260, 91, 41));
        labPitanje = new QLabel(Podrundaui);
        labPitanje->setObjectName(QStringLiteral("labPitanje"));
        labPitanje->setGeometry(QRect(80, 190, 311, 51));
        labPitanje->setStyleSheet(QStringLiteral("background-color: white"));
        labTacanOdgovor = new QLabel(Podrundaui);
        labTacanOdgovor->setObjectName(QStringLiteral("labTacanOdgovor"));
        labTacanOdgovor->setGeometry(QRect(140, 330, 211, 41));
        labTimer = new QLabel(Podrundaui);
        labTimer->setObjectName(QStringLiteral("labTimer"));
        labTimer->setGeometry(QRect(210, 130, 61, 41));
        labTimer->setStyleSheet(QStringLiteral("background-color:white"));

        retranslateUi(Podrundaui);

        QMetaObject::connectSlotsByName(Podrundaui);
    } // setupUi

    void retranslateUi(QWidget *Podrundaui)
    {
        Podrundaui->setWindowTitle(QApplication::translate("Podrundaui", "Podrundaui", 0));
        label->setText(QApplication::translate("Podrundaui", "Unesite odgovor:", 0));
        pbOdgovori->setText(QApplication::translate("Podrundaui", "Odgovori", 0));
        labPitanje->setText(QApplication::translate("Podrundaui", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">PITANJE</span></p></body></html>", 0));
        labTacanOdgovor->setText(QString());
        labTimer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Podrundaui: public Ui_Podrundaui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PODRUNDAUI_H
