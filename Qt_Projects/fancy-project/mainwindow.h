#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>   // <> for Qt and "" for user stuff
#include <QPushButton>
#include <QLabel>
#include "QMessageBox"
#include "QHBoxLayout"
#include "QDialog"
#include "QLineEdit"
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton *my_button;
    QLabel *my_label;
    QLineEdit *user_text;
    QHBoxLayout *my_layout;
    MainWindow(QWidget *parent = nullptr);
    QWidget *my_widget;
    QTimer *my_timer;
private slots:
    void buttonHandler();
    void timeDelay();

};
#endif // MAINWINDOW_H
