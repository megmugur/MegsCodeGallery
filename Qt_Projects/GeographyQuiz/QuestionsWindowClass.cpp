#include "QuestionsWindowClass.h"
#include "ResultWindowClass.h"
#include <QDebug>

#include <QLabel>
#include <QMessageBox>
#include <QGridLayout>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

/*
 * This class creates the necessary UI for the question page.
 * It contains 5 pre-determined Geography questions.
 */
QuestionsWindowClass::QuestionsWindowClass()
{

    q1_label = new QLabel("What is the capital of Greece?");
    q2_label = new QLabel("What is the capital of Fiji?");
    q3_label = new QLabel("What is the capital of Madagascar?");
    q4_label = new QLabel("What is the capital of Greenland?");
    q5_label = new QLabel("What is the capital of Georgia?");

    a1_label = new QLabel();
    a2_label = new QLabel();
    a3_label = new QLabel();
    a4_label = new QLabel();
    a5_label = new QLabel();

    q1_textbox = new QLineEdit();
    q2_textbox = new QLineEdit();
    q3_textbox = new QLineEdit();
    q4_textbox = new QLineEdit();
    q5_textbox = new QLineEdit();

    ques_layout = new QGridLayout();
    ques_dialog= new QDialog();
    submit_button = new QPushButton("Submit");

    ques_layout->addWidget(q1_label, 1,1);
    ques_layout->addWidget(q2_label, 2,1);
    ques_layout->addWidget(q3_label, 3,1);
    ques_layout->addWidget(q4_label, 4,1);
    ques_layout->addWidget(q5_label, 5,1);

    ques_layout->addWidget(q1_textbox, 1,2);
    ques_layout->addWidget(q2_textbox, 2,2);
    ques_layout->addWidget(q3_textbox, 3,2);
    ques_layout->addWidget(q4_textbox, 4,2);
    ques_layout->addWidget(q5_textbox, 5,2);

    ques_layout->addWidget(submit_button, 6, 2);

    ques_dialog->setLayout(ques_layout);

    connect(this->submit_button, SIGNAL (pressed()), this, SLOT (submit_buttonHandler()));
}

/*
 * Checks if all the answers are correct, and displays an appropriate result message
 * by creating an object of the result class.
 */
void QuestionsWindowClass::submit_buttonHandler()
{
    ResultWindowClass res_obj;

    if (q1_textbox->text() == "athens" && q2_textbox->text() == "suva" && q3_textbox->text() == "antananarivo" && q4_textbox->text() == "nuuk" && q5_textbox->text() == "tbilisi")
    {
        res_obj.result_label->setText("Congratulations, you have passed to the next level!");
    }
    else
    {
        res_obj.result_label->setText("One or more answers were incorrect. Please try again.");
    }

    res_obj.exec();

}
