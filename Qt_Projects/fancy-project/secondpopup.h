#ifndef SECONDPOPUP_H
#define SECONDPOPUP_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
class SecondPopupClass : public QDialog
{
public:
    SecondPopupClass();
    QLabel *second_popup_label;
    QLineEdit *second_popup_textbox;
    QHBoxLayout *second_popup_layout;
    QPushButton *second_popup_button;
    QDialog *second_popup_dialog;
};


#endif // SECONDPOPUP_H
