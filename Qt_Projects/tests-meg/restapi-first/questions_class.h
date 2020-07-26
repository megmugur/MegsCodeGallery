#ifndef QUESTIONS_CLASS_H
#define QUESTIONS_CLASS_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>


class questions_class : public QDialog
{
    Q_OBJECT  //without this, the button handler methods wont work.
public:
    questions_class();

    QLabel *q1_label;

    QPushButton *o1_button;
    QPushButton *o2_button;
    QPushButton *o3_button;
    QPushButton *o4_button;

    QVBoxLayout *outer_layout;
    QHBoxLayout *inner_layout_top;
    QGridLayout *inner_layout_bottom;
    QWidget *top_widget;
    QWidget *bottom_widget;
    QDialog *ques_dialog;

    QLabel *a1_label;
    QLabel *a2_label;
    QLabel *a3_label;
    QLabel *a4_label;
    QLabel *a5_label;
    QString chosen_answer;


public slots:
    void o1_buttonHandler();
    void o2_buttonHandler();
    void o3_buttonHandler();
    void o4_buttonHandler();

};

#endif // QUESTION1_CLASS_H
