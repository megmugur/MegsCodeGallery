#include "level2.h"
#include "level3.h"
#include <QDialog>
#include <QWidget>

Level2::Level2()
{
    l2_layout = new QGridLayout();

    l2_label = new QLabel();
    l2_button = new QPushButton("Submit");
    l2_textbox = new QLineEdit();

    l2_label->setAlignment(Qt::AlignCenter);
    l2_label->setText("What is the capiatal of Egypt?");


    l2_layout->addWidget(l2_label, 0,1);
    l2_layout->addWidget(l2_textbox, 0,2);
    l2_layout->addWidget(l2_button, 1,2);

    setLayout(l2_layout);

    connect(this->l2_button, SIGNAL (pressed()), this, SLOT (this->l2_buttonHandler()));

}


void Level2::l2_buttonHandler()
{
    Level3 l3_obj;
    if (l2_textbox->text() == "Canberra" || "canberra")
    {
        l3_obj.l3_label->setText("Correct answer! Test completed.");
    }
    else
    {
        l3_obj.l3_label->setText("Wrong answer. Try again.");
    }

}
