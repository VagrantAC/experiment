import cv2

img = cv2.imread('./static/salt_noise.bmp')
print(img)
cv2.imshow('origin', img)

blur = cv2.blur(img, (5, 5))
cv2.imshow('blur', blur)

median = cv2.medianBlur(img, 5)
cv2.imshow('median', median)

cv2.waitKey(0)