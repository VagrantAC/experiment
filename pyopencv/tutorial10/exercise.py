import cv2
import numpy as np

def nothing():
    pass

cv2.namedWindow('image')
cv2.createTrackbar('maxVal', 'image', 0, 255, nothing)
cv2.createTrackbar('minVal', 'image', 0, 255, nothing)

img = cv2.imread('./static/sudoku.jpg', 0)
edges = cv2.Canny(img, 30, 70)

while(True):
    cv2.imshow('image', np.hstack((img, edges)))
    if cv2.waitKey(1) == 27:
        break

    thresholdMin = cv2.getTrackbarPos('maxVal', 'image')
    thresholdMax = cv2.getTrackbarPos('minVal', 'image')
    edges = cv2.Canny(img, thresholdMin, thresholdMax)