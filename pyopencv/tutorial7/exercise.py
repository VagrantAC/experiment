import cv2
import numpy as np
import matplotlib.pyplot as plt

img = np.zeros((512, 512, 3), np.uint8)
radius = int(256 / 3)
cv2.ellipse(img, (256, 128), (radius, radius), 0, 0, 360, (0, 0, 255), int(radius * 3 / 4))
cv2.ellipse(img, (128, 256+128), (radius, radius), 0, 0, 360, (0, 255, 0), int(radius * 3 / 4))
cv2.ellipse(img, (256+128, 256+128), (radius, radius), 0, 0, 360, (255, 0, 0), int(radius * 3 / 4))

cv2.fillPoly(img, 
             [np.array([
                 [256, 128], 
                 [256-64, 256],
                 [256, 256],
                 [256+64, 256], 
                 ])],
             (0, 0, 0)
             )

cv2.fillPoly(img, 
             [np.array([
                 [128, 256+128], 
                 [128+64, 256+32],
                 [256, 256],
                 [256, 256+128], 
                 ])],
             (0, 0, 0)
             )

cv2.fillPoly(img, 
             [np.array([
                 [256+128, 256+128], 
                 [256+64, 256],
                 [256+128, 256],
                 [256+128+64, 256], 
                 ])],
             (0, 0, 0)
             )

cv2.imshow('img', img)
cv2.waitKey(0)
