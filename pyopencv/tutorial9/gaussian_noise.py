import cv2

img = cv2.imread('./static/gaussian_noise.bmp')
blur = cv2.blur(img, (5, 5))
gaussian = cv2.GaussianBlur(img, (5, 5), 1)

cv2.imshow('origin', img)
cv2.imshow('blur', blur)
cv2.imshow('gaussian', gaussian)
cv2.waitKey(0)