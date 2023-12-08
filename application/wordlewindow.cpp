#include "wordlewindow.h"
#include "ui_wordlewindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QLineEdit>

WordleWindow::WordleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordleWindow)
{
    ui->setupUi(this);
//    connect(,,this, &WordleWindow::handleEnterPressed)
    setUpBackground();
    readQuizWords();
    newWordle();
    disableLineEdits();
//    gameStarted();
//    disableHBoxLayout(6);
}

WordleWindow::~WordleWindow()
{
    delete ui;
}

void WordleWindow::newWordle(){
    srand(time(NULL));
    wordle = quizWords[rand() % quizWords.length()];
    qDebug() << wordle;
}

void WordleWindow::setUpBackground(){
    QPixmap background("/home/dida/Desktop/pobedi-me-ako-znas/application/resources/recko.png");
    background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void WordleWindow::readQuizWords(){
    QFile quizWordsFile("/home/dida/Desktop/pobedi-me-ako-znas/application/resources/QuizWords.txt");
    quizWordsFile.open(QIODevice::ReadOnly);
    QByteArray words = quizWordsFile.readAll();
    quizWords = QString(words).split(" ");
    quizWordsFile.close();
}

void WordleWindow::disableLineEdits(){

    QFormLayout* formLayout = ui->FormLayout1;

    // Iterate through the Form Layout's items
    for (int i = 1; i < formLayout->rowCount(); ++i) {
        QLayoutItem* formItem = formLayout->itemAt(i);

        // Check if the item is a layout
        if (formItem->layout()) {
            QHBoxLayout* horizontalLayout = qobject_cast<QHBoxLayout*>(formItem->layout());

            // Check if it's a QHBoxLayout
            if (horizontalLayout) {
                for (int j = 0; j < horizontalLayout->count(); ++j) {
                    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());

                    if (lineEdit) {
                        lineEdit->setDisabled(true);
                        qDebug() << "input for QLineEdit:" << lineEdit->objectName();
                    }
                }
            }
        }
    }
}


void WordleWindow::disableHBoxLayout(int i){

    if ( i >= ui->FormLayout1->rowCount() || i < 0){
        qWarning() << "Incorrect HBoxLayout index";
        return;
    }

    QHBoxLayout* horizontalLayout = qobject_cast<QHBoxLayout*>(ui->FormLayout1->itemAt(i)->layout());
    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());
        if (lineEdit) {
            lineEdit->setDisabled(true);
            qDebug() << "input for QLineEdit:" << lineEdit->objectName();
        }
    }
}

void WordleWindow::enableHBoxLayout(int i){

    if ( i >= ui->FormLayout1->rowCount() || i < 0){
        qWarning() << "Incorrect HBoxLayout index";
        return;
    }

    QHBoxLayout* horizontalLayout = qobject_cast<QHBoxLayout*>(ui->FormLayout1->itemAt(i)->layout());
    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());
        if (lineEdit) {
            lineEdit->setDisabled(false);
            qDebug() << "input for QLineEdit:" << lineEdit->objectName();
        }
    }
}

void WordleWindow::handleEnterPressed(){
    int hits = 0;
    QHBoxLayout* horizontalLayout = qobject_cast<QHBoxLayout*>(ui->FormLayout1->itemAt(tryNumber)->layout());
    for (int j = 0; j < horizontalLayout->count(); ++j){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(horizontalLayout->itemAt(j)->widget());
        if (lineEdit) {
            QString userInput = lineEdit->text();
            if(userInput.compare(wordle.at(j), Qt::CaseInsensitive) == 0){
                hits++;
                lineEdit->setStyleSheet("background-color: green;");
            }
        }
    }
    disableHBoxLayout(tryNumber);
    if(hits == 5){
        guessed = true;
        isGameFinished = true;
        return;
    }
    tryNumber++;
    if(tryNumber >= 5){
        isGameFinished = true;
        return;
    }
    enableHBoxLayout(tryNumber);


}

void WordleWindow::gameStarted(){
    qDebug() << "GAME STARTED";
    while(!isGameFinished){
//        if (tryNumber >=5 || guessed){
//            break
//        }
    }
    qDebug() << "GAME ENDED";
    return;
}
