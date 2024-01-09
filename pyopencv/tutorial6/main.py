import cv2

img = cv2.imread("./static/lenna.jpg")
height, width, _ = img.shape

res = cv2.resize(img, (int(height / 2), int(width / 2)))

res2 = cv2.resize(img, None, fx=2, fy=2, interpolation=cv2.INTER_LINEAR)

# cv2.imshow("shrink", res)
# cv2.imshow("zoom", res2)
# cv2.waitKey(0)

dst = cv2.flip(img, 1)
cv2.imshow('dst', dst)
cv2.waitKey(0)