#ifndef END_CLASS_H
#define END_CLASS_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>


class end_class : public QDialog
{
    Q_OBJECT  //without this, the button handler methods wont work.
public:
   end_class();

    QLabel *result_label;

    QHBoxLayout *result_layout;
    QGridLayout *inner_layout_bottom;

    QDialog *end_dialog;


};

#endif // END_CLASS_H
