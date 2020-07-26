#ifndef LEVEL3_H
#define LEVEL3_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

class Level3 : public QDialog
{
public:
    Level3();


    QLabel *l3_label;
    QLineEdit *l3_textbox;
    QPushButton *l3_button;
    QHBoxLayout *l3_layout;
    QDialog *l3_dialog;


};

#endif // LEVEL3_H
