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

    QWidget *master_widget;
    QWidget *up_widget;
    QWidget *down_widget;
    QWidget *down_left_widget;
    QWidget *down_mid_widget;
    QWidget *down_right_widget;
    QWidget *prev_play_widget;
    QWidget *devices_widget;
    QWidget *add_remove_widget;


    QLabel *take_label;
    QLabel *notes_label;
    QLabel *desc_label;
    QLabel *time_label;
    QLabel *take_button;
    QLabel *notes_button;
    QLabel *desc_button;
    QLabel *info_button;
    QLabel *select_button;

    QPushButton *play_button;
    QPushButton *prev_button;
    QPushButton *next_button;
    QPushButton *record_button;
    QPushButton *plus_button;
    QPushButton *minus_button;

    QLineEdit *take_textbox;
    QLineEdit *notes_textbox;
    QLineEdit *desc_textbox;
    QLineEdit *name_textbox;
    QLineEdit *type_textbox;
    QLineEdit *status_textbox;

    QGridLayout *down_left_widgets_layout;
    QVBoxLayout *down_mid_widgets_layout;
    QVBoxLayout *down_right_widgets_layout;

    QHBoxLayout *prev_play_next_layout;
    QHBoxLayout *down_widgets_layout;
    QHBoxLayout *up_buttons_layout;
    QVBoxLayout *vbox_layout;
    QHBoxLayout *hbox_layout;
    QHBoxLayout *devices_layout;
    QHBoxLayout *add_remove_layout;


public slots:



};

#endif // MAINWINDOW_H
