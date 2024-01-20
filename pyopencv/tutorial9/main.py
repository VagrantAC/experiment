import cv2

img = cv2.imread('./static/lena.jpg')
cv2.imshow('origin', img)

blur = cv2.blur(img, (3, 3))
cv2.imshow('blur', blur)

boxFilter = cv2.boxFilter(img, -1, (3, 3), normalize=True)
cv2.imshow('boxFilter', boxFilter)

cv2.waitKey(0)