import cv2
import numpy as np

img = cv2.imread('./static/sudoku.jpg', 0)

sobelx = cv2.Sobel(img, -1, 1, 0, ksize=3)
sobely = cv2.Sobel(img, -1, 0, 1, ksize=3)

cv2.imshow('sobel', np.hstack((img, sobelx, sobely)))
cv2.waitKey(0)