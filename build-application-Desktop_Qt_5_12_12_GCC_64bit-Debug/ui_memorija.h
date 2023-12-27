/********************************************************************************
** Form generated from reading UI file 'memorija.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORIJA_H
#define UI_MEMORIJA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Memorija
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget_7;
    QWidget *widget_12;
    QWidget *widget_8;
    QWidget *widget_15;
    QWidget *widget_16;
    QWidget *widget_2;
    QWidget *widget_6;
    QWidget *widget_10;
    QWidget *widget_18;
    QWidget *widget_19;
    QWidget *widget_5;
    QWidget *widget_9;
    QWidget *widget_17;
    QWidget *widget_14;
    QWidget *widget_20;
    QWidget *widget_3;
    QWidget *widget_11;
    QWidget *widget_13;
    QWidget *widget_4;
    QWidget *widget_1;

    void setupUi(QWidget *Memorija)
    {
        if (Memorija->objectName().isEmpty())
            Memorija->setObjectName(QString::fromUtf8("Memorija"));
        Memorija->resize(800, 800);
        Memorija->setMinimumSize(QSize(800, 800));
        Memorija->setMaximumSize(QSize(800, 800));
        layoutWidget = new QWidget(Memorija);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 220, 751, 561));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(layoutWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));

        gridLayout->addWidget(widget_7, 1, 1, 1, 1);

        widget_12 = new QWidget(layoutWidget);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));

        gridLayout->addWidget(widget_12, 2, 1, 1, 1);

        widget_8 = new QWidget(layoutWidget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));

        gridLayout->addWidget(widget_8, 1, 2, 1, 1);

        widget_15 = new QWidget(layoutWidget);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));

        gridLayout->addWidget(widget_15, 2, 4, 1, 1);

        widget_16 = new QWidget(layoutWidget);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));

        gridLayout->addWidget(widget_16, 3, 0, 1, 1);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget_6 = new QWidget(layoutWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));

        gridLayout->addWidget(widget_6, 1, 0, 1, 1);

        widget_10 = new QWidget(layoutWidget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));

        gridLayout->addWidget(widget_10, 1, 4, 1, 1);

        widget_18 = new QWidget(layoutWidget);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));

        gridLayout->addWidget(widget_18, 3, 2, 1, 1);

        widget_19 = new QWidget(layoutWidget);
        widget_19->setObjectName(QString::fromUtf8("widget_19"));

        gridLayout->addWidget(widget_19, 3, 3, 1, 1);

        widget_5 = new QWidget(layoutWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        gridLayout->addWidget(widget_5, 0, 4, 1, 1);

        widget_9 = new QWidget(layoutWidget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));

        gridLayout->addWidget(widget_9, 1, 3, 1, 1);

        widget_17 = new QWidget(layoutWidget);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));

        gridLayout->addWidget(widget_17, 3, 1, 1, 1);

        widget_14 = new QWidget(layoutWidget);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));

        gridLayout->addWidget(widget_14, 2, 3, 1, 1);

        widget_20 = new QWidget(layoutWidget);
        widget_20->setObjectName(QString::fromUtf8("widget_20"));

        gridLayout->addWidget(widget_20, 3, 4, 1, 1);

        widget_3 = new QWidget(layoutWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        gridLayout->addWidget(widget_3, 0, 2, 1, 1);

        widget_11 = new QWidget(layoutWidget);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));

        gridLayout->addWidget(widget_11, 2, 0, 1, 1);

        widget_13 = new QWidget(layoutWidget);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));

        gridLayout->addWidget(widget_13, 2, 2, 1, 1);

        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        gridLayout->addWidget(widget_4, 0, 3, 1, 1);

        widget_1 = new QWidget(layoutWidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_1->sizePolicy().hasHeightForWidth());
        widget_1->setSizePolicy(sizePolicy);
        widget_1->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(widget_1, 0, 0, 1, 1);


        retranslateUi(Memorija);

        QMetaObject::connectSlotsByName(Memorija);
    } // setupUi

    void retranslateUi(QWidget *Memorija)
    {
        Memorija->setWindowTitle(QApplication::translate("Memorija", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Memorija: public Ui_Memorija {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORIJA_H
