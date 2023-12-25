/********************************************************************************
** Form generated from reading UI file 'mojbroj.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOJBROJ_H
#define UI_MOJBROJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mojbroj
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_numbers;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_num1;
    QPushButton *pushButton_num2;
    QPushButton *pushButton_num3;
    QPushButton *pushButton_num4;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_num5;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_num6;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_nextRound;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_nextGame;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *pushButton_add;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_div;
    QPushButton *pushButton_leftBr;
    QPushButton *pushButton_rightBr;
    QSpacerItem *horizontalSpacer_30;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_17;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_result;
    QPushButton *pushButton_del;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_submit;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_opponent;
    QSpacerItem *horizontalSpacer_31;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_result_2;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_round;
    QLabel *label_time;

    void setupUi(QWidget *Mojbroj)
    {
        if (Mojbroj->objectName().isEmpty())
            Mojbroj->setObjectName(QStringLiteral("Mojbroj"));
        Mojbroj->resize(800, 800);
        Mojbroj->setMinimumSize(QSize(800, 800));
        Mojbroj->setMaximumSize(QSize(800, 800));
        verticalLayoutWidget = new QWidget(Mojbroj);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 220, 698, 632));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(130, 70));
        textEdit->setMaximumSize(QSize(130, 70));
        QFont font;
        font.setPointSize(20);
        font.setItalic(false);
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        textEdit->setAutoFillBackground(true);
        textEdit->setInputMethodHints(Qt::ImhNone);
        textEdit->setFrameShape(QFrame::WinPanel);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_3->addWidget(textEdit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_numbers = new QHBoxLayout();
        horizontalLayout_numbers->setObjectName(QStringLiteral("horizontalLayout_numbers"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_numbers->addItem(horizontalSpacer_13);

        pushButton_num1 = new QPushButton(verticalLayoutWidget);
        pushButton_num1->setObjectName(QStringLiteral("pushButton_num1"));
        pushButton_num1->setEnabled(false);
        pushButton_num1->setMinimumSize(QSize(70, 70));
        pushButton_num1->setMaximumSize(QSize(70, 70));

        horizontalLayout_numbers->addWidget(pushButton_num1);

        pushButton_num2 = new QPushButton(verticalLayoutWidget);
        pushButton_num2->setObjectName(QStringLiteral("pushButton_num2"));
        pushButton_num2->setEnabled(false);
        pushButton_num2->setMinimumSize(QSize(70, 70));
        pushButton_num2->setMaximumSize(QSize(70, 70));

        horizontalLayout_numbers->addWidget(pushButton_num2);

        pushButton_num3 = new QPushButton(verticalLayoutWidget);
        pushButton_num3->setObjectName(QStringLiteral("pushButton_num3"));
        pushButton_num3->setEnabled(false);
        pushButton_num3->setMinimumSize(QSize(70, 70));
        pushButton_num3->setMaximumSize(QSize(70, 70));

        horizontalLayout_numbers->addWidget(pushButton_num3);

        pushButton_num4 = new QPushButton(verticalLayoutWidget);
        pushButton_num4->setObjectName(QStringLiteral("pushButton_num4"));
        pushButton_num4->setEnabled(false);
        pushButton_num4->setMinimumSize(QSize(70, 70));
        pushButton_num4->setMaximumSize(QSize(70, 70));

        horizontalLayout_numbers->addWidget(pushButton_num4);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_numbers->addItem(horizontalSpacer_14);

        pushButton_num5 = new QPushButton(verticalLayoutWidget);
        pushButton_num5->setObjectName(QStringLiteral("pushButton_num5"));
        pushButton_num5->setEnabled(false);
        pushButton_num5->setMinimumSize(QSize(100, 70));
        pushButton_num5->setMaximumSize(QSize(100, 70));

        horizontalLayout_numbers->addWidget(pushButton_num5);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_numbers->addItem(horizontalSpacer_15);

        pushButton_num6 = new QPushButton(verticalLayoutWidget);
        pushButton_num6->setObjectName(QStringLiteral("pushButton_num6"));
        pushButton_num6->setEnabled(false);
        pushButton_num6->setMinimumSize(QSize(100, 70));
        pushButton_num6->setMaximumSize(QSize(100, 70));

        horizontalLayout_numbers->addWidget(pushButton_num6);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_numbers->addItem(horizontalSpacer_16);


        verticalLayout_3->addLayout(horizontalLayout_numbers);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        pushButton_nextRound = new QPushButton(verticalLayoutWidget);
        pushButton_nextRound->setObjectName(QStringLiteral("pushButton_nextRound"));
        pushButton_nextRound->setMinimumSize(QSize(400, 0));

        horizontalLayout_5->addWidget(pushButton_nextRound);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        pushButton_nextGame = new QPushButton(verticalLayoutWidget);
        pushButton_nextGame->setObjectName(QStringLiteral("pushButton_nextGame"));
        pushButton_nextGame->setMinimumSize(QSize(400, 0));

        horizontalLayout_6->addWidget(pushButton_nextGame);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_29);

        pushButton_add = new QPushButton(verticalLayoutWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setEnabled(false);
        pushButton_add->setMinimumSize(QSize(30, 30));
        pushButton_add->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_add);

        pushButton_sub = new QPushButton(verticalLayoutWidget);
        pushButton_sub->setObjectName(QStringLiteral("pushButton_sub"));
        pushButton_sub->setEnabled(false);
        pushButton_sub->setMinimumSize(QSize(30, 30));
        pushButton_sub->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_sub);

        pushButton_mul = new QPushButton(verticalLayoutWidget);
        pushButton_mul->setObjectName(QStringLiteral("pushButton_mul"));
        pushButton_mul->setEnabled(false);
        pushButton_mul->setMinimumSize(QSize(30, 30));
        pushButton_mul->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_mul);

        pushButton_div = new QPushButton(verticalLayoutWidget);
        pushButton_div->setObjectName(QStringLiteral("pushButton_div"));
        pushButton_div->setEnabled(false);
        pushButton_div->setMinimumSize(QSize(30, 30));
        pushButton_div->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_div);

        pushButton_leftBr = new QPushButton(verticalLayoutWidget);
        pushButton_leftBr->setObjectName(QStringLiteral("pushButton_leftBr"));
        pushButton_leftBr->setEnabled(false);
        pushButton_leftBr->setMinimumSize(QSize(30, 30));
        pushButton_leftBr->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_leftBr);

        pushButton_rightBr = new QPushButton(verticalLayoutWidget);
        pushButton_rightBr->setObjectName(QStringLiteral("pushButton_rightBr"));
        pushButton_rightBr->setEnabled(false);
        pushButton_rightBr->setMinimumSize(QSize(30, 30));
        pushButton_rightBr->setMaximumSize(QSize(30, 30));

        horizontalLayout_14->addWidget(pushButton_rightBr);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_30);


        verticalLayout_3->addLayout(horizontalLayout_14);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_17 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(420, 0));
        lineEdit->setMaximumSize(QSize(420, 16777215));
        lineEdit->setFrame(true);
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lineEdit);

        lineEdit_result = new QLineEdit(verticalLayoutWidget);
        lineEdit_result->setObjectName(QStringLiteral("lineEdit_result"));
        lineEdit_result->setMinimumSize(QSize(70, 0));
        lineEdit_result->setMaximumSize(QSize(70, 16777215));
        lineEdit_result->setFrame(true);
        lineEdit_result->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lineEdit_result);

        pushButton_del = new QPushButton(verticalLayoutWidget);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));
        pushButton_del->setEnabled(false);
        pushButton_del->setMinimumSize(QSize(30, 30));
        pushButton_del->setMaximumSize(QSize(30, 30));

        horizontalLayout_8->addWidget(pushButton_del);

        horizontalSpacer_18 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_19);

        pushButton_submit = new QPushButton(verticalLayoutWidget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));
        pushButton_submit->setEnabled(false);
        pushButton_submit->setMinimumSize(QSize(130, 30));
        pushButton_submit->setMaximumSize(QSize(130, 30));

        horizontalLayout_10->addWidget(pushButton_submit);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_20);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_opponent = new QHBoxLayout();
        horizontalLayout_opponent->setObjectName(QStringLiteral("horizontalLayout_opponent"));
        horizontalSpacer_31 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_opponent->addItem(horizontalSpacer_31);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(420, 0));
        lineEdit_2->setMaximumSize(QSize(420, 16777215));
        lineEdit_2->setFrame(true);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_opponent->addWidget(lineEdit_2);

        lineEdit_result_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_result_2->setObjectName(QStringLiteral("lineEdit_result_2"));
        lineEdit_result_2->setMinimumSize(QSize(70, 0));
        lineEdit_result_2->setMaximumSize(QSize(70, 16777215));
        lineEdit_result_2->setFrame(true);
        lineEdit_result_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_opponent->addWidget(lineEdit_result_2);

        horizontalSpacer_32 = new QSpacerItem(110, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_opponent->addItem(horizontalSpacer_32);


        verticalLayout_3->addLayout(horizontalLayout_opponent);

        verticalSpacer_5 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_round = new QLabel(Mojbroj);
        label_round->setObjectName(QStringLiteral("label_round"));
        label_round->setGeometry(QRect(10, 10, 67, 17));
        label_time = new QLabel(Mojbroj);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(10, 40, 67, 17));

        retranslateUi(Mojbroj);

        QMetaObject::connectSlotsByName(Mojbroj);
    } // setupUi

    void retranslateUi(QWidget *Mojbroj)
    {
        Mojbroj->setWindowTitle(QApplication::translate("Mojbroj", "Moj broj", 0));
        pushButton_num1->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_num2->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_num3->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_num4->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_num5->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_num6->setText(QApplication::translate("Mojbroj", "?", 0));
        pushButton_nextRound->setText(QApplication::translate("Mojbroj", "ZAPOCNI IGRU", 0));
        pushButton_nextGame->setText(QApplication::translate("Mojbroj", "SLEDECA IGRA", 0));
        pushButton_add->setText(QApplication::translate("Mojbroj", "+", 0));
        pushButton_sub->setText(QApplication::translate("Mojbroj", "-", 0));
        pushButton_mul->setText(QApplication::translate("Mojbroj", "*", 0));
        pushButton_div->setText(QApplication::translate("Mojbroj", "/", 0));
        pushButton_leftBr->setText(QApplication::translate("Mojbroj", "(", 0));
        pushButton_rightBr->setText(QApplication::translate("Mojbroj", ")", 0));
        lineEdit->setText(QString());
        lineEdit_result->setText(QString());
        pushButton_del->setText(QApplication::translate("Mojbroj", "del", 0));
        pushButton_submit->setText(QApplication::translate("Mojbroj", "PREDAJ", 0));
        lineEdit_2->setText(QString());
        lineEdit_result_2->setText(QString());
        label_round->setText(QApplication::translate("Mojbroj", "Round 1", 0));
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mojbroj: public Ui_Mojbroj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOJBROJ_H
