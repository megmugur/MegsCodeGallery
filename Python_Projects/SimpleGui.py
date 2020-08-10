import sys
from PySide2 import QtWidgets


class MyDialog(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(MyDialog, self).__init__(parent)
        layout = QtWidgets.QHBoxLayout()
        self.label = QtWidgets.QLabel("Hello")
        self.my_button = QtWidgets.QPushButton("Submit")
        self.my_button.pressed.connect(self.button_state)
        layout.addWidget(self.my_button)
        layout.addWidget(self.label)
        self.setLayout(layout)
        self.resize(400, 400)

    def button_state(self):
        print("hello")


def show_dialog():
    app = QtWidgets.QApplication(sys.argv)
    d = MyDialog()
    print(d.button_state())
    d.exec_()


if __name__ == "__main__":
    show_dialog()