from PySide2.QtWidgets import *
from hw_ui import Ui_MainWindow

from sense_emu import SenseHat
from time import sleep


class myApp(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()
        self.r = 0
        self.g = 0
        self.b = 0

    def main(self):
        self.sense = SenseHat()

    def Flash(self):
        for y in range(8):
            for x in range(8):
                self.sense.set_pixel(x, y, self.r,self.g,self.b)
                
    def Clear(self):
        self.sense.clear()

    def click(self, x, y):
        self.sense.set_pixel(x, y, self.r, self.g, self.b)

    def rslide(self, val):
        self.r = val

    def gslide(self, val):
        self.r = val

    def bslide(self, val):
        self.b = val


app = QApplication()
win = myApp()
win.show()
app.exec_()