import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLineEdit, QVBoxLayout, QFormLayout


class MainWindow(QWidget):

    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi()
        self.show()

    def setupUi(self):
        self.setWindowTitle("信號的使用!")

        self.button_hello = QPushButton()
        self.button_hello.setText("hello")

        self.button_cancel = QPushButton()
        self.button_cancel.setText("cancel")

        self.line_hello = QLineEdit()

        form_layout = QFormLayout()
        form_layout.addRow(self.button_hello, self.line_hello)
        form_layout.addRow(self.button_cancel)

        h_layout = QVBoxLayout()
        h_layout.addLayout(form_layout)

        self.setLayout(h_layout)

        self.button_hello.clicked.connect(self.hello)
        self.button_cancel.clicked.connect(self.cancel)

    def hello(self):
        self.line_hello.setText("hello 我被觸發了")

    def cancel(self):
        self.line_hello.setText("")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    MainWindow = MainWindow()
    sys.exit(app.exec_())
