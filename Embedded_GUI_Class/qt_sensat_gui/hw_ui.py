# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'hw.ui'
##
## Created by: Qt User Interface Compiler version 6.4.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide2.QtWidgets import (QAbstractItemView, QApplication, QGridLayout, QHeaderView,
    QMainWindow, QMenuBar, QPushButton, QSizePolicy,
    QSlider, QStatusBar, QTableWidget, QTableWidgetItem,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(323, 501)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayoutWidget = QWidget(self.centralwidget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(9, 9, 281, 391))
        self.gridLayout = QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.sliderB = QSlider(self.gridLayoutWidget)
        self.sliderB.setObjectName(u"sliderB")
        self.sliderB.setMaximum(255)
        self.sliderB.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderB, 5, 0, 1, 1)

        self.flash = QPushButton(self.gridLayoutWidget)
        self.flash.setObjectName(u"flash")

        self.gridLayout.addWidget(self.flash, 6, 0, 1, 1)

        self.sliderG = QSlider(self.gridLayoutWidget)
        self.sliderG.setObjectName(u"sliderG")
        self.sliderG.setMaximum(255)
        self.sliderG.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderG, 4, 0, 1, 1)

        self.clear = QPushButton(self.gridLayoutWidget)
        self.clear.setObjectName(u"clear")

        self.gridLayout.addWidget(self.clear, 7, 0, 1, 1)

        self.table = QTableWidget(self.gridLayoutWidget)
        if (self.table.columnCount() < 8):
            self.table.setColumnCount(8)
        if (self.table.rowCount() < 8):
            self.table.setRowCount(8)
        self.table.setObjectName(u"table")
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setSelectionMode(QAbstractItemView.SingleSelection)
        self.table.setRowCount(8)
        self.table.setColumnCount(8)
        self.table.horizontalHeader().setVisible(False)
        self.table.horizontalHeader().setDefaultSectionSize(34)
        self.table.horizontalHeader().setHighlightSections(True)
        self.table.verticalHeader().setVisible(False)

        self.gridLayout.addWidget(self.table, 1, 0, 1, 1)

        self.sliderR = QSlider(self.gridLayoutWidget)
        self.sliderR.setObjectName(u"sliderR")
        self.sliderR.setMaximum(255)
        self.sliderR.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderR, 3, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 323, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.clear.clicked.connect(MainWindow.Clear)
        self.flash.clicked.connect(MainWindow.Flash)
        self.table.cellEntered.connect(MainWindow.click)
        self.table.cellPressed.connect(MainWindow.click)
        self.sliderR.valueChanged.connect(MainWindow.rslide)
        self.sliderG.valueChanged.connect(MainWindow.gslide)
        self.sliderB.valueChanged.connect(MainWindow.bslide)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.flash.setText(QCoreApplication.translate("MainWindow", u"flash", None))
        self.clear.setText(QCoreApplication.translate("MainWindow", u"clear", None))
    # retranslateUi

