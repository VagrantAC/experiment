import cv2
import numpy as np

kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))

out_img = cv2.imread('./static/j_noise_out.bmp', 0)
in_img = cv2.imread('./static/j_noise_in.bmp', 0)
opening = cv2.morphologyEx(out_img, cv2.MORPH_OPEN, kernel)
closing = cv2.morphologyEx(in_img, cv2.MORPH_CLOSE, kernel)

cv2.imshow('open-and-close', np.hstack((
    out_img,
    opening,
    in_img,
    closing,
)))
cv2.waitKey(0)