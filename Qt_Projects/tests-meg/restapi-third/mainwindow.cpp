#include "mainwindow.h"
# include "questionclass.h"

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
    welcomePageWidget = new  QWidget();
    questionPageWidget = new QWidget();
    finalPageWidget = new QWidget();

    welcomeLayout = new QVBoxLayout();
    outerLayout = new QVBoxLayout();
    finalPageLayout = new QVBoxLayout();


//***************** WELCOME PAGE :********************************************** //
    enterQuizButton = new QPushButton("Enter");
    welcomeLabel = new QLabel("Welcome to Geography Trivia.");
    welcomeLabel->setAlignment(Qt::AlignCenter);

    welcomeLayout->addWidget(welcomeLabel);
    welcomeLayout->addWidget(enterQuizButton);

//***************** QUESTIONS PAGE :******************************************* //
    topWidget = new QWidget();
    midWidget = new QWidget();
    bottomWidget = new QWidget();
    innerLayoutTop = new QHBoxLayout();
    innerLayoutMid = new QGridLayout();
    innerLayoutBottom = new QVBoxLayout();
    qLabel = new QLabel();
    o1Button = new QPushButton();
    o2Button = new QPushButton();
    o3Button = new QPushButton();
    o4Button = new QPushButton();
    wrongLabel = new QLabel();
    chosenAnswer = "";
    quesNum = 0;

    //***************** FINAL PAGE :******************************************* //

    finalPageLayout = new QVBoxLayout();
    finalPageLabel = new QLabel("Congratulations! Quiz completed.");
    finalPageLayout->setAlignment(Qt::AlignCenter);
    finalPageLayout->addWidget(finalPageLabel);

// ************************************************************************* //
    welcomePageWidget->setLayout(welcomeLayout);

    finalPageWidget->setLayout(finalPageLayout);

    stackedWidget->addWidget(welcomePageWidget);
    stackedWidget->addWidget(finalPageWidget);

    this->setCentralWidget(stackedWidget);
    this->setWindowTitle("Geography Trivia");
    this->setMinimumSize(600, 200);
    connect(enterQuizButton, SIGNAL (pressed()), this, SLOT (enterButtonHandler()));

}

void MainWindow::enterButtonHandler()
{
    connError = false;
    connRequest->setUrl(QUrl("https://opentdb.com/api.php?amount=10&category=22&difficulty=medium&type=multiple"));
    connManager->get(*connRequest);
    QObject::connect(connManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkConnMethod(QNetworkReply*)));

}

void MainWindow::networkConnMethod(QNetworkReply *reply)
{

    if (reply->error())
    {
        connError = true;
        qDebug() << reply->errorString();
        return;
    }

    QJsonDocument jsonDoc;

    answer = reply->readAll();
    jsonDoc = QJsonDocument::fromJson(answer.toUtf8());
    jsonObj  = jsonDoc.object();

    if (connError != true)
        { questionProcessingMethod(); }



    qDebug()<< "\n\n" << quesNum << "\n\n";

    qLabel->setText(allQuesList[quesNum][0]);
    o1Button->setText(allQuesList[0][1]);
    o2Button->setText(allQuesList[0][2]);
    o3Button->setText(allQuesList[0][3]);
    o4Button->setText(allQuesList[0][4]);
    qLabel->setText("Q" + QString::number(quesNum+1) + ". " + allQuesList[quesNum][0]);
    o1Button->setText(allQuesList[quesNum][1]);
    o2Button->setText(allQuesList[quesNum][2]);
    o3Button->setText(allQuesList[quesNum][3]);
    o4Button->setText(allQuesList[quesNum][4]);
    int randCol = QRandomGenerator::global()->bounded(2);
    int randRow = QRandomGenerator::global()->bounded(2);
    innerLayoutTop->addWidget(qLabel);
    innerLayoutMid->addWidget(o1Button, randCol,randRow);
    innerLayoutMid->addWidget(o2Button, randCol,1-randRow);
    innerLayoutMid->addWidget(o3Button, 1-randCol,randRow);
    innerLayoutMid->addWidget(o4Button, 1-randCol,1-randRow);
    innerLayoutBottom->addWidget(wrongLabel);
    topWidget->setLayout(innerLayoutTop);
    midWidget->setLayout(innerLayoutMid);
    bottomWidget->setLayout(innerLayoutBottom);
    outerLayout->addWidget(topWidget);
    outerLayout->addWidget(midWidget);
    outerLayout->addWidget(bottomWidget);
    questionPageWidget->setLayout(outerLayout);
    stackedWidget->addWidget(questionPageWidget);
    stackedWidget->setCurrentWidget(questionPageWidget);
    connect(o1Button, SIGNAL (pressed()), this, SLOT (o1ButtonHandler()));
    connect(o2Button, SIGNAL (pressed()), this, SLOT (o2ButtonHandler()));
    connect(o3Button, SIGNAL (pressed()), this, SLOT (o3ButtonHandler()));
    connect(o4Button, SIGNAL (pressed()), this, SLOT (o4ButtonHandler()));
}

// seperate the object into individual question modules
void MainWindow::questionProcessingMethod()
{
    //answeredFlag = false;
    for(iter=jsonObj.begin();iter!=jsonObj.end();iter++)
    {
        if (iter.value().isArray())
        {
            jsonArray = iter.value().toArray();
            for(iter2 = jsonArray.begin(); iter2 != jsonArray.end(); iter2++) eachQuestionMethod();
        }
    }
}

//Make a list of ques.
//Each item in list is, inturn, a list containing: ques, 4 answers
void MainWindow::eachQuestionMethod()
{
    if(!  (iter2->isObject())) return;
    eachQuesObj = iter2->toObject();

    QVector <QString> eachQuesData;

    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "question") ques = iter3.value().toString();
    }
    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "correct_answer")corAns = iter3.value().toString();
    }
    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "incorrect_answers")
      {
          incAns1 = iter3.value().toArray()[0].toString();
          incAns2 = iter3.value().toArray()[1].toString();
          incAns3 = iter3.value().toArray()[2].toString();
      }
    }
    eachQuesData.append(ques);
    eachQuesData.append(corAns);
    eachQuesData.append(incAns1);
    eachQuesData.append(incAns2);
    eachQuesData.append(incAns3);

    allQuesList.append(eachQuesData);
}

void MainWindow::o1ButtonHandler()
{
    if (quesNum < 9)
    {
        correctFlag =true;
        displayMethod(correctFlag);
    }
    else  { finalMessageMethod(); }

}
void MainWindow::o2ButtonHandler()
{
    correctFlag = false;
    displayMethod(correctFlag);
}
void MainWindow::o3ButtonHandler()
{
    correctFlag = false;
    displayMethod(correctFlag);
}
void MainWindow::o4ButtonHandler()
{
    correctFlag = false;
    displayMethod(correctFlag);
}

void MainWindow::displayMethod(bool correctFlag)
{
    if (correctFlag == true) quesNum++;
    qDebug() << "Question #"<< quesNum+1;
    chosenAnswer = o1Button->text();
    qDebug() << "correct answer: " << allQuesList[quesNum][1];
    QuestionClass quesObj;
    quesObj.qLabel->setText("Q" + QString::number(quesNum+1) + ". " + allQuesList[quesNum][0]);
    quesObj.o1Button->setText(allQuesList[quesNum][1]);
    quesObj.o2Button->setText(allQuesList[quesNum][2]);
    quesObj.o3Button->setText(allQuesList[quesNum][3]);
    quesObj.o4Button->setText(allQuesList[quesNum][4]);
    if (correctFlag == false) quesObj.wrongLabel->setText("Wrong. Try again.");
    stackedWidget->addWidget(quesObj.currentQuesWidget);
    stackedWidget->setCurrentWidget(quesObj.currentQuesWidget);
    connect(quesObj.o1Button, SIGNAL (pressed()), this, SLOT (o1ButtonHandler()));
    connect(quesObj.o2Button, SIGNAL (pressed()), this, SLOT (o2ButtonHandler()));
    connect(quesObj.o3Button, SIGNAL (pressed()), this, SLOT (o3ButtonHandler()));
    connect(quesObj.o4Button, SIGNAL (pressed()), this, SLOT (o4ButtonHandler()));
    correctFlag = false;
}

void MainWindow::finalMessageMethod()
{
    stackedWidget->setCurrentWidget(finalPageWidget);
}
