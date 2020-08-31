#ifndef LEVEL2_H
#define LEVEL2_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class Level2 : public QDialog
{
public:
    Level2();

    QLabel *l2_label;
    QLineEdit *l2_textbox;
    QPushButton *l2_button;
    QGridLayout *l2_layout;
    QDialog *l2_dialog;

public slots:
    void l2_buttonHandler();

};

#endif // LEVEL2_H
