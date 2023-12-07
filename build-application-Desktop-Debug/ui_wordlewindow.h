/********************************************************************************
** Form generated from reading UI file 'wordlewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDLEWINDOW_H
#define UI_WORDLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordleWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_25;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WordleWindow)
    {
        if (WordleWindow->objectName().isEmpty())
            WordleWindow->setObjectName(QString::fromUtf8("WordleWindow"));
        WordleWindow->resize(800, 600);
        centralwidget = new QWidget(WordleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 100, 711, 341));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit->setMaxLength(1);
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);
        lineEdit_5->setFont(font);
        lineEdit_5->setAutoFillBackground(true);
        lineEdit_5->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_5->setMaxLength(1);
        lineEdit_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_5);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setFont(font);
        lineEdit_4->setAutoFillBackground(true);
        lineEdit_4->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_4->setMaxLength(1);
        lineEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_4);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setFont(font);
        lineEdit_3->setAutoFillBackground(true);
        lineEdit_3->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_3->setMaxLength(1);
        lineEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setFont(font);
        lineEdit_2->setAutoFillBackground(true);
        lineEdit_2->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_2->setMaxLength(1);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_2);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_6 = new QLineEdit(formLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setFont(font);
        lineEdit_6->setAutoFillBackground(true);
        lineEdit_6->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_6->setMaxLength(1);
        lineEdit_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(formLayoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);
        lineEdit_7->setFont(font);
        lineEdit_7->setAutoFillBackground(true);
        lineEdit_7->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_7->setMaxLength(1);
        lineEdit_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(formLayoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);
        lineEdit_8->setFont(font);
        lineEdit_8->setAutoFillBackground(true);
        lineEdit_8->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_8->setMaxLength(1);
        lineEdit_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_8);

        lineEdit_9 = new QLineEdit(formLayoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);
        lineEdit_9->setFont(font);
        lineEdit_9->setAutoFillBackground(true);
        lineEdit_9->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_9->setMaxLength(1);
        lineEdit_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(formLayoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy);
        lineEdit_10->setFont(font);
        lineEdit_10->setAutoFillBackground(true);
        lineEdit_10->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_10->setMaxLength(1);
        lineEdit_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_10);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_11 = new QLineEdit(formLayoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);
        lineEdit_11->setFont(font);
        lineEdit_11->setAutoFillBackground(true);
        lineEdit_11->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_11->setMaxLength(1);
        lineEdit_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_11);

        lineEdit_12 = new QLineEdit(formLayoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        sizePolicy.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy);
        lineEdit_12->setFont(font);
        lineEdit_12->setAutoFillBackground(true);
        lineEdit_12->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_12->setMaxLength(1);
        lineEdit_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_12);

        lineEdit_13 = new QLineEdit(formLayoutWidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        sizePolicy.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy);
        lineEdit_13->setFont(font);
        lineEdit_13->setAutoFillBackground(true);
        lineEdit_13->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_13->setMaxLength(1);
        lineEdit_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_13);

        lineEdit_14 = new QLineEdit(formLayoutWidget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        sizePolicy.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy);
        lineEdit_14->setFont(font);
        lineEdit_14->setAutoFillBackground(true);
        lineEdit_14->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_14->setMaxLength(1);
        lineEdit_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_14);

        lineEdit_15 = new QLineEdit(formLayoutWidget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        sizePolicy.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy);
        lineEdit_15->setFont(font);
        lineEdit_15->setAutoFillBackground(true);
        lineEdit_15->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_15->setMaxLength(1);
        lineEdit_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_15);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_16 = new QLineEdit(formLayoutWidget);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        sizePolicy.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy);
        lineEdit_16->setFont(font);
        lineEdit_16->setAutoFillBackground(true);
        lineEdit_16->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_16->setMaxLength(1);
        lineEdit_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_16);

        lineEdit_17 = new QLineEdit(formLayoutWidget);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        sizePolicy.setHeightForWidth(lineEdit_17->sizePolicy().hasHeightForWidth());
        lineEdit_17->setSizePolicy(sizePolicy);
        lineEdit_17->setFont(font);
        lineEdit_17->setAutoFillBackground(true);
        lineEdit_17->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_17->setMaxLength(1);
        lineEdit_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_17);

        lineEdit_18 = new QLineEdit(formLayoutWidget);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        sizePolicy.setHeightForWidth(lineEdit_18->sizePolicy().hasHeightForWidth());
        lineEdit_18->setSizePolicy(sizePolicy);
        lineEdit_18->setFont(font);
        lineEdit_18->setAutoFillBackground(true);
        lineEdit_18->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_18->setMaxLength(1);
        lineEdit_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_18);

        lineEdit_19 = new QLineEdit(formLayoutWidget);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        sizePolicy.setHeightForWidth(lineEdit_19->sizePolicy().hasHeightForWidth());
        lineEdit_19->setSizePolicy(sizePolicy);
        lineEdit_19->setFont(font);
        lineEdit_19->setAutoFillBackground(true);
        lineEdit_19->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_19->setMaxLength(1);
        lineEdit_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_19);

        lineEdit_20 = new QLineEdit(formLayoutWidget);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        sizePolicy.setHeightForWidth(lineEdit_20->sizePolicy().hasHeightForWidth());
        lineEdit_20->setSizePolicy(sizePolicy);
        lineEdit_20->setFont(font);
        lineEdit_20->setAutoFillBackground(true);
        lineEdit_20->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_20->setMaxLength(1);
        lineEdit_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_20);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_21 = new QLineEdit(formLayoutWidget);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        sizePolicy.setHeightForWidth(lineEdit_21->sizePolicy().hasHeightForWidth());
        lineEdit_21->setSizePolicy(sizePolicy);
        lineEdit_21->setFont(font);
        lineEdit_21->setAutoFillBackground(true);
        lineEdit_21->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_21->setMaxLength(1);
        lineEdit_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_21);

        lineEdit_22 = new QLineEdit(formLayoutWidget);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        sizePolicy.setHeightForWidth(lineEdit_22->sizePolicy().hasHeightForWidth());
        lineEdit_22->setSizePolicy(sizePolicy);
        lineEdit_22->setFont(font);
        lineEdit_22->setAutoFillBackground(true);
        lineEdit_22->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_22->setMaxLength(1);
        lineEdit_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_22);

        lineEdit_23 = new QLineEdit(formLayoutWidget);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        sizePolicy.setHeightForWidth(lineEdit_23->sizePolicy().hasHeightForWidth());
        lineEdit_23->setSizePolicy(sizePolicy);
        lineEdit_23->setFont(font);
        lineEdit_23->setAutoFillBackground(true);
        lineEdit_23->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_23->setMaxLength(1);
        lineEdit_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_23);

        lineEdit_24 = new QLineEdit(formLayoutWidget);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        sizePolicy.setHeightForWidth(lineEdit_24->sizePolicy().hasHeightForWidth());
        lineEdit_24->setSizePolicy(sizePolicy);
        lineEdit_24->setFont(font);
        lineEdit_24->setAutoFillBackground(true);
        lineEdit_24->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_24->setMaxLength(1);
        lineEdit_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_24);

        lineEdit_25 = new QLineEdit(formLayoutWidget);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        sizePolicy.setHeightForWidth(lineEdit_25->sizePolicy().hasHeightForWidth());
        lineEdit_25->setSizePolicy(sizePolicy);
        lineEdit_25->setFont(font);
        lineEdit_25->setAutoFillBackground(true);
        lineEdit_25->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_25->setMaxLength(1);
        lineEdit_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_25);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_26 = new QLineEdit(formLayoutWidget);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));
        sizePolicy.setHeightForWidth(lineEdit_26->sizePolicy().hasHeightForWidth());
        lineEdit_26->setSizePolicy(sizePolicy);
        lineEdit_26->setFont(font);
        lineEdit_26->setAutoFillBackground(true);
        lineEdit_26->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_26->setMaxLength(1);
        lineEdit_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit_26);

        lineEdit_27 = new QLineEdit(formLayoutWidget);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));
        sizePolicy.setHeightForWidth(lineEdit_27->sizePolicy().hasHeightForWidth());
        lineEdit_27->setSizePolicy(sizePolicy);
        lineEdit_27->setFont(font);
        lineEdit_27->setAutoFillBackground(true);
        lineEdit_27->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_27->setMaxLength(1);
        lineEdit_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit_27);

        lineEdit_28 = new QLineEdit(formLayoutWidget);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        sizePolicy.setHeightForWidth(lineEdit_28->sizePolicy().hasHeightForWidth());
        lineEdit_28->setSizePolicy(sizePolicy);
        lineEdit_28->setFont(font);
        lineEdit_28->setAutoFillBackground(true);
        lineEdit_28->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_28->setMaxLength(1);
        lineEdit_28->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit_28);

        lineEdit_29 = new QLineEdit(formLayoutWidget);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));
        sizePolicy.setHeightForWidth(lineEdit_29->sizePolicy().hasHeightForWidth());
        lineEdit_29->setSizePolicy(sizePolicy);
        lineEdit_29->setFont(font);
        lineEdit_29->setAutoFillBackground(true);
        lineEdit_29->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_29->setMaxLength(1);
        lineEdit_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit_29);

        lineEdit_30 = new QLineEdit(formLayoutWidget);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));
        sizePolicy.setHeightForWidth(lineEdit_30->sizePolicy().hasHeightForWidth());
        lineEdit_30->setSizePolicy(sizePolicy);
        lineEdit_30->setFont(font);
        lineEdit_30->setAutoFillBackground(true);
        lineEdit_30->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_30->setMaxLength(1);
        lineEdit_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit_30);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_31 = new QLineEdit(formLayoutWidget);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        sizePolicy.setHeightForWidth(lineEdit_31->sizePolicy().hasHeightForWidth());
        lineEdit_31->setSizePolicy(sizePolicy);
        lineEdit_31->setFont(font);
        lineEdit_31->setAutoFillBackground(true);
        lineEdit_31->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_31->setMaxLength(1);
        lineEdit_31->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_31);

        lineEdit_32 = new QLineEdit(formLayoutWidget);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        sizePolicy.setHeightForWidth(lineEdit_32->sizePolicy().hasHeightForWidth());
        lineEdit_32->setSizePolicy(sizePolicy);
        lineEdit_32->setFont(font);
        lineEdit_32->setAutoFillBackground(true);
        lineEdit_32->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_32->setMaxLength(1);
        lineEdit_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_32);

        lineEdit_33 = new QLineEdit(formLayoutWidget);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        sizePolicy.setHeightForWidth(lineEdit_33->sizePolicy().hasHeightForWidth());
        lineEdit_33->setSizePolicy(sizePolicy);
        lineEdit_33->setFont(font);
        lineEdit_33->setAutoFillBackground(true);
        lineEdit_33->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_33->setMaxLength(1);
        lineEdit_33->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_33);

        lineEdit_34 = new QLineEdit(formLayoutWidget);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        sizePolicy.setHeightForWidth(lineEdit_34->sizePolicy().hasHeightForWidth());
        lineEdit_34->setSizePolicy(sizePolicy);
        lineEdit_34->setFont(font);
        lineEdit_34->setAutoFillBackground(true);
        lineEdit_34->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_34->setMaxLength(1);
        lineEdit_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_34);

        lineEdit_35 = new QLineEdit(formLayoutWidget);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        sizePolicy.setHeightForWidth(lineEdit_35->sizePolicy().hasHeightForWidth());
        lineEdit_35->setSizePolicy(sizePolicy);
        lineEdit_35->setFont(font);
        lineEdit_35->setAutoFillBackground(true);
        lineEdit_35->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineEdit_35->setMaxLength(1);
        lineEdit_35->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_35);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_7);

        WordleWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WordleWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        WordleWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WordleWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WordleWindow->setStatusBar(statusbar);

        retranslateUi(WordleWindow);

        QMetaObject::connectSlotsByName(WordleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WordleWindow)
    {
        WordleWindow->setWindowTitle(QApplication::translate("WordleWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordleWindow: public Ui_WordleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDLEWINDOW_H
