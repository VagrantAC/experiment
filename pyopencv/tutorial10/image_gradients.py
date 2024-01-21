import cv2
import numpy as np

img = cv2.imread('./static/sudoku.jpg', 0)

kernel = np.array([
    [-1, 0, 1],
    [-2, 0, 2],
    [-1, 0, 1],
], dtype=np.float32)

dst_v = cv2.filter2D(img, -1, kernel)
dst_h = cv2.filter2D(img, -1, kernel.T)

cv2.imshow('edge', np.hstack((img, dst_v, dst_h)))
cv2.waitKey(0)