#include "MainWindow.h"
#include "QuestionsWindowClass.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QFont>
#include <QtGui>
#include <QFrame>

/*
 * This class creates the necessary UI framework for a quiz containing
 * 5 pre-determined Geography questions on a single page.
 * This is just an utterly simple practice test for the more complex quiz application,
 * which will be developed next.
 * A welcome page is created.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    welcome_widget = new QWidget();
    welcome_layout = new QVBoxLayout();
    welcome_msg_label = new QLabel("Welcome to World Capital Trivia!");
    enter_quiz_button = new QPushButton("Enter");

    welcome_layout->addWidget(welcome_msg_label);
    welcome_layout->addWidget(enter_quiz_button);

    welcome_widget->setLayout(welcome_layout);

    this->setCentralWidget(welcome_widget); //need this to display the widgets. w/o this, empty window comes up.

    connect(enter_quiz_button, SIGNAL (pressed()), this, SLOT (enter_buttonHandler()));
}

/*
 * When the enter button is pressed, an object of the question class is created,
 * and the question page is displayed.
 */
void MainWindow::enter_buttonHandler()
{
    QuestionsWindowClass qw_obj;
    qw_obj.ques_dialog->exec();

}
