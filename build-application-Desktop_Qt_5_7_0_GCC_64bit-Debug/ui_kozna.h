/********************************************************************************
** Form generated from reading UI file 'kozna.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOZNA_H
#define UI_KOZNA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
    QLabel *labelTimer;
    QSpacerItem *verticalSpacer_3;
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
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KoZnaui)
    {
        if (KoZnaui->objectName().isEmpty())
            KoZnaui->setObjectName(QStringLiteral("KoZnaui"));
        KoZnaui->resize(800, 800);
        KoZnaui->setMinimumSize(QSize(800, 800));
        KoZnaui->setMaximumSize(QSize(800, 800));
        widget = new QWidget(KoZnaui);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelTimer = new QLabel(widget);
        labelTimer->setObjectName(QStringLiteral("labelTimer"));
        labelTimer->setMinimumSize(QSize(100, 100));
        labelTimer->setMaximumSize(QSize(100, 100));

        verticalLayout_2->addWidget(labelTimer);

        verticalSpacer_3 = new QSpacerItem(20, 220, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(50, 50));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labQuestion = new QLabel(frame);
        labQuestion->setObjectName(QStringLiteral("labQuestion"));
        labQuestion->setGeometry(QRect(36, 10, 711, 31));
        labQuestion->setStyleSheet(QStringLiteral("background-color: white;"));

        verticalLayout->addWidget(frame);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(1000, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonAns4 = new QPushButton(widget);
        pushButtonAns4->setObjectName(QStringLiteral("pushButtonAns4"));
        pushButtonAns4->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns4, 2, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        pushButtonAns3 = new QPushButton(widget);
        pushButtonAns3->setObjectName(QStringLiteral("pushButtonAns3"));
        pushButtonAns3->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns3, 2, 1, 1, 1);

        pushButtonAns2 = new QPushButton(widget);
        pushButtonAns2->setObjectName(QStringLiteral("pushButtonAns2"));
        pushButtonAns2->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns2, 0, 3, 1, 1);

        pushButtonAns1 = new QPushButton(widget);
        pushButtonAns1->setObjectName(QStringLiteral("pushButtonAns1"));
        pushButtonAns1->setEnabled(true);
        pushButtonAns1->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns1, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        KoZnaui->setCentralWidget(widget);
        menubar = new QMenuBar(KoZnaui);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        KoZnaui->setMenuBar(menubar);
        statusbar = new QStatusBar(KoZnaui);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        KoZnaui->setStatusBar(statusbar);

        retranslateUi(KoZnaui);

        QMetaObject::connectSlotsByName(KoZnaui);
    } // setupUi

    void retranslateUi(QMainWindow *KoZnaui)
    {
        KoZnaui->setWindowTitle(QApplication::translate("KoZnaui", "KoZnaui", 0));
        labelTimer->setText(QString());
        labQuestion->setText(QString());
        pushButtonAns4->setText(QString());
        pushButtonAns3->setText(QString());
        pushButtonAns2->setText(QString());
        pushButtonAns1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KoZnaui: public Ui_KoZnaui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOZNA_H
