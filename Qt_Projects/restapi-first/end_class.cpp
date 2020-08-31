#include "end_class.h"

#include <QLabel>
#include <QGridLayout>

end_class::end_class()
{
    result_label = new QLabel("Congratulations! Quiz completed.");
    result_label->setAlignment(Qt::AlignCenter);
    result_layout = new QHBoxLayout();
    end_dialog = new QDialog();
    end_dialog->resize(500,200);

    result_layout->addWidget(result_label);
    end_dialog->setLayout(result_layout);
    end_dialog->setWindowTitle("Complete");

}
