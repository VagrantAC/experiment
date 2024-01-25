import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./static/hist.jpg', 0)
hist = cv2.calcHist([img], [0], None, [256], [0, 256])
plt.hist(img.ravel(), 256, [0, 256])
plt.show()

equ = cv2.equalizeHist(img)
cv2.imshow('equalization', np.hstack((img, equ)))
cv2.waitKey(0)