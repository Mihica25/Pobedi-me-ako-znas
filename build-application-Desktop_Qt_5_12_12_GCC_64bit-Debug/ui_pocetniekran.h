/********************************************************************************
** Form generated from reading UI file 'pocetniekran.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POCETNIEKRAN_H
#define UI_POCETNIEKRAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PocetniEkran
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pokreniIgruButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *PocetniEkran)
    {
        if (PocetniEkran->objectName().isEmpty())
            PocetniEkran->setObjectName(QString::fromUtf8("PocetniEkran"));
        PocetniEkran->resize(800, 800);
        PocetniEkran->setMinimumSize(QSize(800, 800));
        PocetniEkran->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(PocetniEkran);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("background-color: #800020"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(300, 55));
        pushButton_2->setMaximumSize(QSize(300, 55));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #800020"));

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        pokreniIgruButton = new QPushButton(centralwidget);
        pokreniIgruButton->setObjectName(QString::fromUtf8("pokreniIgruButton"));
        pokreniIgruButton->setMinimumSize(QSize(300, 55));
        pokreniIgruButton->setMaximumSize(QSize(300, 55));
        pokreniIgruButton->setStyleSheet(QString::fromUtf8("background-color:  #741515"));

        gridLayout->addWidget(pokreniIgruButton, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        PocetniEkran->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PocetniEkran);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        PocetniEkran->setMenuBar(menubar);

        retranslateUi(PocetniEkran);

        QMetaObject::connectSlotsByName(PocetniEkran);
    } // setupUi

    void retranslateUi(QMainWindow *PocetniEkran)
    {
        PocetniEkran->setWindowTitle(QApplication::translate("PocetniEkran", "PocetniEkran", nullptr));
        toolButton->setText(QApplication::translate("PocetniEkran", "...", nullptr));
        pushButton_2->setText(QApplication::translate("PocetniEkran", "Podesavanja", nullptr));
        pokreniIgruButton->setText(QApplication::translate("PocetniEkran", "Pokreni igru", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PocetniEkran: public Ui_PocetniEkran {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POCETNIEKRAN_H
