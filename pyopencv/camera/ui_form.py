# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'form.ui'
##
## Created by: Qt User Interface Compiler version 6.6.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QPushButton, QSizePolicy,
    QWidget)

class Ui_Widget(object):
    def setupUi(self, Widget):
        if not Widget.objectName():
            Widget.setObjectName(u"Widget")
        Widget.resize(610, 400)
        self.btnOpenCamera = QPushButton(Widget)
        self.btnOpenCamera.setObjectName(u"btnOpenCamera")
        self.btnOpenCamera.setGeometry(QRect(18, 300, 100, 32))
        self.btnCapture = QPushButton(Widget)
        self.btnCapture.setObjectName(u"btnCapture")
        self.btnCapture.setGeometry(QRect(136, 300, 100, 32))
        self.labelCamera = QLabel(Widget)
        self.labelCamera.setObjectName(u"labelCamera")
        self.labelCamera.setGeometry(QRect(40, 100, 150, 150))
        self.labelCapture = QLabel(Widget)
        self.labelCapture.setObjectName(u"labelCapture")
        self.labelCapture.setGeometry(QRect(230, 100, 150, 150))
        self.labelResult = QLabel(Widget)
        self.labelResult.setObjectName(u"labelResult")
        self.labelResult.setGeometry(QRect(420, 100, 150, 150))
        self.btnGray = QPushButton(Widget)
        self.btnGray.setObjectName(u"btnGray")
        self.btnGray.setGeometry(QRect(372, 300, 100, 32))
        self.btnReadImage = QPushButton(Widget)
        self.btnReadImage.setObjectName(u"btnReadImage")
        self.btnReadImage.setGeometry(QRect(254, 300, 100, 32))
        self.btnThreshold = QPushButton(Widget)
        self.btnThreshold.setObjectName(u"btnThreshold")
        self.btnThreshold.setGeometry(QRect(490, 300, 100, 32))

        self.retranslateUi(Widget)
        self.btnCapture.clicked.connect(Widget.btnCapture_Clicked)
        self.btnOpenCamera.clicked.connect(Widget.btnOpenCamera_Clicked)
        self.btnReadImage.clicked.connect(Widget.btnReadImage_Clicked)
        self.btnGray.clicked.connect(Widget.btnGray_Clicked)
        self.btnThreshold.clicked.connect(Widget.btnThreshold_Clicked)

        QMetaObject.connectSlotsByName(Widget)
    # setupUi

    def retranslateUi(self, Widget):
        Widget.setWindowTitle(QCoreApplication.translate("Widget", u"Widget", None))
        self.btnOpenCamera.setText(QCoreApplication.translate("Widget", u"\u6253\u5f00\u6444\u50cf\u5934", None))
        self.btnCapture.setText(QCoreApplication.translate("Widget", u"\u6355\u83b7\u56fe\u7247", None))
        self.labelCamera.setText(QCoreApplication.translate("Widget", u"\u6444\u50cf\u5934", None))
        self.labelCapture.setText(QCoreApplication.translate("Widget", u"\u6355\u83b7\u56fe", None))
        self.labelResult.setText(QCoreApplication.translate("Widget", u"\u7ed3\u679c\u56fe", None))
        self.btnGray.setText(QCoreApplication.translate("Widget", u"\u7070\u5ea6\u5316", None))
        self.btnReadImage.setText(QCoreApplication.translate("Widget", u"\u6253\u5f00\u56fe\u7247", None))
        self.btnThreshold.setText(QCoreApplication.translate("Widget", u"\u9608\u503c\u5206\u5272(Otsu)", None))
    # retranslateUi

