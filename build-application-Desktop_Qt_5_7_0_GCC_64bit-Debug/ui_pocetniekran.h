/********************************************************************************
** Form generated from reading UI file 'pocetniekran.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POCETNIEKRAN_H
#define UI_POCETNIEKRAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            PocetniEkran->setObjectName(QStringLiteral("PocetniEkran"));
        PocetniEkran->resize(800, 800);
        PocetniEkran->setMinimumSize(QSize(800, 800));
        PocetniEkran->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(PocetniEkran);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QStringLiteral("background-color: #800020"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(300, 55));
        pushButton_2->setMaximumSize(QSize(300, 55));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: #800020"));

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        pokreniIgruButton = new QPushButton(centralwidget);
        pokreniIgruButton->setObjectName(QStringLiteral("pokreniIgruButton"));
        pokreniIgruButton->setMinimumSize(QSize(300, 55));
        pokreniIgruButton->setMaximumSize(QSize(300, 55));
        pokreniIgruButton->setStyleSheet(QStringLiteral("background-color:  #741515"));

        gridLayout->addWidget(pokreniIgruButton, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        PocetniEkran->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PocetniEkran);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        PocetniEkran->setMenuBar(menubar);

        retranslateUi(PocetniEkran);

        QMetaObject::connectSlotsByName(PocetniEkran);
    } // setupUi

    void retranslateUi(QMainWindow *PocetniEkran)
    {
        PocetniEkran->setWindowTitle(QApplication::translate("PocetniEkran", "PocetniEkran", 0));
        toolButton->setText(QApplication::translate("PocetniEkran", "...", 0));
        pushButton_2->setText(QApplication::translate("PocetniEkran", "Podesavanja", 0));
        pokreniIgruButton->setText(QApplication::translate("PocetniEkran", "Pokreni igru", 0));
    } // retranslateUi

};

namespace Ui {
    class PocetniEkran: public Ui_PocetniEkran {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POCETNIEKRAN_H
