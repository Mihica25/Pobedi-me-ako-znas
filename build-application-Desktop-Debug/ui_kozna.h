/********************************************************************************
** Form generated from reading UI file 'kozna.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOZNA_H
#define UI_KOZNA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoZnaui
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *poeni1;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTimer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *poeni2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *labQuestion;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAns4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonAns3;
    QPushButton *pushButtonAns2;
    QPushButton *pushButtonAns1;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QPushButton *DALJE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KoZnaui)
    {
        if (KoZnaui->objectName().isEmpty())
            KoZnaui->setObjectName(QString::fromUtf8("KoZnaui"));
        KoZnaui->resize(800, 800);
        KoZnaui->setMinimumSize(QSize(800, 800));
        KoZnaui->setMaximumSize(QSize(800, 800));
        widget = new QWidget(KoZnaui);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 100, -1, -1);
        poeni1 = new QLabel(widget);
        poeni1->setObjectName(QString::fromUtf8("poeni1"));
        poeni1->setMinimumSize(QSize(100, 100));
        poeni1->setMaximumSize(QSize(100, 100));
        poeni1->setStyleSheet(QString::fromUtf8("background-color: white"));

        horizontalLayout->addWidget(poeni1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelTimer = new QLabel(widget);
        labelTimer->setObjectName(QString::fromUtf8("labelTimer"));
        labelTimer->setMinimumSize(QSize(100, 100));
        labelTimer->setMaximumSize(QSize(100, 100));
        labelTimer->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(labelTimer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        poeni2 = new QLabel(widget);
        poeni2->setObjectName(QString::fromUtf8("poeni2"));
        poeni2->setMinimumSize(QSize(100, 100));
        poeni2->setMaximumSize(QSize(100, 100));
        poeni2->setStyleSheet(QString::fromUtf8("background-color: white"));

        horizontalLayout->addWidget(poeni2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(50, 50));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labQuestion = new QLabel(frame);
        labQuestion->setObjectName(QString::fromUtf8("labQuestion"));
        labQuestion->setGeometry(QRect(36, 10, 711, 31));
        labQuestion->setStyleSheet(QString::fromUtf8("background-color: white;"));

        verticalLayout->addWidget(frame);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(1000, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonAns4 = new QPushButton(widget);
        pushButtonAns4->setObjectName(QString::fromUtf8("pushButtonAns4"));
        pushButtonAns4->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns4, 2, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        pushButtonAns3 = new QPushButton(widget);
        pushButtonAns3->setObjectName(QString::fromUtf8("pushButtonAns3"));
        pushButtonAns3->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns3, 2, 1, 1, 1);

        pushButtonAns2 = new QPushButton(widget);
        pushButtonAns2->setObjectName(QString::fromUtf8("pushButtonAns2"));
        pushButtonAns2->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns2, 0, 3, 1, 1);

        pushButtonAns1 = new QPushButton(widget);
        pushButtonAns1->setObjectName(QString::fromUtf8("pushButtonAns1"));
        pushButtonAns1->setEnabled(true);
        pushButtonAns1->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns1, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        DALJE = new QPushButton(widget);
        DALJE->setObjectName(QString::fromUtf8("DALJE"));

        verticalLayout_2->addWidget(DALJE);

        KoZnaui->setCentralWidget(widget);
        menubar = new QMenuBar(KoZnaui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        KoZnaui->setMenuBar(menubar);
        statusbar = new QStatusBar(KoZnaui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        KoZnaui->setStatusBar(statusbar);

        retranslateUi(KoZnaui);

        QMetaObject::connectSlotsByName(KoZnaui);
    } // setupUi

    void retranslateUi(QMainWindow *KoZnaui)
    {
        KoZnaui->setWindowTitle(QApplication::translate("KoZnaui", "KoZnaui", nullptr));
        poeni1->setText(QString());
        labelTimer->setText(QString());
        poeni2->setText(QString());
        labQuestion->setText(QString());
        pushButtonAns4->setText(QString());
        pushButtonAns3->setText(QString());
        pushButtonAns2->setText(QString());
        pushButtonAns1->setText(QString());
        DALJE->setText(QApplication::translate("KoZnaui", "DALJE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KoZnaui: public Ui_KoZnaui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOZNA_H
