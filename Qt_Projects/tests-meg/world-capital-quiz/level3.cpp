#include "level3.h"

Level3::Level3()
{

    //l3_dialog = new QDialog();
    l3_label = new QLabel();
    //l3_button = new QPushButton();
    l3_layout = new QHBoxLayout();
    //l3_textbox = new QLineEdit();


    l3_label->setText("What is the capiatal of Goa?");
    l3_label->setAlignment(Qt::AlignCenter);
    //l3_button->setText("Submit");

    l3_layout->addWidget(l3_label);
    //l3_layout->addWidget(l3_button);
    setLayout(l3_layout);

    //setLayout(l3_layout);
    //this->setGeometry(0,0,300,200);

    //connect(l3_button, SIGNAL (pressed()), this, SLOT (l3_buttonHandler()));
    //l3_dialog->exec();
}
