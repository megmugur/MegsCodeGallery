#include "MainWindow.h"
# include "QuestionDataClass.h"
# include "QuestionWidgetClass.h"

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

/**
 * Initializes the game UI.
 * Creates a stacked widget to hold the welcome page, question pages and the final message page.
 * Questions are loaded from an external website, so the objects required for making connection are setup.
 * It starts with display of the welcome page along with a welcome message.
 * An enter button is setup to invite the user to start the quiz.
 * @param *parent Calls the QMainWindow constructor, and lets us set up parent-child relationship.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    connManager = new QNetworkAccessManager();
    connRequest = new QNetworkRequest();
    stackedWidget = new QStackedWidget();

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

// FINAL PAGE :
    finalPageLayout = new QVBoxLayout();
    finalPageLabel = new QLabel("Congratulations! Quiz completed.");
    finalPageLayout->setAlignment(Qt::AlignCenter);
    finalPageLayout->addWidget(finalPageLabel);


    welcomePageWidget->setLayout(welcomeLayout);
    finalPageWidget->setLayout(finalPageLayout);

    stackedWidget->addWidget(welcomePageWidget);

    stackedWidget->setWindowTitle("Geography Trivia");
    stackedWidget->setMinimumSize(600,200);
    stackedWidget->setCurrentWidget(welcomePageWidget);
    connect (enterQuizButton, SIGNAL (pressed()), this, SLOT (enterButtonHandler()));
    this->setCentralWidget(stackedWidget);
}

/**
 * When the Enter button is pressed, this method is called.
 * It sets up the connection to an external database which contains the questions for the quiz
*/
void MainWindow::enterButtonHandler()
{
    connRequest->setUrl(QUrl("https://opentdb.com/api.php?amount=10&category=22&difficulty=medium&type=multiple"));
    connManager->get(*connRequest);
    connect(connManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkConnMethod(QNetworkReply*)));
    quesNum = 0;

}

/**
 * If there are no errors in connection, it reads the data from the external site,
 * and stores it in a json file.
 */
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

/**
 * Creates an object of the QuestionDataClass and loads the questions into an array/list.
 * The question, one correct answer and 3 wrong answers are separated and stored.
 */
void MainWindow::questionProcessingMethod()
{
    QuestionDataClass dataObj;
    dataObj.jsonObj = jsonObj;
    dataObj.dataProcessingMethod();
    allQuesList = dataObj.allQuesList;
}

/**
 * Handles all the logic in the quesion page. They are multiple choice questions.
 * Displays a question label and 4 buttons as answer choices.
 */
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

/**
 * This method is called when the correct answer is clicked on.
 * The correct answer can appear in any of the 4 answer button positions.
 * If all 10 questions have already been answered, proceeds to the final message page.
 * If not, goes to the next question.
 */
void MainWindow::o1ButtonHandler()
{
    correctFlag = true;
    quesNum++;
    if (quesNum == 10) {finalMessageMethod();}
    else     quesDisplayMethod();
}

/**
 * This method is called when one of the wrong answers is clicked on.
 * Reloads the question page, this time rearranging the answer button positions.
 */
void MainWindow::o2ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}

/**
 * This method is called when one of the wrong answers is clicked on.
 * Reloads the question page, this time rearranging the answer button positions.
 */
void MainWindow::o3ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}

/**
 * This method is called when one of the wrong answers is clicked on.
 * Reloads the question page, this time rearranging the answer button positions.
 */
void MainWindow::o4ButtonHandler()
{
    correctFlag = false;
    quesDisplayMethod();
}

/**
 * Sets the stack to the final page and displays the appropriate end message.
 */
void MainWindow::finalMessageMethod()
{
    stackedWidget->addWidget(finalPageWidget);
    stackedWidget->setCurrentWidget(finalPageWidget);
}

