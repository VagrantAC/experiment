import cv2

img = cv2.imread('./static/lena.jpg', 0)
cv2.imshow('origin', img)

gau = cv2.GaussianBlur(img, (5, 5), 0)
cv2.imshow('gau', gau)

blur = cv2.bilateralFilter(img, 9, 75, 75)
cv2.imshow('blur', blur)

cv2.waitKey(0)