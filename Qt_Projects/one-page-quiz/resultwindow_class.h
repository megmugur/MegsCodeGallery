#ifndef RESULTWINDOW_CLASS_H
#define RESULTWINDOW_CLASS_H

#include <QLabel>
#include <QDialog>
#include <QHBoxLayout>

class ResultWindow_Class : public QDialog
{
    Q_OBJECT


public:
    ResultWindow_Class();

    QLabel *result_label;
    QLayout *result_layout;

};

#endif // RESULTWINDOW_CLASS_H
