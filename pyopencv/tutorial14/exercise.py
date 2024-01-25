import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('./static/hist.jpg', 0)

bgimg = np.zeros(img.shape[:2], np.uint8)
cv2.rectangle(bgimg, (0, 0), (200, 200), (255, 255, 255), -1)

hist = cv2.calcHist([img], [0], bgimg, [256], [0, 256])
plt.hist(img.ravel(), 256, [0, 256])
plt.show()
cv2.imshow('bgimg', bgimg)
cv2.waitKey(0)