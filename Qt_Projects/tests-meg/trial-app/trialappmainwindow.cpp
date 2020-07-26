#include "trialappmainwindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QFont>
#include <QtGui>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
        master_widget = new QWidget();

        up_widget = new QWidget();
        down_widget = new QWidget();
        down_left_widget = new QWidget();
        down_mid_widget = new QWidget();
        down_right_widget = new QWidget();
        prev_play_widget = new QWidget();
        devices_widget = new QWidget();
        add_remove_widget = new QWidget();

        take_button = new QLabel("Take");
        notes_button = new QLabel("Notes");
        desc_button = new QLabel("Description");
        info_button = new QLabel("Info");
        select_button = new QLabel("Select");

        take_label = new QLabel("Take:");
        notes_label = new QLabel("Notes:");
        desc_label = new QLabel("Desc:");

        take_textbox = new QLineEdit();
        notes_textbox = new QLineEdit();
        desc_textbox = new QLineEdit();
        name_textbox = new QLineEdit("Name");
        type_textbox = new QLineEdit("Type");
        status_textbox = new QLineEdit("Status");

        time_label = new QLabel("00:00:00:00");
        prev_button = new QPushButton("Prev");
        play_button = new QPushButton("Play");
        next_button = new QPushButton("Next");
        record_button = new QPushButton("Record");
        plus_button = new QPushButton("+");
        minus_button = new QPushButton("-");

        vbox_layout = new QVBoxLayout();
        hbox_layout = new QHBoxLayout();
        up_buttons_layout = new QHBoxLayout();
        down_widgets_layout = new QHBoxLayout();
        down_left_widgets_layout = new QGridLayout();
        down_mid_widgets_layout = new QVBoxLayout();
        down_right_widgets_layout = new QVBoxLayout();
        prev_play_next_layout = new QHBoxLayout();
        devices_layout = new QHBoxLayout();
        add_remove_layout = new QHBoxLayout();

        vbox_layout->addWidget(up_widget);
        vbox_layout->setAlignment(up_widget, Qt::AlignTop);
        vbox_layout->addWidget(down_widget);

        master_widget->setLayout(vbox_layout);
        this->setCentralWidget(master_widget);
        master_widget->setMaximumWidth(550);

        up_widget->setLayout(up_buttons_layout);
        up_buttons_layout->addWidget(take_button);
        up_buttons_layout->addWidget(notes_button);
        up_buttons_layout->addWidget(desc_button);
        up_buttons_layout->addWidget(info_button);
        up_buttons_layout->addWidget(select_button);

        up_widget->setMinimumHeight(250);

        down_widget->setLayout(down_widgets_layout);
        down_widgets_layout->addWidget(down_left_widget);
        down_widgets_layout->addWidget(down_mid_widget);
        down_widgets_layout->addWidget(down_right_widget);

        down_left_widget->setLayout(down_left_widgets_layout);
        down_left_widgets_layout->addWidget(take_label, 0,0);
        down_left_widgets_layout->addWidget(notes_label, 1,0);
        down_left_widgets_layout->addWidget(desc_label,2,0);
        down_left_widgets_layout->addWidget(take_textbox, 0,1);
        down_left_widgets_layout->addWidget(notes_textbox, 1,1);
        down_left_widgets_layout->addWidget(desc_textbox,2,1);


        down_mid_widget->setLayout(down_mid_widgets_layout);
        down_mid_widgets_layout->addWidget(time_label);
        down_mid_widgets_layout->addWidget(prev_play_widget);
        down_mid_widgets_layout->addWidget(record_button);
        time_label->setAlignment(Qt::AlignCenter);


        prev_play_widget->setLayout(prev_play_next_layout);
        prev_play_next_layout->addWidget(prev_button);
        prev_play_next_layout->addWidget(play_button);
        prev_play_next_layout->addWidget(next_button);

        down_right_widget->setLayout(down_right_widgets_layout);
        down_right_widgets_layout->addWidget(devices_widget);
        down_right_widgets_layout->addWidget(add_remove_widget);

        devices_widget->setLayout(devices_layout);
        devices_layout->addWidget(name_textbox);
        devices_layout->addWidget(type_textbox);
        devices_layout->addWidget(status_textbox);

        add_remove_widget->setLayout(add_remove_layout);
        add_remove_layout->addWidget(plus_button);
        add_remove_layout->addWidget(minus_button);

}
