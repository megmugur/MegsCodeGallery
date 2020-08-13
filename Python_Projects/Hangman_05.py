import sys
from PySide2 import QtWidgets
from PySide2 import QtGui
from PySide2 import QtCore

class InviteDialog(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(InviteDialog, self).__init__(parent)
        self.setWindowTitle("Hangman Beta © Meg Mugur 2020")
        self.gameStackWidget = QtWidgets.QStackedWidget()
        self.gameStackLayout = QtWidgets.QVBoxLayout()

        self.welcomeWidget = QtWidgets.QWidget()
        self.q1Widget = QtWidgets.QWidget()
        # self.q2Widget = QtWidgets.QWidget()
        # self.q3Widget = QtWidgets.QWidget()
        # self.q4Widget = QtWidgets.QWidget()
        # self.q5Widget = QtWidgets.QWidget()
        self.resultWidget = QtWidgets.QWidget()
        self.addWidgetsToStack()

        # Welcome page:
        self.welcomeLayout = QtWidgets.QVBoxLayout()
        self.welcomeLabel = QtWidgets.QLabel("Welcome to Hangman! Are you ready?")
        self.entrButton = QtWidgets.QPushButton("Enter")
        self.entrButton.pressed.connect(self.q1Page)
        self.welcomePage()
        self.questionsList = ["Avatar", "The Blind Side", "Princess Mononoke", "The Pursuit of Happiness", "Kung Fu Kanda"]

        # Question 1 page:
        self.q1Layout = QtWidgets.QHBoxLayout()
        self.leftLayout = QtWidgets.QVBoxLayout()
        self.rightLayout = QtWidgets.QVBoxLayout()
        self.leftWidget = QtWidgets.QWidget()
        self.rightWidget = QtWidgets.QWidget()

        self.q1Label = QtWidgets.QLabel("Guess the movie:")
        self.imgWidget = QtWidgets.QWidget()
        self.imgLayout = QtWidgets.QHBoxLayout()
        self.imgLabel = QtWidgets.QLabel()
        self.q1BoxesWidget = QtWidgets.QWidget()
        self.q1BoxesLayout = QtWidgets.QHBoxLayout()

        # Question 1 page, textboxes area:
        self.ansTxtList = []
        for t in range(0, 25):                                                  # TODO: Hardcoded a limit to number of characters. Try to avoid.
            ts = str(t)
            exec("self.ans%sTxt = QtWidgets.QLineEdit()" % ts)                    # execute list of commands of type: [     self.ans1Txt = QtWidgets.QLineEdit()    ]
            exec("self.ansTxtList.append(self.ans%sTxt)" % ts)                    # create "ansTxtList", a list of textboxes for movie name letters.
        self.correctGuessCount = 0

        # Question 1 page, alphabets button area:
        self.alphList = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                         "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]                     # TODO: include numbers and special characters
        self.alphBtnList = []
        for index, b in enumerate(self.alphList):
            exec("self.alph%sBtn = QtWidgets.QPushButton('%s')" % (b, b))          # execute list of commands of type: [    self.alphA = QtWidgets.QPushButton("A")    ]
            exec("self.alphBtnList.append(self.alph%sBtn)" % b)                    # create "alphBtnList", a list of buttons for A-Z.
            self.alphBtnList[index].clicked.connect(self.alphClick)

        self.alphWidget = QtWidgets.QWidget()
        self.alphLayout = QtWidgets.QHBoxLayout()
        self.indexOfClickedBtn = int()

        # Question 1 page, health widget area:
        self.healthBar1 = QtWidgets.QLabel()
        self.healthBar2 = QtWidgets.QLabel()
        self.healthBar3 = QtWidgets.QLabel()
        self.healthBar4 = QtWidgets.QLabel()
        self.healthBar5 = QtWidgets.QLabel()
        self.healthBar6 = QtWidgets.QLabel()
        self.healthBar7 = QtWidgets.QLabel()
        self.healthBar8 = QtWidgets.QLabel()
        self.healthBar9 = QtWidgets.QLabel()
        self.healthBar10 = QtWidgets.QLabel()
        self.healthBar11 = QtWidgets.QLabel()
        self.healthBar12 = QtWidgets.QLabel()
        self.healthBarsList = [self.healthBar1,
                               self.healthBar2,
                               self.healthBar3,
                               self.healthBar4,
                               self.healthBar5,
                               self.healthBar6,
                               self.healthBar7,
                               self.healthBar8,
                               self.healthBar9,
                               self.healthBar10,
                               self.healthBar11,
                               self.healthBar12]
        self.colorList = ["greenyellow", "greenyellow", "#adf802", "#fcc006", "#fec615", "#f5bf03", "#fe02a2",
                          "#fe019a", "#ff0784", "#fa4224", "#f4320c", "#fe0002"]
        self.healthLoss = 0

        # Result Page:
        self.resultLayout = QtWidgets.QVBoxLayout()
        self.resultLabel = QtWidgets.QLabel()
        self.result = ""

        # Stack:
        self.gameStackWidget.setLayout(self.gameStackLayout)
        self.setLayout(self.gameStackLayout)
        self.gameStackLayout.addWidget(self.gameStackWidget)
        self.resize(600, 300)

    def addWidgetsToStack(self):
        self.gameStackWidget.addWidget(self.welcomeWidget)
        self.gameStackWidget.addWidget(self.q1Widget)
        self.gameStackWidget.addWidget(self.resultWidget)
        # self.gameStackWidget.addWidget(self.q2Widget)
        # self.gameStackWidget.addWidget(self.q3Widget)
        # self.gameStackWidget.addWidget(self.q4Widget)
        # self.gameStackWidget.addWidget(self.q5Widget)

    def welcomePage(self):
        self.entrButton.setMaximumWidth(200)
        self.welcomeLayout.addWidget(self.welcomeLabel)
        self.welcomeLayout.addWidget(self.entrButton)
        self.welcomeLayout.setAlignment(QtCore.Qt.AlignCenter)
        self.welcomeWidget.setLayout(self.welcomeLayout)
        self.gameStackWidget.setCurrentWidget(self.welcomeWidget)

    def q1Page(self):                                                    # q1Widget - includes q1Label, imgLabel, q1BoxesWidget and alphWidget
        self.gameStackWidget.setCurrentWidget(self.q1Widget)
        self.q1Widget.setLayout(self.q1Layout)
        self.q1Layout.addWidget(self.leftWidget)
        self.q1Layout.addWidget(self.rightWidget)
        self.leftWidget.setLayout(self.leftLayout)
        self.rightWidget.setLayout(self.rightLayout)
        self.leftLayout.addWidget(self.q1Label)                           # q1Label

        self.leftLayout.addWidget(self.imgWidget)                          # imgLabel
        self.imgWidget.setLayout(self.imgLayout)
        self.imgLayout.addWidget(self.imgLabel)
        self.imgLayout.setAlignment(QtCore.Qt.AlignCenter)

        self.imgLabel.setPixmap("Avatar.jpg")
        self.imgLabel.setMaximumWidth(300)
        self.imgLabel.setMaximumHeight(300)
        self.imgLabel.setAlignment(QtCore.Qt.AlignCenter)

        self.q1Label.setAlignment(QtCore.Qt.AlignCenter)
        self.leftLayout.addWidget(self.q1BoxesWidget)
        self.leftLayout.addWidget(self.alphWidget)
        for j, h in enumerate(self.healthBarsList):
            self.rightLayout.addWidget(h)
            h.setFixedWidth(50)
            h.setStyleSheet("background-color: " + self.colorList[j])
        self.imgLabel.setAlignment(QtCore.Qt.AlignRight)
        self.q1BoxesLayout.setAlignment(QtCore.Qt.AlignCenter)
        self.addAnsTextBoxesMethod()
        self.addAlphabetWidgetMethod()

    def resultPage(self):
        print(self.result)
        self.resultLabel.setText(self.result)
        self.resultLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.resultLayout.addWidget(self.resultLabel)
        self.resultWidget.setLayout(self.resultLayout)
        self.gameStackWidget.setCurrentWidget(self.resultWidget)

    def addAnsTextBoxesMethod(self):
        self.q1BoxesWidget.setLayout(self.q1BoxesLayout)                # q1BoxesWidget
        self.q1BoxesLayout.setAlignment(QtCore.Qt.AlignCenter)
        for b in range(len(self.questionsList[0])):
            self.q1BoxesLayout.addWidget(self.ansTxtList[b])
            self.ansTxtList[b].setMaxLength(1)
            self.ansTxtList[b].setMaximumWidth(20)
            self.ansTxtList[b].setAlignment(QtCore.Qt.AlignCenter)
            self.ansTxtList[b].setStyleSheet("border: 1px border-color: green;")

    def addAlphabetWidgetMethod(self):
        self.alphWidget.setLayout(self.alphLayout)                      # alphWidget
        for k in range(len(self.alphBtnList)):
            self.alphBtnList[k].setMaximumWidth(20)
            self.alphLayout.addWidget(self.alphBtnList[k])
            self.alphBtnList[k].setFocusPolicy(QtCore.Qt.NoFocus)

    def alphClick(self):
        self.indexOfClickedBtn = self.alphBtnList.index(self.sender())
        print("clicked: ", self.alphList[self.indexOfClickedBtn])
        self.alphBtnList[self.indexOfClickedBtn].setStyleSheet("text-decoration: line-through")
        self.alphBtnList[self.indexOfClickedBtn].setEnabled(False)
        if self.alphList[self.indexOfClickedBtn].upper() in self.questionsList[0].upper():            # check if clicked char exists in the movie name
            for pos, char in enumerate(self.questionsList[0]):                                        # for every char in the question, check if equal to the clicked char
                if self.alphList[self.indexOfClickedBtn].upper() == char.upper():
                    self.ansTxtList[pos].setText(self.alphList[self.indexOfClickedBtn].upper())
                    self.correctGuessCount += 1
                    if self.correctGuessCount == len(self.questionsList[0]):
                        self.result = "Good stuff!"
                        print("Success!")
                        self.resultPage()
        elif self.healthLoss < 12:                                                                    # else reduce health
            self.healthBarsList[self.healthLoss].setStyleSheet("background-color : None")
            self.healthLoss += 1
        else:                                                                                         # TODO: Go to next question
            self.result = "Oi..too many wrong guesses!"
            print("Game Over!")
            self.resultPage()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    inviteDialog = InviteDialog()
    inviteDialog.exec_()

