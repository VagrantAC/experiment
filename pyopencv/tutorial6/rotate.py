import cv2
import numpy as np

img = cv2.imread("./static/lenna.jpg")
rows, cols = img.shape[:2]

M = cv2.getRotationMatrix2D((cols / 2, rows / 2), 45, 0.5)
dst = cv2.warpAffine(img, M, (cols, rows))

cv2.imshow('rotation', dst)
cv2.waitKey(0)