#include "popupclass.h"
#include <QDialog>
#include <QLineEdit>
#include "secondpopup.h"

PopupClass::PopupClass()
{
    popup_label = new QLabel();
    popup_textbox = new QLineEdit();
    popup_button = new QPushButton("Submit");
    popup_layout = new QHBoxLayout();
    //popup_dialog = new QDialog();

    popup_layout->addWidget(popup_label);
    popup_layout->addWidget(popup_textbox);
    popup_layout->addWidget(popup_button);
    this->setLayout(popup_layout);

    connect(popup_button, SIGNAL (pressed()), this , SLOT (popup_buttonHandler()));


}

void PopupClass::popup_buttonHandler()
{
    SecondPopupClass sec_obj;
    sec_obj.second_popup_label->setText("Olympia is the correct answer!");

    sec_obj.exec();
}
