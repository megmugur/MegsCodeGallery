#include "mainwindow.h"
#include "level1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    welcome_window_widget = new QWidget();
    welcome_window_label = new QLabel();
    welcome_window_button = new QPushButton();
    welcome_window_layout = new QVBoxLayout();


    welcome_window_label->setText("Welcome to World Capital Quiz!");
    welcome_window_label->setAlignment(Qt::AlignCenter);
    welcome_window_button->setText("Start");
    welcome_window_layout->addWidget(welcome_window_label);
    welcome_window_layout->addWidget(welcome_window_button);
    welcome_window_widget->setLayout(welcome_window_layout);

    this->setWindowTitle("World Capital Quiz");
    this->setCentralWidget(welcome_window_widget);
    this->setGeometry(0,0,300,100);

    connect(welcome_window_button, SIGNAL (pressed()), this, SLOT (enter_buttonHandler()));

}


void MainWindow::enter_buttonHandler()
{

    //qDebug("welcome_buttonHandler() executed ");
    Level1 l1_obj;

    l1_obj.l1_dialog->exec();
}
