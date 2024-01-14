# This Python file uses the following encoding: utf-8
import sys
import cv2

from PySide6.QtCore import QTimer
from PySide6.QtWidgets import QApplication, QWidget, QFileDialog
from PySide6.QtGui import QImage, Qt, QPixmap

from ui_form import Ui_Widget

class PyQtMainEntry(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.ui = Ui_Widget()
        self.ui.setupUi(self)

        self.camera = cv2.VideoCapture(0)
        self.is_camera_opened = False

        self._timer = QTimer(self)
        self._timer.timeout.connect(self._queryFrame)
        self._timer.setInterval(30)


    def btnOpenCamera_Clicked(self):
        self.is_camera_opened = ~self.is_camera_opened
        if self.is_camera_opened:
            self.ui.btnOpenCamera.setText("关闭摄像头")
            self._timer.start()
        else:
            self.ui.btnOpenCamera.setText("打开摄像头")
            self._timer.stop()


    def btnCapture_Clicked(self):
        if not self.is_camera_opened:
            return

        self.captured = self.frame

        rows, cols, channels = self.captured.shape
        bytesPerLine = channels * cols

        QImg = QImage(self.captured.data, cols, rows, bytesPerLine, QImage.Format_RGB888)
        self.ui.labelCapture.setPixmap(QPixmap.fromImage(QImg).scaled(
            self.ui.labelCapture.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))


    def btnReadImage_Clicked(self):
        filename, _ = QFileDialog.getOpenFileName(self, "打开图片")

        if filename:
            self.captured = cv2.imread(str(filename))
            self.captured = cv2.cvtColor(self.captured, cv2.COLOR_BGR2RGB)

            rows, cols, channels = self.captured.shape
            bytesPerLine = channels * cols
            QImg = QImage(self.captured.data, cols, rows, bytesPerLine, QImage.Format_RGB888)
            self.ui.labelCapture.setPixmap(QPixmap.fromImage(QImg).scaled(
               self.ui.labelCapture.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))

    def btnGray_Clicked(self):
        if not hasattr(self, "captured"):
            return

        self.captured = cv2.cvtColor(self.captured, cv2.COLOR_RGB2GRAY)

        rows, columns = self.captured.shape
        bytesPerLine = columns

        QImg = QImage(self.captured.data, columns, rows, bytesPerLine, QImage.Format_Indexed8)
        self.ui.labelResult.setPixmap(QPixmap.fromImage(QImg).scaled(
            self.ui.labelResult.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))


    def btnThreshold_Clicked(self):
        if not hasattr(self, "captured"):
            return

        _, self.captured = cv2.threshold(
            cv2.cvtColor(self.captured, cv2.COLOR_BGR2GRAY),
                0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)

        rows, columns = self.captured.shape
        bytesPerLine = columns

        QImg = QImage(self.captured.data, columns, rows, bytesPerLine, QImage.Format_Indexed8)
        self.ui.labelResult.setPixmap(QPixmap.fromImage(QImg).scaled(
            self.ui.labelResult.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))


    def _queryFrame(self):
        ret, self.frame = self.camera.read()
        img_rows, img_cols, channels = self.frame.shape
        bytesPerLine = channels * img_cols

        cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB, self.frame)
        QImg = QImage(self.frame.data, img_cols, img_rows,
                              bytesPerLine, QImage.Format_RGB888)
        self.ui.labelCamera.setPixmap(QPixmap.fromImage(QImg).scaled(
                self.ui.labelCamera.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = PyQtMainEntry()
    widget.show()
    sys.exit(app.exec())
