import cv2

img = cv2.imread('./static/lenna.jpg')
r = img[25:120, 50:220, 2]
cv2.imshow('red', r)
cv2.waitKey(0)