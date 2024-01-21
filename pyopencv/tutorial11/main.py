import cv2
import numpy as np

img =cv2.imread('./static/j.bmp', 0)
kernel = np.ones((5, 5), np.uint8)
erosion = cv2.erode(img, kernel)
dilation = cv2.dilate(img, kernel)

cv2.imshow('erode-and-dilate', np.hstack((
    img,
    erosion,
    dilation,
)))
# cv2.imshow('erode-and-dilate', erosion)
cv2.waitKey(0)