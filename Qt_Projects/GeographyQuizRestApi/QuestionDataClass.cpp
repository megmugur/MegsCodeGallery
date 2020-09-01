#include "QuestionDataClass.h"
#include "MainWindow.h"

#include <QList>
#include <QRandomGenerator>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

/**
 * This Class handles all the back-end data processing for the questions page.
 */
QuestionDataClass::QuestionDataClass()
{
    QVector <QVector<QString>> allQuesList;
}


/**
 * Goes through the incoming data stream, separates the questions,
 * and for each question, calls the method that processes it.
 */
void QuestionDataClass::dataProcessingMethod()
{
    for(iter=jsonObj.begin();iter!=jsonObj.end();iter++)
    {
        if (iter.value().isArray())
        {
            jsonArray = iter.value().toArray();
            for(iter2 = jsonArray.begin(); iter2 != jsonArray.end(); iter2++)
            {
                eachQuestionMethod();
            }
        }
    }
}

/**
 * From the incoming json data objects, for each object, separates out the components : question, correct answers, 3 wrong answers.
 * Loads the components into a QVector array. So each question's data is a contained an individual array.
 */
void QuestionDataClass::eachQuestionMethod()
{
    if(!  (iter2->isObject())) return;
    eachQuesObj = iter2->toObject();

    QVector <QString> eachQuesData;
    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "question") ques = iter3.value().toString();
    }
    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "correct_answer")corAns = iter3.value().toString();
    }
    for (iter3 = eachQuesObj.begin(); iter3 != eachQuesObj.end(); iter3++)
    {
      if (iter3.key() == "incorrect_answers")
      {
          incAns1 = iter3.value().toArray()[0].toString();
          incAns2 = iter3.value().toArray()[1].toString();
          incAns3 = iter3.value().toArray()[2].toString();
      }
    }
    eachQuesData.append(ques);
    eachQuesData.append(corAns);
    eachQuesData.append(incAns1);
    eachQuesData.append(incAns2);
    eachQuesData.append(incAns3);

    allQuesList.append(eachQuesData);
}
