import cv2
import numpy as np

img = cv2.imread('./static/sudoku.jpg', 0)
laplacian = cv2.Laplacian(img, -1)

cv2.imshow('laplacian', laplacian)
cv2.waitKey(0)