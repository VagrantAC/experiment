import cv2
import numpy as np

capture = cv2.VideoCapture(0)

lower_blue = np.array([100, 100, 100])
upper_blue = np.array([120, 255, 255])

lower_green = np.array([40, 100, 100])
upper_green = np.array([70, 255, 255])

lower_red1 = np.array([0, 100, 100])
upper_red1 = np.array([10, 255, 255])

lower_red2 = np.array([160, 100, 100])
upper_red2 = np.array([180, 255, 255])

while (True):
    ret, frame = capture.read()
    
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask_blue = cv2.inRange(hsv, lower_blue, upper_blue)
    mask_green = cv2.inRange(hsv, lower_green, upper_green)
    mask_red1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask_red2 = cv2.inRange(hsv, lower_red2, upper_red2)
    # final_mask = mask_blue
    final_mask = cv2.bitwise_or(mask_blue, 
                                cv2.bitwise_or(mask_green, 
                                               cv2.bitwise_or(mask_red1, mask_red2)))
    res = cv2.bitwise_and(frame, frame, mask=final_mask)

    cv2.imshow('frame', frame)
    cv2.imshow('mask', final_mask)
    cv2.imshow('res', res)

    if cv2.waitKey(1) == ord('q'):
        break