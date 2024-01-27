import cv2
import numpy as np

img_rgb = cv2.rotate(cv2.imread('./static/mario.jpg'), cv2.ROTATE_90_CLOCKWISE)

img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)
template = cv2.rotate(cv2.imread('./static/mario_coin.jpg', 0), cv2.ROTATE_90_CLOCKWISE)
h, w = template.shape[:2]

res = cv2.matchTemplate(img_gray, template, cv2.TM_CCOEFF_NORMED)
threshold = 0.8

loc = np.where(res >= threshold)
for pt in zip(*loc[::-1]):
    right_bottom = (pt[0] + w, pt[1] + h)
    cv2.rectangle(img_rgb, pt, right_bottom, (0, 0, 255), 2)

cv2.imshow('img_rgb', img_rgb)
cv2.waitKey(0)