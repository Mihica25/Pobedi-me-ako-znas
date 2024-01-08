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
            Podrundaui->setObjectName(QString::fromUtf8("Podrundaui"));
        Podrundaui->resize(500, 400);
        Podrundaui->setMinimumSize(QSize(500, 400));
        Podrundaui->setMaximumSize(QSize(500, 400));
        label = new QLabel(Podrundaui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(70, 260, 111, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pbOdgovori = new QPushButton(Podrundaui);
        pbOdgovori->setObjectName(QString::fromUtf8("pbOdgovori"));
        pbOdgovori->setGeometry(QRect(310, 260, 80, 41));
        teOdgovor = new QTextEdit(Podrundaui);
        teOdgovor->setObjectName(QString::fromUtf8("teOdgovor"));
        teOdgovor->setGeometry(QRect(200, 260, 91, 41));
        labPitanje = new QLabel(Podrundaui);
        labPitanje->setObjectName(QString::fromUtf8("labPitanje"));
        labPitanje->setGeometry(QRect(80, 190, 311, 51));
        labPitanje->setStyleSheet(QString::fromUtf8("background-color: white"));
        labTacanOdgovor = new QLabel(Podrundaui);
        labTacanOdgovor->setObjectName(QString::fromUtf8("labTacanOdgovor"));
        labTacanOdgovor->setEnabled(true);
        labTacanOdgovor->setGeometry(QRect(130, 330, 211, 41));
        labTimer = new QLabel(Podrundaui);
        labTimer->setObjectName(QString::fromUtf8("labTimer"));
        labTimer->setGeometry(QRect(210, 130, 61, 41));
        labTimer->setStyleSheet(QString::fromUtf8("background-color:white"));

        retranslateUi(Podrundaui);

        QMetaObject::connectSlotsByName(Podrundaui);
    } // setupUi

    void retranslateUi(QWidget *Podrundaui)
    {
        Podrundaui->setWindowTitle(QApplication::translate("Podrundaui", "Podrundaui", nullptr));
        label->setText(QString());
        pbOdgovori->setText(QApplication::translate("Podrundaui", "Odgovori", nullptr));
        labPitanje->setText(QApplication::translate(
            "Podrundaui",
            "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">PITANJE</span></p></body></html>",
            nullptr));
        labTacanOdgovor->setText(QString());
        labTimer->setText(QString());
    } // retranslateUi
};

namespace Ui
{
class Podrundaui : public Ui_Podrundaui
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PODRUNDAUI_H
