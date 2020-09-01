#ifndef RESULTWINDOWCLASS_H
#define RESULTWINDOWCLASS_H

#include <QLabel>
#include <QDialog>
#include <QHBoxLayout>

class ResultWindowClass : public QDialog
{
    Q_OBJECT


public:
    ResultWindowClass();

    QLabel *result_label;
    QLayout *result_layout;

};

#endif // RESULTWINDOW_CLASS_H
