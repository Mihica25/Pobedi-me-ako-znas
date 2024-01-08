/********************************************************************************
** Form generated from reading UI file 'infolog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOLOG_H
#define UI_INFOLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoLog
{
  public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QToolButton *tb1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InfoLog)
    {
        if (InfoLog->objectName().isEmpty())
            InfoLog->setObjectName(QString::fromUtf8("InfoLog"));
        InfoLog->resize(794, 533);
        InfoLog->setStyleSheet(QString::fromUtf8("background-color: #480002"));
        centralwidget = new QWidget(InfoLog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        tb1 = new QToolButton(centralwidget);
        tb1->setObjectName(QString::fromUtf8("tb1"));

        verticalLayout_2->addWidget(tb1);

        InfoLog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InfoLog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 794, 29));
        InfoLog->setMenuBar(menubar);
        statusbar = new QStatusBar(InfoLog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InfoLog->setStatusBar(statusbar);

        retranslateUi(InfoLog);

        QMetaObject::connectSlotsByName(InfoLog);
    } // setupUi

    void retranslateUi(QMainWindow *InfoLog)
    {
        InfoLog->setWindowTitle(QApplication::translate("InfoLog", "InfoLog", nullptr));
        textEdit->setHtml(QApplication::translate(
            "InfoLog",
            "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
            "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
            "p, li { white-space: pre-wrap; }\n"
            "</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; "
            "font-style:normal;\">\n"
            "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
            "-qt-block-indent:0; text-indent:0px;\">Re\304\215 ko: Igra\304\215  zapo\304\215inje jednu partiju igre. "
            "Ima 6 poku\305\241aja da pogodi koja je tajna re\304\215 od 5 slova, pri \304\215emu dobija povratnu "
            "informaciju o pogo\304\221enim slovima bilo da su na pravom ili pogre\305\241nom mestu.</p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
            "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
            "-qt-block-"
            "indent:0; text-indent:0px;\">Moj broj: Igra &quot;Moj broj&quot; se sastoji iz dve runde. Za svaku rundu, "
            "aplikacija generi\305\241e jedan (tra\305\276eni) broj 1-999, potom \304\215etiri jednocifrena (brojevi "
            "1-9) i dva dvocifrena broja (brojeve 10, 15, 25, 50 ili 75). Koriste\304\207i operacije +, -, * i , "
            "igra\304\215i treba da dobiju \305\241to pribli\305\276nije re\305\241enje tra\305\276enom broju.</p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
            "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
            "-qt-block-indent:0; text-indent:0px;\">Ko zna: Igra\304\215i zapo\304\215inju jednu partiju igre. "
            "Dobijaju pitanje i 4 ponu\304\221ena odgovora od kojih je 1 ta\304\215an. Poene dobija onaj igra\304\215 "
            "koji odgovori ta\304\215no na pitanje. Ukoliko i on i protivnik odgovore ta\304\215no, dobijaju PODRUNDU, "
            "odnosno pitanje \304\215"
            "iji je odgovor odre\304\221eni broj. Onaj igra\304\215 koji je bio bli\305\276i re\305\241enju dobija "
            "poene.</p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
            "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
            "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
            "-qt-block-indent:0; text-indent:0px;\">Pogodi sta: Igra\304\215i poku\305\241avaju da pogode "
            "zamu\304\207enu zagonetnu sliku, pri \304\215emu kako runde prolaze, slika postaje sve jasnija i jasnija, "
            "ali i ta\304\215an odgovor nosi manji broj poena. Igra\304\215i imaju pravo na jedan poku\305\241aj po "
            "rundi, poene nosi onaj igra\304\215 koji pre pogodi pojam iza slike.</p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; "
            "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
            "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
            "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
            "-qt-block-indent:0; text-indent:0px;\">Memorija: U igri &quot;Memorija&quot; igra\304\215i okre\304\207u "
            "kartice i poku\305\241avaju da prona\304\221u sto vi\305\241e parova kartica. Za svaki prona\304\221eni "
            "par igra\304\215 dobija po jedan poen.</p></body></html>",
            nullptr));
        tb1->setText(QApplication::translate("InfoLog", "X", nullptr));
    } // retranslateUi
};

namespace Ui
{
class InfoLog : public Ui_InfoLog
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOLOG_H
