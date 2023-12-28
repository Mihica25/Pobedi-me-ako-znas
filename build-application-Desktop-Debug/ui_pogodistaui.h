/********************************************************************************
** Form generated from reading UI file 'pogodistaui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POGODISTAUI_H
#define UI_POGODISTAUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PogodiStaUI
{
public:
    QLabel *lbImage;
    QLabel *lbTimer;
    QLabel *lbInfo;
    QLineEdit *leInsert;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lePlayer1;
    QLCDNumber *lcdPoints1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lePlayer2;
    QLCDNumber *lcdPoints2;

    void setupUi(QWidget *PogodiStaUI)
    {
        if (PogodiStaUI->objectName().isEmpty())
            PogodiStaUI->setObjectName(QString::fromUtf8("PogodiStaUI"));
        PogodiStaUI->resize(800, 800);
        PogodiStaUI->setMinimumSize(QSize(800, 800));
        PogodiStaUI->setMaximumSize(QSize(800, 800));
        PogodiStaUI->setStyleSheet(QString::fromUtf8(""));
        lbImage = new QLabel(PogodiStaUI);
        lbImage->setObjectName(QString::fromUtf8("lbImage"));
        lbImage->setEnabled(true);
        lbImage->setGeometry(QRect(75, 195, 650, 450));
        lbImage->setStyleSheet(QString::fromUtf8(""));
        lbTimer = new QLabel(PogodiStaUI);
        lbTimer->setObjectName(QString::fromUtf8("lbTimer"));
        lbTimer->setGeometry(QRect(302, 75, 100, 100));
        QPalette palette;
        QBrush brush(QColor(126, 217, 87, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(239, 41, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush2(QColor(126, 217, 87, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        lbTimer->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(40);
        font.setBold(false);
        lbTimer->setFont(font);
        lbTimer->setAutoFillBackground(false);
        lbTimer->setStyleSheet(QString::fromUtf8("color: rgb(126, 217, 87);"));
        lbTimer->setAlignment(Qt::AlignCenter);
        lbInfo = new QLabel(PogodiStaUI);
        lbInfo->setObjectName(QString::fromUtf8("lbInfo"));
        lbInfo->setEnabled(false);
        lbInfo->setGeometry(QRect(250, 660, 300, 40));
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        lbInfo->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setItalic(true);
        lbInfo->setFont(font1);
        lbInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbInfo->setAlignment(Qt::AlignCenter);
        leInsert = new QLineEdit(PogodiStaUI);
        leInsert->setObjectName(QString::fromUtf8("leInsert"));
        leInsert->setEnabled(true);
        leInsert->setGeometry(QRect(75, 725, 650, 41));
        leInsert->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(PogodiStaUI);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lePlayer1 = new QLineEdit(verticalLayoutWidget);
        lePlayer1->setObjectName(QString::fromUtf8("lePlayer1"));
        QFont font2;
        font2.setPointSize(20);
        lePlayer1->setFont(font2);
        lePlayer1->setAutoFillBackground(false);
        lePlayer1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        lePlayer1->setAlignment(Qt::AlignCenter);
        lePlayer1->setReadOnly(true);

        verticalLayout->addWidget(lePlayer1);

        lcdPoints1 = new QLCDNumber(verticalLayoutWidget);
        lcdPoints1->setObjectName(QString::fromUtf8("lcdPoints1"));

        verticalLayout->addWidget(lcdPoints1);

        verticalLayoutWidget_2 = new QWidget(PogodiStaUI);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(610, 10, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lePlayer2 = new QLineEdit(verticalLayoutWidget_2);
        lePlayer2->setObjectName(QString::fromUtf8("lePlayer2"));
        lePlayer2->setFont(font2);
        lePlayer2->setAutoFillBackground(false);
        lePlayer2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        lePlayer2->setAlignment(Qt::AlignCenter);
        lePlayer2->setReadOnly(true);

        verticalLayout_2->addWidget(lePlayer2);

        lcdPoints2 = new QLCDNumber(verticalLayoutWidget_2);
        lcdPoints2->setObjectName(QString::fromUtf8("lcdPoints2"));

        verticalLayout_2->addWidget(lcdPoints2);


        retranslateUi(PogodiStaUI);

        QMetaObject::connectSlotsByName(PogodiStaUI);
    } // setupUi

    void retranslateUi(QWidget *PogodiStaUI)
    {
        PogodiStaUI->setWindowTitle(QApplication::translate("PogodiStaUI", "Pogodi \305\240ta", nullptr));
        lbImage->setText(QString());
        lbTimer->setText(QString());
        lbInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PogodiStaUI: public Ui_PogodiStaUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POGODISTAUI_H
