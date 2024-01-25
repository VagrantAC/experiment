import cv2
import numpy as np

img = cv2.imread('./static/tsukuba.jpg', 0)

clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
cl1 = clahe.apply(img)

cv2.imshow('equalization', np.hstack((img, cl1)))
cv2.waitKey(0)