import cv2

img = cv2.imread('./static/handwriting.jpg')
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(img_gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

contours, hierarchy = cv2.findContours(
    thresh,
    cv2.RETR_TREE,
    cv2.CHAIN_APPROX_SIMPLE
)

contour_img = cv2.drawContours(
    cv2.cvtColor(thresh, cv2.COLOR_GRAY2BGR),
    contours,
    -1,
    (0, 255, 255),
    5
)
cv2.imshow('contour img', contour_img)
cv2.waitKey(0)