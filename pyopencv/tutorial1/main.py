import cv2

img = cv2.imread("./static/lenna.jpg", 0)

# cv2.imshow('lena', img)
# cv2.waitKey(0)

cv2.namedWindow('lena2', cv2.WINDOW_NORMAL)
cv2.imshow('lena2', img)
cv2.waitKey(0)

cv2.imwrite('./static/lena_gray.jpg', img)
