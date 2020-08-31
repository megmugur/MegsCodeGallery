#ifndef QUESTIONCLASS_H
#define QUESTIONCLASS_H
#include "MainWindow.h"

#include <QDialog>
#include <QMainWindow>
#include <QStackedWidget>

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QJsonObject>
#include <QGridLayout>


class QuestionClass: public QDialog
{
    Q_OBJECT
public:
    QuestionClass();

    QLabel *qLabel;
    QLabel *wrongLabel;
    QPushButton *o1Button;
    QPushButton *o2Button;
    QPushButton *o3Button;
    QPushButton *o4Button;
    QVBoxLayout *outerLayout;
    QHBoxLayout *innerLayoutTop;
    QGridLayout *innerLayoutMid;
    QVBoxLayout *innerLayoutBottom;
    QWidget *topWidget;
    QWidget *midWidget;
    QWidget *bottomWidget;
    QWidget *quesWidget;
    QWidget *currentQuesWidget;

    QString o1ButtonText = "";
    QString o2ButtonText = "";
    QString o3ButtonText = "";
    QString o4ButtonText = "";

    QString ques = "";
    QString corAns = "";
    QString incAns1 = "";
    QString incAns2 = "";
    QString incAns3 = "";
    QString result = "";
    QString chosenAnswer="";
    int randCol;
    int randRow;

public slots:

};

#endif // QUESTIONCLASS_H
