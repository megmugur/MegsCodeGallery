#include "resultwindow_class.h"

#include <QLabel>
#include <QGridLayout>

ResultWindow_Class::ResultWindow_Class()
{
    result_label = new QLabel("success!");
    result_layout = new QHBoxLayout();

    result_layout->addWidget(result_label);
    this->setLayout(result_layout);

}
