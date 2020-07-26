#include "onepagequiz_mainwindow.h"
#include "questionswindow_class.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QFont>
#include <QtGui>
#include <QFrame>

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

void MainWindow::enter_buttonHandler()
{
    QuestionsWindow_Class qw_obj;
    qw_obj.q1_label->setText("Greece?");
    qw_obj.ques_dialog->exec();

}
