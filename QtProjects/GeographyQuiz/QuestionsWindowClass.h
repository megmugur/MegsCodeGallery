#ifndef QUESTIONSWINDOWCLASS_H
#define QUESTIONSWINDOWCLASS_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>


class QuestionsWindowClass: public QDialog
{
    Q_OBJECT
public:
    QuestionsWindowClass();

    QLabel *q1_label;
    QLabel *q2_label;
    QLabel *q3_label;
    QLabel *q4_label;
    QLabel *q5_label;

    QLineEdit *q1_textbox;
    QLineEdit *q2_textbox;
    QLineEdit *q3_textbox;
    QLineEdit *q4_textbox;
    QLineEdit *q5_textbox;

    QPushButton *submit_button;
    QGridLayout *ques_layout;
    QDialog *ques_dialog;

    QLabel *a1_label;
    QLabel *a2_label;
    QLabel *a3_label;
    QLabel *a4_label;
    QLabel *a5_label;



public slots:
    void submit_buttonHandler();


};



#endif // QUESTIONSWINDOW_CLASS_H
