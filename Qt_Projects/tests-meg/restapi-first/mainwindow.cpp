#include "mainwindow.h"
#include "questions_class.h"
#include "end_class.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QFont>
#include <QtGui>
#include <QFrame>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QList>
#include <QMap>


#include <QtNetwork/QNetworkAccessManager>
//#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    manager = new QNetworkAccessManager();
    request = new QNetworkRequest();

    my_layout = new QVBoxLayout();
    my_widget = new QWidget();

    welcome_msg_label = new QLabel("Welcome to Geography Trivia.\n\nYou will be asked 10 questions.");
    welcome_msg_label->setAlignment(Qt::AlignCenter);
    enter_quiz_button = new QPushButton("Enter");

    my_layout->addWidget(welcome_msg_label);
    my_layout->addWidget(enter_quiz_button);

    my_widget->setLayout(my_layout);
    this->setCentralWidget(my_widget); //need this to display the widgets in MainWindow. w/o this, empty window shows up.
    this->setWindowTitle("Geography Trivia");
    this->setMinimumWidth(400);
    connect(enter_quiz_button, SIGNAL (pressed()), this, SLOT (enter_buttonHandler()));
}


void MainWindow::enter_buttonHandler()
{


    request->setUrl(QUrl("https://opentdb.com/api.php?amount=10&category=22&difficulty=medium&type=multiple"));
    manager->get(*request);
    //q1_obj.ques_dialog->exec();


    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(managerFinished(QNetworkReply*)));


}

void MainWindow::managerFinished(QNetworkReply *reply)
{

    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8()); // Ask Al how to do this without converting to utf8
    if (doc.isObject()){
        //qDebug() << " It is an Object" <<endl;
    }


    QJsonObject obj  = doc.object();
    QJsonObject::iterator iter;
    for(iter=obj.begin();iter!=obj.end();iter++)
    {
        if(iter.value().isObject())
        {
              //qDebug() << "found an object. Ignored.";

        }

        else
        {
            //qDebug() <<"Found a non object. Is it an array?";
            if (iter.value().isArray())
            {
                QJsonArray arr = iter.value().toArray();
                QJsonArray::iterator iter2;
                int ques_number = 0;

                for(iter2=arr.begin();iter2!=arr.end();iter2++)
                {
                    each_ques(iter2, ques_number); //iter2 is an individual question data modeule
                    ques_number++;
                }

            }
        }
    }
    final_message();
}


void MainWindow::each_ques(QJsonArray::iterator iter2, int ques_num)
{
    QString ques;
    QString cor_ans;
    QString inc_ans_1;
    QString inc_ans_2;
    QString inc_ans_3;
    QString result;

    if(iter2->isObject())
    {
        QJsonObject each_unit = iter2->toObject();
        // iterate through each question. It will have the keys: type, category, difficulty, question, correct_answer and incorrect_answers.
        QJsonObject::iterator iter3;
        for (iter3 = each_unit.begin(); iter3 != each_unit.end(); iter3++)
        {
          if (iter3.key() == "question")
          {
              ques = iter3.value().toString();
              qDebug() << "Question" << " : " << ques << endl;
          }
        }
        for (iter3 = each_unit.begin(); iter3 != each_unit.end(); iter3++)
        {
          if (iter3.key() == "correct_answer")
          {
              cor_ans = iter3.value().toString();
              qDebug() << "Correct answer" << " : " << cor_ans << endl;
          }
        }
        for (iter3 = each_unit.begin(); iter3 != each_unit.end(); iter3++)
        {
          if (iter3.key() == "incorrect_answers")
          {
              inc_ans_1 = iter3.value().toArray()[0].toString();
              inc_ans_2 = iter3.value().toArray()[1].toString();
              inc_ans_3 = iter3.value().toArray()[2].toString();
              qDebug() << "Incorrect answer 1" << " : " << inc_ans_1 << endl;
              qDebug() << "Incorrect answer 2" << " : " << inc_ans_2 << endl;
              qDebug() << "Incorrect answer 3" << " : " << inc_ans_3 << endl;
          }
        }
        result = create_question_popup(ques, cor_ans, inc_ans_1, inc_ans_2, inc_ans_3, ques_num);
        qDebug() << "result: " << result;
        if (result == "pass")
        {
            return;
        }
        else
        {
            each_ques(iter2, ques_num);
        }
    }
}

QString MainWindow::create_question_popup(QString ques, QString cor_ans, QString inc_ans_1, QString inc_ans_2, QString inc_ans_3, int ques_numb)
{
    QString result = "";
    questions_class q1_obj;

    q1_obj.q1_label->setText(ques);
    q1_obj.o1_button->setText(cor_ans);
    q1_obj.o2_button->setText(inc_ans_1);
    q1_obj.o3_button->setText(inc_ans_2);
    q1_obj.o4_button->setText(inc_ans_3);
    QString win_title = "Question " + QString::number(ques_numb+1);
    q1_obj.ques_dialog->setWindowTitle(win_title);
    q1_obj.ques_dialog->exec();
    if (q1_obj.chosen_answer == cor_ans)
    {
        result = "pass";
    }
    else
    {
        result = "fail";
    }


    return result;
}
void MainWindow::final_message()
{
    end_class end_obj;
    end_obj.end_dialog->exec();
}


