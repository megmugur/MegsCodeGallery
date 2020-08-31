#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>

class Level1 : public QDialog
{
public:

    Level1();

    QLabel *l1_label;
    QLineEdit *l1_textbox;
    QPushButton *l1_button;
    QGridLayout *l1_layout;
    QDialog *l1_dialog;


public slots:
    void l1_buttonHandler();

};

#endif // LEVEL1_H
