#include "secondpopup.h"
#include <QDialog>
#include <QLineEdit>
SecondPopupClass::SecondPopupClass()
{
    second_popup_label = new QLabel("some default text");
    second_popup_textbox = new QLineEdit();
    second_popup_button = new QPushButton ("SUbmit");
    second_popup_layout = new QHBoxLayout();

    //second_popup_dialog = new QDialog();

    second_popup_layout->addWidget(second_popup_textbox);
    second_popup_layout->addWidget(second_popup_label);
    second_popup_layout->addWidget(second_popup_button);

    this->setLayout(second_popup_layout);

}
