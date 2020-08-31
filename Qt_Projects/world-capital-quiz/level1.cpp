#include "level1.h"
#include "level2.h"
#include <QDebug>

#include <QLabel>
#include <QMessageBox>
#include <QGridLayout>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

Level1:: Level1()

{
    l1_label = new QLabel("What is the capiatal of Australia?");
    l1_button = new QPushButton("Submit");
    l1_textbox = new QLineEdit();

    l1_layout = new QGridLayout();
    l1_dialog = new QDialog();

    l1_layout->addWidget(l1_label, 0, 1);
    l1_layout->addWidget(l1_textbox, 0, 2);
    l1_layout->addWidget(l1_button, 1, 2);

    l1_dialog->setLayout(l1_layout);
    //l1_dialog->exec();
    connect(this->l1_button, SIGNAL (pressed()), this , SLOT (l1_buttonHandler()));

}

void Level1::l1_buttonHandler()
{
    //qDebug("l1_buttonHandler() executed ");
    Level2 level2_obj;
    if (l1_textbox->text() == "Canberra" || "canberra")
    {
        level2_obj.l2_label->setText("What is the capital of Tehran?");
    }
    else
    {
        level2_obj.l2_label->setText("Wrong answer. Try again.");
    }
    level2_obj.exec();

}
