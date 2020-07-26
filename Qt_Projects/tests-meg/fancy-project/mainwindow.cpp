#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QMessageBox"
#include "QGridLayout"
#include "QDialog"
#include "QLineEdit"
#include "popupclass.h"
#include "secondpopup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    my_widget = new QWidget();
    my_label = new QLabel("What is the capital of Australia?");
    user_text = new QLineEdit();
    my_button= new QPushButton("Submit");
    my_timer = new QTimer();
    my_timer->setInterval(500);
    my_layout = new QHBoxLayout;
    my_layout->addWidget(my_label);
    my_layout->addWidget(user_text);
    my_layout->addWidget(my_button);
    my_widget->setLayout(my_layout);
    my_widget->setWindowTitle("Level 2");

    my_timer->setSingleShot(true); //to run only once
    this->setCentralWidget(my_widget);
    connect(my_button, SIGNAL (pressed()), this, SLOT (buttonHandler()));
    connect(my_timer, SIGNAL(timeout()), this, SLOT (timeDelay()) );
}

void MainWindow::buttonHandler()
{
    my_timer->start();
}

void MainWindow::timeDelay()
{
    PopupClass popup_obj;
    if (user_text->text() =="Canberra" || "canberra")
    {
        popup_obj.popup_label->setText(user_text->text() + " was the correct answer!\n\n What is the capital of Washington?");

        //SecondPopupClass second_popup_obj;


    }
    else
    {
        popup_obj.popup_label->setText("Wrong answer. Try again.");
    }
    popup_obj.exec();
}
