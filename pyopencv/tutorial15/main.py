import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('./static/lena.jpg', 0)
template = cv2.imread('./static/face.jpg', 0)
h, w = template.shape[:2]

res = cv2.matchTemplate(img, template, cv2.TM_CCOEFF)
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

left_top = max_loc
right_bottom = (left_top[0] + w, left_top[1] + h)
cv2.rectangle(img, left_top, right_bottom, 255, 2)

cv2.imshow('img', img)
cv2.waitKey(0)