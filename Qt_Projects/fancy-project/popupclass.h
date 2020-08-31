#ifndef POPUPCLASS_H
#define POPUPCLASS_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include<QPushButton>

class PopupClass : public QDialog
{
public:
    PopupClass();

    QLabel *popup_label;
    QLineEdit *popup_textbox;
    QPushButton *popup_button;
    QHBoxLayout *popup_layout;
    QDialog *popup_dialog;
public slots:
    void popup_buttonHandler();

};

#endif // POPUPCLASS_H
