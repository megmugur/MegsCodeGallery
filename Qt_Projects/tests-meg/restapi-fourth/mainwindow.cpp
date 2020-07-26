#include "mainwindow.h"
# include "questiondataclass.h"
# include "questionwidgetclass.h"

#include <QJsonDocument>
#include <QRandomGenerator>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    connManager = new QNetworkAccessManager();
    connRequest = new QNetworkRequest();
    stackedWidget = new QStackedWidget();
    this->setWindowTitle("Geography Trivia");
    stackedWidget->setMinimumSize(600,200);
    welcomePageWidget = new  QWidget();
    finalPageWidget = new QWidget();

    welcomeLayout = new QVBoxLayout();
    finalPageLayout = new QVBoxLayout();

// WELCOME PAGE :
    enterQuizButton = new QPushButton("Enter");
    welcomeLabel = new QLabel("Welcome to Geography Trivia.");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLayout->addWidget(welcomeLabel);
    welcomeLayout->addWidget(enterQuizButton);

//FINAL PAGE :
    finalPageLayout = new QVBoxLayout();
    finalPageLabel = new QLabel("Congratulations! Quiz completed.");
    finalPageLayout->setAlignment(Qt::AlignCenter);
    finalPageLayout->addWidget(finalPageLabel);


    welcomePageWidget->setLayout(welcomeLayout);
    finalPageWidget->setLayout(finalPageLayout);

    stackedWidget->addWidget(welcomePageWidget);

    stackedWidget->setCurrentWidget(welcomePageWidget);
    connect (enterQuizButton, SIGNAL (pressed()), this, SLOT (enterButtonHandler()));
    this->setCentralWidget(stackedWidget);


}

void MainWindow::enterButtonHandler()
{
    connRequest->setUrl(QUrl("https://opentdb.com/api.php?amount=10&category=22&difficulty=medium&type=multiple"));
    connManager->get(*connRequest);
    connect(connManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkConnMethod(QNetworkReply*)));
    quesNum = 0;

    //connect(connManager, &QNetworkAccessManager::finished, connManager, &QNetworkAccessManager::deleteLater);
}

void MainWindow::networkConnMethod(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }
    QJsonDocument jsonDoc;

    answer = reply->readAll();
    jsonDoc = QJsonDocument::fromJson(answer.toUtf8());
    jsonObj  = jsonDoc.object();

    correctFlag = true;
    questionProcessingMethod();
    quesDisplayMethod();
}

void MainWindow::questionProcessingMethod()
{
    QuestionDataClass dataObj;
    dataObj.jsonObj = jsonObj;
    dataObj.dataProcessingMethod();
    allQuesList = dataObj.allQuesList;
}


void MainWindow::quesDisplayMethod()
{
    QuestionWidgetClass widObj;
    widObj.qLabel->setText("Q" + QString::number(quesNum+1) + ". " + allQuesList[quesNum][0]);
    widObj.o1Button->setText(allQuesList[quesNum][1]);
    widObj.o2Button->setText(allQuesList[quesNum][2]);
    widObj.o3Button->setText(allQuesList[quesNum][3]);
    widObj.o4Button->setText(allQuesList[quesNum][4]);

    connect(widObj.o1Button, SIGNAL (pressed()), this, SLOT (o1ButtonHandler()));
    connect(widObj.o2Button, SIGNAL (pressed()), this, SLOT (o2ButtonHandler()));
    connect(widObj.o3Button, SIGNAL (pressed()), this, SLOT (o3ButtonHandler()));
    connect(widObj.o4Button, SIGNAL (pressed()), this, SLOT (o4ButtonHandler()));

    if (correctFlag == false) widObj.wrongLabel->setText("Wrong answer. Try again.");
    stackedWidget->addWidget(widObj.questionPageWidget);
    stackedWidget->setCurrentWidget(widObj.questionPageWidget);
    correctFlag = false;

}



void MainWindow::o1ButtonHandler()
{
    correctFlag = true;
    quesNum++;
    if (quesNum == 10) {finalMessageMethod();}
    else     quesDisplayMethod();
}
void MainWindow::o2ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}
void MainWindow::o3ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}
void MainWindow::o4ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}

void MainWindow::finalMessageMethod()
{
    stackedWidget->addWidget(finalPageWidget);
    stackedWidget->setCurrentWidget(finalPageWidget);
}


