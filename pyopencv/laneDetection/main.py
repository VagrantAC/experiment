import cv2
import math
import numpy as np

origin_img = cv2.imread('./static/lane_detection.jpeg')
img = cv2.imread('./static/lane_detection.jpeg', 0)
blur_gray = cv2.GaussianBlur(img, (5, 5), 0)
canny = cv2.Canny(blur_gray, 50, 150)
rows, cols = img.shape

# roi
mask = np.zeros_like(img)
pts = np.array([
    [(0, rows), 
     (460, 325),
     (520, 325),
     (cols, rows)
    ]],
    np.int32)
pts = pts.reshape((-1, 1, 2))
cv2.fillPoly(mask, [pts], (255, 255, 255))
masked_img = cv2.bitwise_and(canny, mask)

# hough lines p
lines = cv2.HoughLinesP(masked_img, 0.8, np.pi / 180, 90,
                        minLineLength=50, maxLineGap=10)

lsum_k = 0
lsum_b = 0
lcount = 0
rsum_k = 0
rsum_b = 0
rcount = 0
for line in lines:
    x0, y0, x1, y1 = line[0]
    k = (y1 - y0) / (x1 - x0)
    b = y1 - k * x1
    if k < 0:
        lsum_k += k
        lsum_b += b
        lcount += 1
    else:
        rsum_k += k
        rsum_b += b
        rcount += 1

lavg_k = lsum_k / lcount
lavg_b = lsum_b / lcount
ravg_k = rsum_k / rcount
ravg_b = rsum_b / rcount

cv2.line(origin_img,
        (int((rows - lavg_b) / lavg_k), rows),
        (int((325 - lavg_b) / lavg_k), 325),
        (0, 0, 255),
        1,
        lineType=cv2.LINE_AA)

cv2.line(origin_img,
        (int((rows - ravg_b) / ravg_k), rows),
        (int((325 - ravg_b) / ravg_k), 325),
        (0, 0, 255),
        1,
        lineType=cv2.LINE_AA)
cv2.imshow('mask', origin_img)
cv2.waitKey(0)
