import cv2
import numpy as np

# img = cv2.imread('./static/lenna.jpg')
# img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# cv2.imshow('img', img)
# cv2.imshow('gray', img_gray)
# cv2.waitKey(0)

capture = cv2.VideoCapture(0)

lower_color = np.array([100, 110, 110])
upper_color = np.array([130, 255, 255])

while(True):
    ret, frame = capture.read()

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask = cv2.inRange(hsv, lower_color, upper_color)

    res = cv2.bitwise_and(frame, frame, mask=mask)

    cv2.imshow('frame', frame)
    cv2.imshow('mask', mask)
    cv2.imshow('res', res)

    if cv2.waitKey(1) == ord('q'):
        break