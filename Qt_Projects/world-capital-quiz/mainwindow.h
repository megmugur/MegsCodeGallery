#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QLabel *welcome_window_label;
    QPushButton *welcome_window_button;
    QVBoxLayout *welcome_window_layout;
    QWidget *welcome_window_widget;


private slots:
    void enter_buttonHandler();
};
#endif // MAINWINDOW_H
