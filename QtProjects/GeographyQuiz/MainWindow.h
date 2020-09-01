#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QLabel *welcome_msg_label;
    QPushButton *enter_quiz_button;
    QVBoxLayout *welcome_layout;
    QWidget *welcome_widget;

public slots:
    void enter_buttonHandler();



};

#endif // MAINWINDOW_H
