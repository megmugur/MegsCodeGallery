#ifndef QUESTIONDATACLASS_H
#define QUESTIONDATACLASS_H

#include <QMainWindow>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>

class QuestionDataClass : QObject
{
    Q_OBJECT
public:
    QuestionDataClass();

    QJsonObject eachQuesObj;
    QJsonObject::iterator iter3;

    QString answer;
    QJsonObject jsonObj;
    QJsonObject::iterator iter;
    QJsonArray::iterator iter2;
    QJsonArray jsonArray;
    QVector <QVector<QString>> allQuesList;

    QString corAns = "";
    QString ques = "";
    QString incAns1 = "";
    QString incAns2 = "";
    QString incAns3 = "";

public slots:
    void eachQuestionMethod();
    void dataProcessingMethod();
};

#endif // QUESTIONCLASS_H
