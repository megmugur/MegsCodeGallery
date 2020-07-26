#include <QApplication>
#include "QDialog"
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QGridLayout"
#include "QMessageBox"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *my_window = new MainWindow(nullptr);
    my_window->show();
    return app.exec();
}


