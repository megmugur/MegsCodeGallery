#include "ResultWindowClass.h"

#include <QLabel>
#include <QGridLayout>

/*
 * Sets the result label to display a success message, adds it to a new layout,
 * and sets that as the current layout.
 */
ResultWindowClass::ResultWindowClass()
{
    result_label = new QLabel("success!");
    result_layout = new QHBoxLayout();

    result_layout->addWidget(result_label);
    this->setLayout(result_layout);

}
