#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "questiondataclass.h"
#include "questionwidgetclass.h"

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
    QWidget *finalPageWidget;
    QStackedWidget *stackedWidget;

    QLabel *welcomeLabel;
    QPushButton *enterQuizButton;
    QWidget *welcomeWidget;
    QVBoxLayout *welcomeLayout;
    QNetworkAccessManager *connManager;
    QNetworkRequest *connRequest;

    QJsonObject eachQuesObj;
    QJsonObject::iterator iter3;

    QString answer;
    QJsonObject jsonObj;
    QJsonObject::iterator iter;
    QJsonArray::iterator iter2;
    QJsonArray jsonArray;

    QVector <QVector<QString>> allQuesList;
    QString chosenAnswer = "";

    int quesNum;
    bool correctFlag;
    QLabel *finalPageLabel;
    QVBoxLayout *finalPageLayout;


public slots:
    void enterButtonHandler();
    void networkConnMethod(QNetworkReply*);
    void questionProcessingMethod();
    void quesDisplayMethod();
    void finalMessageMethod();
    void o1ButtonHandler();
    void o2ButtonHandler();
    void o3ButtonHandler();
    void o4ButtonHandler();
};
#endif // MAINWINDOW_H
