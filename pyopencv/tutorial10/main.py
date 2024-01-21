import cv2
import numpy as np

img = cv2.imread('./static/handwriting.jpg', 0)
edges = cv2.Canny(img, 30, 70)

cv2.imshow('canny', np.hstack((img, edges)))
cv2.waitKey(0)