#include "QuestionWidgetClass.h"

#include <QRandomGenerator>
#include <QLabel>
#include <QRandomGenerator>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>


/**
 * This Class handles all the front-end UI for the questions page.
 * It creates the necessary UI elements.
 * We don't want the correct answer button's position to be the same for each question,
 * so we use a randon generator for it.
 */
QuestionWidgetClass::QuestionWidgetClass()
{
    questionPageWidget = new QWidget();
    topWidget = new QWidget();
    midWidget = new QWidget();
    bottomWidget = new QWidget();
    outerLayout = new QVBoxLayout();
    innerLayoutTop = new QHBoxLayout();
    innerLayoutMid = new QGridLayout();
    innerLayoutBottom = new QVBoxLayout();
    qLabel = new QLabel("");
    o1Button = new QPushButton("a");
    o2Button = new QPushButton("a");
    o3Button = new QPushButton("a");
    o4Button = new QPushButton("a");
    wrongLabel = new QLabel("");
    chosenAnswer = "";
    quesNum = 0;


    int randCol = QRandomGenerator::global()->bounded(2);
    int randRow = QRandomGenerator::global()->bounded(2);

    innerLayoutTop->addWidget(qLabel);
    innerLayoutMid->addWidget(o1Button, randCol,randRow);
    innerLayoutMid->addWidget(o2Button, randCol,1-randRow);
    innerLayoutMid->addWidget(o3Button, 1-randCol,randRow);
    innerLayoutMid->addWidget(o4Button, 1-randCol,1-randRow);
    innerLayoutBottom->addWidget(wrongLabel);
    topWidget->setLayout(innerLayoutTop);
    midWidget->setLayout(innerLayoutMid);
    bottomWidget->setLayout(innerLayoutBottom);
    outerLayout->addWidget(topWidget);
    outerLayout->addWidget(midWidget);
    outerLayout->addWidget(bottomWidget);
    questionPageWidget->setLayout(outerLayout);

}
