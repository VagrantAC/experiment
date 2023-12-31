import cv2

img = cv2.imread('./static/lenna.jpg', cv2.IMREAD_COLOR)

cv2.namedWindow('lena', cv2.WINDOW_NORMAL)
cv2.imshow('lena', img)

if cv2.waitKey(0) == ord('s'):
    print("Yes")
    cv2.imwrite('./static/lena_save.bmp', img)
else:
    print("No")
