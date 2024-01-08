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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoZnaui
{
  public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QLabel *lbTimer;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lePlayer1_2;
    QLCDNumber *lcdPoints1_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lePlayer2;
    QLCDNumber *lcdPoints2;
    QLabel *labQuestion;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAns3;
    QPushButton *pushButtonAns2;
    QPushButton *pushButtonAns4;
    QPushButton *pushButtonAns1;
    QPushButton *DALJE1;
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
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(50, 50));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lbTimer = new QLabel(frame);
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
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 160, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lePlayer1_2 = new QLineEdit(verticalLayoutWidget);
        lePlayer1_2->setObjectName(QString::fromUtf8("lePlayer1_2"));
        QFont font1;
        font1.setPointSize(20);
        lePlayer1_2->setFont(font1);
        lePlayer1_2->setAutoFillBackground(false);
        lePlayer1_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
                                                     "color: rgb(255, 255, 255);"));
        lePlayer1_2->setAlignment(Qt::AlignCenter);
        lePlayer1_2->setReadOnly(true);

        verticalLayout_4->addWidget(lePlayer1_2);

        lcdPoints1_2 = new QLCDNumber(verticalLayoutWidget);
        lcdPoints1_2->setObjectName(QString::fromUtf8("lcdPoints1_2"));

        verticalLayout_4->addWidget(lcdPoints1_2);

        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(600, 0, 160, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        lePlayer2 = new QLineEdit(verticalLayoutWidget_2);
        lePlayer2->setObjectName(QString::fromUtf8("lePlayer2"));
        lePlayer2->setFont(font1);
        lePlayer2->setAutoFillBackground(false);
        lePlayer2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
                                                   "color: rgb(255, 255, 255);"));
        lePlayer2->setAlignment(Qt::AlignCenter);
        lePlayer2->setReadOnly(true);

        verticalLayout_5->addWidget(lePlayer2);

        lcdPoints2 = new QLCDNumber(verticalLayoutWidget_2);
        lcdPoints2->setObjectName(QString::fromUtf8("lcdPoints2"));

        verticalLayout_5->addWidget(lcdPoints2);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        verticalLayout_2->addLayout(gridLayout_2);

        labQuestion = new QLabel(widget);
        labQuestion->setObjectName(QString::fromUtf8("labQuestion"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(25);
        labQuestion->setFont(font2);
        labQuestion->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        labQuestion->setAlignment(Qt::AlignCenter);
        labQuestion->setWordWrap(true);

        verticalLayout_2->addWidget(labQuestion);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonAns3 = new QPushButton(widget);
        pushButtonAns3->setObjectName(QString::fromUtf8("pushButtonAns3"));
        pushButtonAns3->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns3, 1, 0, 1, 1);

        pushButtonAns2 = new QPushButton(widget);
        pushButtonAns2->setObjectName(QString::fromUtf8("pushButtonAns2"));
        pushButtonAns2->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns2, 0, 1, 1, 1);

        pushButtonAns4 = new QPushButton(widget);
        pushButtonAns4->setObjectName(QString::fromUtf8("pushButtonAns4"));
        pushButtonAns4->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns4, 1, 1, 1, 1);

        pushButtonAns1 = new QPushButton(widget);
        pushButtonAns1->setObjectName(QString::fromUtf8("pushButtonAns1"));
        pushButtonAns1->setEnabled(true);
        pushButtonAns1->setMinimumSize(QSize(200, 50));

        gridLayout->addWidget(pushButtonAns1, 0, 0, 1, 1);

        verticalLayout_2->addLayout(gridLayout);

        DALJE1 = new QPushButton(widget);
        DALJE1->setObjectName(QString::fromUtf8("DALJE1"));

        verticalLayout_2->addWidget(DALJE1);

        KoZnaui->setCentralWidget(widget);
        menubar = new QMenuBar(KoZnaui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        lbTimer->setText(QString());
        labQuestion->setText(QString());
        pushButtonAns3->setText(QString());
        pushButtonAns2->setText(QString());
        pushButtonAns4->setText(QString());
        pushButtonAns1->setText(QString());
        DALJE1->setText(QApplication::translate("KoZnaui", "DALJE", nullptr));
    } // retranslateUi
};

namespace Ui
{
class KoZnaui : public Ui_KoZnaui
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOZNA_H
