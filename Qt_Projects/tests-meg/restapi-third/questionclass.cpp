#include "questionclass.h"
#include "mainwindow.h"
#include <QList>
#include <QRandomGenerator>

QuestionClass::QuestionClass()
{
    result = "";
    randCol = 0;
    randRow = 0;

    currentQuesWidget = new QWidget();
    topWidget = new QWidget();
    midWidget = new QWidget();
    bottomWidget = new QWidget();

    innerLayoutTop = new QHBoxLayout();
    innerLayoutMid = new QGridLayout();
    innerLayoutBottom = new QVBoxLayout();
    outerLayout = new QVBoxLayout();

    qLabel = new QLabel("What is blah blah blah?");
    o1Button = new QPushButton("option 1");
    o2Button = new QPushButton("option 2");
    o3Button = new QPushButton("option 3");
    o4Button = new QPushButton("option 4");
    wrongLabel = new QLabel("");

    topWidget->setLayout(innerLayoutTop);
    midWidget->setLayout(innerLayoutMid);
    bottomWidget->setLayout(innerLayoutBottom);

    outerLayout->addWidget(topWidget);
    outerLayout->addWidget(midWidget);
    outerLayout->addWidget(bottomWidget);

    randCol = QRandomGenerator::global()->bounded(2);
    randRow = QRandomGenerator::global()->bounded(2);

    innerLayoutTop->addWidget(qLabel);
    innerLayoutMid->addWidget(o1Button, randCol,randRow);
    innerLayoutMid->addWidget(o2Button, randCol,1-randRow);
    innerLayoutMid->addWidget(o3Button, 1-randCol,randRow);
    innerLayoutMid->addWidget(o4Button, 1-randCol,1-randRow);
    innerLayoutBottom->addWidget(wrongLabel);
    innerLayoutBottom->setAlignment(Qt::AlignCenter);

    o1ButtonText = o1Button->text();
    o2ButtonText = o2Button->text();
    o3ButtonText = o3Button->text();
    o4ButtonText = o4Button->text();

    currentQuesWidget->setLayout(outerLayout);
}
