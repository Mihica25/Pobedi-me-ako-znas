/********************************************************************************
** Form generated from reading UI file 'pogodistaui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POGODISTAUI_H
#define UI_POGODISTAUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PogodiStaUI
{
public:
    QLabel *lbImage;
    QLabel *lbTimer;
    QLabel *lbInfo;
    QLineEdit *leInsert;

    void setupUi(QWidget *PogodiStaUI)
    {
        if (PogodiStaUI->objectName().isEmpty())
            PogodiStaUI->setObjectName(QStringLiteral("PogodiStaUI"));
        PogodiStaUI->resize(800, 800);
        PogodiStaUI->setMinimumSize(QSize(800, 800));
        PogodiStaUI->setMaximumSize(QSize(800, 800));
        PogodiStaUI->setStyleSheet(QStringLiteral(""));
        lbImage = new QLabel(PogodiStaUI);
        lbImage->setObjectName(QStringLiteral("lbImage"));
        lbImage->setEnabled(true);
        lbImage->setGeometry(QRect(75, 195, 650, 450));
        lbImage->setStyleSheet(QStringLiteral(""));
        lbTimer = new QLabel(PogodiStaUI);
        lbTimer->setObjectName(QStringLiteral("lbTimer"));
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
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
        lbTimer->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(40);
        font.setBold(false);
        lbTimer->setFont(font);
        lbTimer->setAutoFillBackground(false);
        lbTimer->setStyleSheet(QStringLiteral("color: rgb(126, 217, 87);"));
        lbTimer->setAlignment(Qt::AlignCenter);
        lbInfo = new QLabel(PogodiStaUI);
        lbInfo->setObjectName(QStringLiteral("lbInfo"));
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
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
        lbInfo->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setItalic(true);
        lbInfo->setFont(font1);
        lbInfo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lbInfo->setAlignment(Qt::AlignCenter);
        leInsert = new QLineEdit(PogodiStaUI);
        leInsert->setObjectName(QStringLiteral("leInsert"));
        leInsert->setEnabled(true);
        leInsert->setGeometry(QRect(75, 725, 650, 41));
        leInsert->setAlignment(Qt::AlignCenter);

        retranslateUi(PogodiStaUI);

        QMetaObject::connectSlotsByName(PogodiStaUI);
    } // setupUi

    void retranslateUi(QWidget *PogodiStaUI)
    {
        PogodiStaUI->setWindowTitle(QApplication::translate("PogodiStaUI", "Pogodi \305\240ta", 0));
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
