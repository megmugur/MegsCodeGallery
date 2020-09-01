#ifndef QUESTIONWIDGETCLASS_H
#define QUESTIONWIDGETCLASS_H


#include <QMainWindow>
#include <QStackedWidget>
#include "QuestionDataClass.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
//#include <QtNetwork/QNetworkAccessManager>
//#include <QtNetwork/QNetworkReply>
//#include <QJsonArray>
//#include <QJsonObject>
#include <QGridLayout>
#include <QDialog>



class QuestionWidgetClass: public QWidget
{
    Q_OBJECT
public:
    QuestionWidgetClass();

    QWidget *questionPageWidget;

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

    QString o1ButtonText = "";
    QString o2ButtonText = "";
    QString o3ButtonText = "";
    QString o4ButtonText = "";


    QString chosenAnswer = "";
    QString corAns = "";
    QString ques = "";
    QString incAns1 = "";
    QString incAns2 = "";
    QString incAns3 = "";
    int quesNum;
    bool correctFlag;

    QLabel *finalPageLabel;
    QVBoxLayout *finalPageLayout;


};

#endif // QUESTIONWIDGETCLASS_H
