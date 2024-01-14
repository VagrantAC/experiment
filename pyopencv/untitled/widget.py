# This Python file uses the following encoding: utf-8
import sys
import cv2
# import PySide6

from PySide6.QtCore import QTimer, Signal
from PySide6.QtWidgets import QApplication, QWidget
from PySide6.QtGui import QImage, Qt, QPixmap

# Important:
# You need to run the following command to generate the ui_form.py file
#     pyside6-uic form.ui -o ui_form.py, or
#     pyside2-uic form.ui -o ui_form.py
from ui_form import Ui_Widget

class PyQtMainEntry(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.ui = Ui_Widget()
        self.ui.setupUi(self)

        self.camera = cv2.VideoCapture(1)
        self.is_camera_opened = False

        self._timer = QTimer(self)
        self._timer.timeout.connect(self._queryFrame)
        self._timer.setInterval(30)

    @Signal
    def _queryFrame(self):
        ret, self.frame = self.camera.read()
        img_rows, img_cols, channels = self.frame.shape
        bytesPerLine = channels * img_cols

        cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB, self.frame)
        QImg = QImage(self.frame.data, img_cols, img_rows,
                              bytesPerLine, QImage.Format_RGB888)
        print("XXXX")
        self.labelCamera.setPixmap(QPixmap.fromImage(QImg).scaled(
                self.labelCamera.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = PyQtMainEntry()
    widget.show()
    sys.exit(app.exec())
