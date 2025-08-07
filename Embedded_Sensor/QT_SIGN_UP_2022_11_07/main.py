from PySide6.QtGui import *
from PySide6.QtWidgets import *


app = QApplication()
win = QMainWindow()

strname = []

def Findcheck():

    ch = False

    if len(line1.text()) > 10 or len(line1.text()) <= 0:
        bar.showMessage("길이를 준수하세요")
        return

    for s in strname:
        if s == line1.text():
            bar.showMessage("이미 있는 친구입니다")
            ch = True

    if ch == False:
        strname.append(line1.text())


def Deletcheck():

    if len(line1.text()) <= 0:
        bar.showMessage("이름을 입력하세요")

    ch = False
    ss = ""
    for s in strname:
        if s == line1.text():
            strname.remove(s)
            ch = True
            ss = s

    if ch == False:
        bar.showMessage("없는 인맥입니다.")
    else:
        ss = ss + "더 이상 내 친구가 아닙니다."
        bar.showMessage(ss)

def exit():
    win.close()
    app.quit()
    bar.showMessage("더 이상 내 친구가 아닙니다.")

win.setWindowTitle("My Friends")
main = QWidget()
win.setCentralWidget(main)
bar = win.statusBar()
menu = win.menuBar()
menuFile = menu.addMenu("메뉴")
menuexit = menu.addMenu("종료")

add = QAction("추가", win)
delet = QAction("제거", win)
exit2 = QAction("종료", win)
menuFile.addAction(add)
menuFile.addAction(delet)
menuexit.addAction(exit2)

form = QFormLayout()
hlay = QHBoxLayout()

line1 = QLineEdit()
lbl = QLabel('인맥를 관리합시다.')
btn1 = QPushButton("추가")
btn2 = QPushButton("제거")
form.addRow(lbl)
form.addRow("name", line1)
hlay.addWidget(btn1)
hlay.addWidget(btn2)
form.addRow(hlay)
main.setLayout(form)

btn1.clicked.connect(Findcheck)
btn2.clicked.connect(Deletcheck)

exit2.triggered.connect(exit)

win.show()
app.exec()

'''            
def run():
    bar.showMessage("버튼을 눌렀다")

menu = win.menuBar()
menuFile = menu.addMenu("파일")
menuEdit = menu.addMenu("편집")
menu.addMenu("종료")

open = QAction("열기", win)
close = QAction("닫기", win)
find = QAction("찾기", win)
font = QAction("글꼴", win)
edit = QAction("서식", win)

menuFile.addAction(open)
menuFile.addAction(close)
menuFile.addAction(find)
menuEdit.addAction(font)
menuEdit.addAction(edit)

bar = win.statusBar()
bar.showMessage("메뉴를 클릭해보세요")

open.triggered.connect(run)
'''
'''
def gogo():

    if int(line2.text()) > 25:
         lbl.setVisible(True)
         btn1.setVisible(False)
    else:
        btn1.setVisible(True)
        lbl.setVisible(False)


def gogo2():

    if len(line1.text()) > 4:
        alert = QMessageBox()
        alert.setText("이름은 1~4 지키셈")
        alert.exec()
    else:
        alert = QMessageBox()
        alert.setText("회원가입 성공임")
        alert.exec()


form = QFormLayout()
line1 = QLineEdit()
line2 = QLineEdit()
lbl = QLabel('나이가 너무 많습니다.')
btn1 = QPushButton("회원가입")
btn2 = QPushButton("나이 확인")
hlay = QHBoxLayout()
hlay.addWidget(line2)
hlay.addWidget(btn2)
form.addRow("age", line1)
form.addRow("name", hlay)
form.addRow(btn1)
form.addRow(lbl)
lbl.setVisible(False)
btn1.setVisible(False)

btn2.clicked.connect(gogo)
btn1.clicked.connect(gogo2)



win.setLayout(form)



'''
'''
tbox = QLineEdit(win)
btn = QPushButton("ok", win)

hlay = QVBoxLayout()
hlay.addWidget(tbox)
hlay.addWidget(btn)
win.setLayout(hlay)

btn.clicked.connect(gogo)

btn1 = QPushButton("one")
btn2 = QPushButton("two")
btn3 = QPushButton("three")
btn4 = QPushButton("onw")
btn5 = QPushButton("two")
btn6 = QPushButton("three")

mlay = QVBoxLayout()
vlay = QVBoxLayout()
hlay = QHBoxLayout()


hlay.addWidget(btn1)
hlay.addWidget(btn2)
hlay.addWidget(btn3)
vlay.addWidget(btn4)
vlay.addWidget(btn5)
vlay.addWidget(btn6)

mlay.addLayout(hlay)
mlay.addLayout(vlay)


win.setLayout(mlay)
'''
