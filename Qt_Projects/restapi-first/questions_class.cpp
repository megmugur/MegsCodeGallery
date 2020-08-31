#include "questions_class.h"
#include "end_class.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QRandomGenerator>

questions_class::questions_class()
{
    q1_label = new QLabel("Question blah blah blah?");
    o1_button = new QPushButton("Option 1");
    o2_button = new QPushButton("Option 2");
    o3_button = new QPushButton("Option 3");
    o4_button = new QPushButton("Option 4");

    outer_layout = new QVBoxLayout();
    inner_layout_top = new QHBoxLayout();
    inner_layout_bottom = new QGridLayout();
    top_widget = new QWidget();
    bottom_widget = new QWidget();

    ques_dialog= new QDialog();
    ques_dialog->resize(500,200);

    int rand_col = QRandomGenerator::global()->bounded(2);
    int rand_row = QRandomGenerator::global()->bounded(2);

    inner_layout_top->addWidget(q1_label);
    inner_layout_bottom->addWidget(o1_button, rand_col,rand_row);
    inner_layout_bottom->addWidget(o2_button, rand_col,1-rand_row);
    inner_layout_bottom->addWidget(o3_button, 1-rand_col,rand_row);
    inner_layout_bottom->addWidget(o4_button, 1-rand_col,1-rand_row);

    top_widget->setLayout(inner_layout_top);
    bottom_widget->setLayout(inner_layout_bottom);
    outer_layout->addWidget(top_widget);
    outer_layout->addWidget(bottom_widget);

    ques_dialog->setLayout(outer_layout);
    ques_dialog->setWindowTitle("Question");

    QString button1_text = o1_button->text();
    QString button2_text = o2_button->text();
    QString button3_text = o3_button->text();
    QString button4_text = o4_button->text();
    connect(this->o1_button, SIGNAL (pressed()), this, SLOT (o1_buttonHandler()));
    connect(this->o2_button, SIGNAL (pressed()), this, SLOT (o2_buttonHandler()));
    connect(this->o3_button, SIGNAL (pressed()), this, SLOT (o3_buttonHandler()));
    connect(this->o4_button, SIGNAL (pressed()), this, SLOT (o4_buttonHandler()));

}


void questions_class::o1_buttonHandler()
{
    chosen_answer = this->o1_button->text() ;
    this->ques_dialog->close();
}

void questions_class::o2_buttonHandler()
{
    chosen_answer = this->o2_button->text() ;
    this->ques_dialog->close();
}
void questions_class::o3_buttonHandler()
{
    chosen_answer = this->o3_button->text() ;
    this->ques_dialog->close();
}
void questions_class::o4_buttonHandler()
{
    chosen_answer = this->o4_button->text() ;
    this->ques_dialog->close();
}
