import cv2
import numpy as np

img = cv2.imread('./static/handwriting1.jpg', 0)
_, thresh = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
contours, hierarchy = cv2.findContours(thresh, 3, 2)
cnt = contours[1]

img_color1 = cv2.cvtColor(thresh, cv2.COLOR_GRAY2BGR)
img_color2 = np.copy(img_color1)
cv2.drawContours(img_color1, [cnt], 0, (0, 0, 255), 2)

print("Area:", cv2.contourArea(cnt)) 
print("ArcLength:", cv2.arcLength(cnt, True))

M = cv2.moments(cnt)
cx, cy = M['m10'] / M['m00'], M['m01'] / M['m00'] 
print("Cx:", cx, " Cy:", cy)

x, y, w, h = cv2.boundingRect(cnt)
cv2.rectangle(img_color1, (x, y), (x + w, y + h), (0, 255, 0), 2)

box = np.intp(cv2.boxPoints(cv2.minAreaRect(cnt)))
cv2.drawContours(img_color1, [box], 0, (255, 0, 0), 2)

ellipse = cv2.fitEllipse(cnt)
cv2.ellipse(img_color1, ellipse, (255, 255, 0), 2)

(x, y), radius = cv2.minEnclosingCircle(cnt)
(x, y, radius) = np.int0((x, y, radius))
cv2.circle(img_color1, (x, y), radius, (0, 0, 255), 2)

cv2.imshow('img_color', img_color1)
cv2.waitKey(0)