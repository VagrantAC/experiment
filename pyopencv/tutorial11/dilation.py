import cv2
import numpy as np

kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5)) 

img = cv2.imread('./static/school.bmp', 0)

gradient = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)
tophat = cv2.morphologyEx(img, cv2.MORPH_TOPHAT, kernel)
blackhat = cv2.morphologyEx(img, cv2.MORPH_BLACKHAT, kernel)

cv2.imshow('morphology-ex', np.hstack((
    img,
    gradient,
    tophat,
    blackhat,
)))
cv2.waitKey(0)