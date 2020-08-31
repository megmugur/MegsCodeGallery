#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "questionclass.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include <QGridLayout>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QWidget *welcomePageWidget;
    QWidget *questionPageWidget;
    QWidget *finalPageWidget;
    QStackedWidget *stackedWidget;

    QLabel *welcomeLabel;
    QPushButton *welcomeButton;
    QPushButton *enterQuizButton;
    QWidget *welcomeWidget;
    QVBoxLayout *welcomeLayout;
    QNetworkAccessManager *connManager;
    QNetworkRequest *connRequest;
    bool connError;
    bool answeredFlag;

    QJsonObject eachQuesObj;
    QJsonObject::iterator iter3;

    QString answer;
    QJsonObject jsonObj;
    QJsonObject::iterator iter;
    QJsonArray::iterator iter2;
    QJsonArray jsonArray;


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

    QVector <QVector<QString>> allQuesList;
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


public slots:
    void enterButtonHandler();
    void networkConnMethod(QNetworkReply*);
    void eachQuestionMethod();
    void questionProcessingMethod();
    void o1ButtonHandler();
    void o2ButtonHandler();
    void o3ButtonHandler();
    void o4ButtonHandler();
    void displayMethod(bool);
    void finalMessageMethod();


};
#endif // MAINWINDOW_H
