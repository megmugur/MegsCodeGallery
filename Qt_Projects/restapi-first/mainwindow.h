#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
//#include "onepagequiz_mainwindow.h"
//#include "questionswindow_class.h"


#include <QVBoxLayout>

#include <QLabel>
#include <QDialog>
#include <QFont>
#include <QtGui>
#include <QFrame>

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);


    QLabel *my_label;
    QLabel *welcome_msg_label;
    QPushButton *my_button;
    QPushButton *enter_quiz_button;
    QWidget *my_widget;


    QVBoxLayout *my_layout;
    QNetworkAccessManager *manager;
    QNetworkRequest *request;

public slots:
    void each_ques(QJsonArray::iterator iter2, int);
    QString create_question_popup(QString ques, QString cor_ans, QString inc_ans_1, QString inc_ans_2, QString inc_ans_3, int);
    void enter_buttonHandler();
    void managerFinished(QNetworkReply *reply);
    void final_message();

};
#endif // MAINWINDOW_H
