
#ifndef UI_RECKOUI_H
#define UI_RECKOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReckoUI
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pbPotvrdi1;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_25;
    QPushButton *pbPotvrdi2;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QPushButton *pbPotvrdi3;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QPushButton *pbPotvrdi4;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QLineEdit *lineEdit_36;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QPushButton *pbPotvrdi5;
    QLineEdit *leTimer;
    QLineEdit *leBodovi;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *resenje;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *p1Name;
    QLCDNumber *pl1Points;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *mTimer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *p2Name;
    QLCDNumber *pl2Points;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReckoUI)
    {
        if (ReckoUI->objectName().isEmpty())
            ReckoUI->setObjectName(QString::fromUtf8("ReckoUI"));
        ReckoUI->resize(800, 851);
        centralwidget = new QWidget(ReckoUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 800));
        centralwidget->setMaximumSize(QSize(800, 800));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 330, 481, 346));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_1 = new QLineEdit(verticalLayoutWidget);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setMinimumSize(QSize(60, 60));
        lineEdit_1->setMaximumSize(QSize(60, 60));
        lineEdit_1->setMaxLength(1);
        lineEdit_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_1);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(60, 60));
        lineEdit_2->setMaximumSize(QSize(60, 60));
        lineEdit_2->setMaxLength(1);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(60, 60));
        lineEdit_3->setMaximumSize(QSize(60, 60));
        lineEdit_3->setMaxLength(1);
        lineEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(60, 60));
        lineEdit_4->setMaximumSize(QSize(60, 60));
        lineEdit_4->setMaxLength(1);
        lineEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(60, 60));
        lineEdit_5->setMaximumSize(QSize(60, 60));
        lineEdit_5->setMaxLength(1);
        lineEdit_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_5);


        horizontalLayout->addLayout(horizontalLayout_2);

        pbPotvrdi1 = new QPushButton(verticalLayoutWidget);
        pbPotvrdi1->setObjectName(QString::fromUtf8("pbPotvrdi1"));
        pbPotvrdi1->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(pbPotvrdi1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEdit_21 = new QLineEdit(verticalLayoutWidget);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setMinimumSize(QSize(60, 60));
        lineEdit_21->setMaximumSize(QSize(60, 60));
        lineEdit_21->setMaxLength(1);
        lineEdit_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(lineEdit_21);

        lineEdit_22 = new QLineEdit(verticalLayoutWidget);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setMinimumSize(QSize(60, 60));
        lineEdit_22->setMaximumSize(QSize(60, 60));
        lineEdit_22->setMaxLength(1);
        lineEdit_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(lineEdit_22);

        lineEdit_23 = new QLineEdit(verticalLayoutWidget);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setMinimumSize(QSize(60, 60));
        lineEdit_23->setMaximumSize(QSize(60, 60));
        lineEdit_23->setMaxLength(1);
        lineEdit_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(lineEdit_23);

        lineEdit_24 = new QLineEdit(verticalLayoutWidget);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        lineEdit_24->setMinimumSize(QSize(60, 60));
        lineEdit_24->setMaximumSize(QSize(60, 60));
        lineEdit_24->setMaxLength(1);
        lineEdit_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(lineEdit_24);

        lineEdit_25 = new QLineEdit(verticalLayoutWidget);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        lineEdit_25->setMinimumSize(QSize(60, 60));
        lineEdit_25->setMaximumSize(QSize(60, 60));
        lineEdit_25->setMaxLength(1);
        lineEdit_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(lineEdit_25);


        horizontalLayout_9->addLayout(horizontalLayout_10);

        pbPotvrdi2 = new QPushButton(verticalLayoutWidget);
        pbPotvrdi2->setObjectName(QString::fromUtf8("pbPotvrdi2"));
        pbPotvrdi2->setMinimumSize(QSize(0, 50));

        horizontalLayout_9->addWidget(pbPotvrdi2);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lineEdit_26 = new QLineEdit(verticalLayoutWidget);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));
        lineEdit_26->setMinimumSize(QSize(60, 60));
        lineEdit_26->setMaximumSize(QSize(60, 60));
        lineEdit_26->setMaxLength(1);
        lineEdit_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_26);

        lineEdit_27 = new QLineEdit(verticalLayoutWidget);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));
        lineEdit_27->setMinimumSize(QSize(60, 60));
        lineEdit_27->setMaximumSize(QSize(60, 60));
        lineEdit_27->setMaxLength(1);
        lineEdit_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_27);

        lineEdit_28 = new QLineEdit(verticalLayoutWidget);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        lineEdit_28->setMinimumSize(QSize(60, 60));
        lineEdit_28->setMaximumSize(QSize(60, 60));
        lineEdit_28->setMaxLength(1);
        lineEdit_28->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_28);

        lineEdit_29 = new QLineEdit(verticalLayoutWidget);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));
        lineEdit_29->setMinimumSize(QSize(60, 60));
        lineEdit_29->setMaximumSize(QSize(60, 60));
        lineEdit_29->setMaxLength(1);
        lineEdit_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_29);

        lineEdit_30 = new QLineEdit(verticalLayoutWidget);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));
        lineEdit_30->setMinimumSize(QSize(60, 60));
        lineEdit_30->setMaximumSize(QSize(60, 60));
        lineEdit_30->setMaxLength(1);
        lineEdit_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_30);


        horizontalLayout_11->addLayout(horizontalLayout_12);

        pbPotvrdi3 = new QPushButton(verticalLayoutWidget);
        pbPotvrdi3->setObjectName(QString::fromUtf8("pbPotvrdi3"));
        pbPotvrdi3->setMinimumSize(QSize(0, 50));

        horizontalLayout_11->addWidget(pbPotvrdi3);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        lineEdit_31 = new QLineEdit(verticalLayoutWidget);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        lineEdit_31->setMinimumSize(QSize(60, 60));
        lineEdit_31->setMaximumSize(QSize(60, 60));
        lineEdit_31->setMaxLength(1);
        lineEdit_31->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_31);

        lineEdit_32 = new QLineEdit(verticalLayoutWidget);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        lineEdit_32->setMinimumSize(QSize(60, 60));
        lineEdit_32->setMaximumSize(QSize(60, 60));
        lineEdit_32->setMaxLength(1);
        lineEdit_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_32);

        lineEdit_33 = new QLineEdit(verticalLayoutWidget);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setMinimumSize(QSize(60, 60));
        lineEdit_33->setMaximumSize(QSize(60, 60));
        lineEdit_33->setMaxLength(1);
        lineEdit_33->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_33);

        lineEdit_34 = new QLineEdit(verticalLayoutWidget);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        lineEdit_34->setMinimumSize(QSize(60, 60));
        lineEdit_34->setMaximumSize(QSize(60, 60));
        lineEdit_34->setMaxLength(1);
        lineEdit_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_34);

        lineEdit_35 = new QLineEdit(verticalLayoutWidget);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        lineEdit_35->setMinimumSize(QSize(60, 60));
        lineEdit_35->setMaximumSize(QSize(60, 60));
        lineEdit_35->setMaxLength(1);
        lineEdit_35->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_35);


        horizontalLayout_13->addLayout(horizontalLayout_14);

        pbPotvrdi4 = new QPushButton(verticalLayoutWidget);
        pbPotvrdi4->setObjectName(QString::fromUtf8("pbPotvrdi4"));
        pbPotvrdi4->setMinimumSize(QSize(0, 50));

        horizontalLayout_13->addWidget(pbPotvrdi4);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        lineEdit_36 = new QLineEdit(verticalLayoutWidget);
        lineEdit_36->setObjectName(QString::fromUtf8("lineEdit_36"));
        lineEdit_36->setMinimumSize(QSize(60, 60));
        lineEdit_36->setMaximumSize(QSize(60, 60));
        lineEdit_36->setMaxLength(1);
        lineEdit_36->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_36);

        lineEdit_37 = new QLineEdit(verticalLayoutWidget);
        lineEdit_37->setObjectName(QString::fromUtf8("lineEdit_37"));
        lineEdit_37->setMinimumSize(QSize(60, 60));
        lineEdit_37->setMaximumSize(QSize(60, 60));
        lineEdit_37->setMaxLength(1);
        lineEdit_37->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_37);

        lineEdit_38 = new QLineEdit(verticalLayoutWidget);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));
        lineEdit_38->setMinimumSize(QSize(60, 60));
        lineEdit_38->setMaximumSize(QSize(60, 60));
        lineEdit_38->setMaxLength(1);
        lineEdit_38->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_38);

        lineEdit_39 = new QLineEdit(verticalLayoutWidget);
        lineEdit_39->setObjectName(QString::fromUtf8("lineEdit_39"));
        lineEdit_39->setMinimumSize(QSize(60, 60));
        lineEdit_39->setMaximumSize(QSize(60, 60));
        lineEdit_39->setMaxLength(1);
        lineEdit_39->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_39);

        lineEdit_40 = new QLineEdit(verticalLayoutWidget);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));
        lineEdit_40->setMinimumSize(QSize(60, 60));
        lineEdit_40->setMaximumSize(QSize(60, 60));
        lineEdit_40->setMaxLength(1);
        lineEdit_40->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_40);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        pbPotvrdi5 = new QPushButton(verticalLayoutWidget);
        pbPotvrdi5->setObjectName(QString::fromUtf8("pbPotvrdi5"));
        pbPotvrdi5->setMinimumSize(QSize(0, 50));

        horizontalLayout_15->addWidget(pbPotvrdi5);


        verticalLayout->addLayout(horizontalLayout_15);

        leTimer = new QLineEdit(centralwidget);
        leTimer->setObjectName(QString::fromUtf8("leTimer"));
        leTimer->setGeometry(QRect(360, 230, 60, 60));
        leTimer->setMinimumSize(QSize(60, 60));
        leTimer->setMaximumSize(QSize(60, 60));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        leTimer->setFont(font);
        leTimer->setAlignment(Qt::AlignCenter);
        leBodovi = new QLineEdit(centralwidget);
        leBodovi->setObjectName(QString::fromUtf8("leBodovi"));
        leBodovi->setGeometry(QRect(10, 80, 111, 81));
        QFont font1;
        font1.setPointSize(26);
        leBodovi->setFont(font1);
        leBodovi->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 67, 17));
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 720, 381, 62));
        resenje = new QHBoxLayout(layoutWidget);
        resenje->setObjectName(QString::fromUtf8("resenje"));
        resenje->setContentsMargins(0, 0, 0, 0);
        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(60, 60));
        lineEdit_6->setMaximumSize(QSize(60, 60));
        lineEdit_6->setMaxLength(1);
        lineEdit_6->setAlignment(Qt::AlignCenter);

        resenje->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setMinimumSize(QSize(60, 60));
        lineEdit_7->setMaximumSize(QSize(60, 60));
        lineEdit_7->setMaxLength(1);
        lineEdit_7->setAlignment(Qt::AlignCenter);

        resenje->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setMinimumSize(QSize(60, 60));
        lineEdit_8->setMaximumSize(QSize(60, 60));
        lineEdit_8->setMaxLength(1);
        lineEdit_8->setAlignment(Qt::AlignCenter);

        resenje->addWidget(lineEdit_8);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(60, 60));
        lineEdit_9->setMaximumSize(QSize(60, 60));
        lineEdit_9->setMaxLength(1);
        lineEdit_9->setAlignment(Qt::AlignCenter);

        resenje->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setMinimumSize(QSize(60, 60));
        lineEdit_10->setMaximumSize(QSize(60, 60));
        lineEdit_10->setMaxLength(1);
        lineEdit_10->setAlignment(Qt::AlignCenter);

        resenje->addWidget(lineEdit_10);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 20, 694, 72));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        p1Name = new QLineEdit(layoutWidget_2);
        p1Name->setObjectName(QString::fromUtf8("p1Name"));
        p1Name->setEnabled(false);
        QFont font3;
        font3.setFamily(QString::fromUtf8("8514oem"));
        p1Name->setFont(font3);
        p1Name->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 216, 255);\n"
"color:black;"));
        p1Name->setAlignment(Qt::AlignCenter);
        p1Name->setReadOnly(true);

        verticalLayout_2->addWidget(p1Name);

        pl1Points = new QLCDNumber(layoutWidget_2);
        pl1Points->setObjectName(QString::fromUtf8("pl1Points"));
        pl1Points->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 216, 255);"));

        verticalLayout_2->addWidget(pl1Points);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        mTimer = new QLineEdit(layoutWidget_2);
        mTimer->setObjectName(QString::fromUtf8("mTimer"));
        mTimer->setEnabled(false);
        mTimer->setMinimumSize(QSize(0, 70));
        QFont font4;
        font4.setPointSize(20);
        mTimer->setFont(font4);
        mTimer->setStyleSheet(QString::fromUtf8("QLineEdit  { \n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(76, 130, 196);\n"
"	 border-radius: 10px;\n"
"	border: 2px solid gray;\n"
"	color:black; \n"
"}\n"
""));
        mTimer->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(mTimer, 0, Qt::AlignTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        p2Name = new QLineEdit(layoutWidget_2);
        p2Name->setObjectName(QString::fromUtf8("p2Name"));
        p2Name->setEnabled(false);
        p2Name->setFont(font3);
        p2Name->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 216, 255);\n"
"color:black;"));
        p2Name->setAlignment(Qt::AlignCenter);
        p2Name->setReadOnly(true);

        verticalLayout_3->addWidget(p2Name);

        pl2Points = new QLCDNumber(layoutWidget_2);
        pl2Points->setObjectName(QString::fromUtf8("pl2Points"));
        pl2Points->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 216, 255);"));

        verticalLayout_3->addWidget(pl2Points);


        horizontalLayout_3->addLayout(verticalLayout_3);

        ReckoUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReckoUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        ReckoUI->setMenuBar(menubar);
        statusbar = new QStatusBar(ReckoUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReckoUI->setStatusBar(statusbar);

        retranslateUi(ReckoUI);

        QMetaObject::connectSlotsByName(ReckoUI);
    } // setupUi

    void retranslateUi(QMainWindow *ReckoUI)
    {
        ReckoUI->setWindowTitle(QApplication::translate("ReckoUI", "Recko", nullptr));
        pbPotvrdi1->setText(QApplication::translate("ReckoUI", "Potvrdi", nullptr));
        pbPotvrdi2->setText(QApplication::translate("ReckoUI", "Potvrdi", nullptr));
        pbPotvrdi3->setText(QApplication::translate("ReckoUI", "Potvrdi", nullptr));
        pbPotvrdi4->setText(QApplication::translate("ReckoUI", "Potvrdi", nullptr));
        pbPotvrdi5->setText(QApplication::translate("ReckoUI", "Potvrdi", nullptr));
        label->setText(QApplication::translate("ReckoUI", "Poeni", nullptr));
        p1Name->setText(QApplication::translate("ReckoUI", "Igrac 1: ", nullptr));
        mTimer->setText(QApplication::translate("ReckoUI", "90", nullptr));
        p2Name->setText(QApplication::translate("ReckoUI", "Igrac 2: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReckoUI: public Ui_ReckoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECKOUI_H
