import cv2

def nothing(x: int):
    capture.set(cv2.CAP_PROP_POS_FRAMES, x)
    pass

cv2.namedWindow('video')
capture = cv2.VideoCapture('./static/oceans.mp4')

cv2.createTrackbar('process', 'video', 0, int(capture.get(cv2.CAP_PROP_FRAME_COUNT)), nothing)

while (True):
    ret, frame = capture.read()
    if frame is None:
        break

    cv2.imshow('video', frame)
    cv2.setTrackbarPos('process', 'video', int(capture.get(cv2.CAP_PROP_POS_FRAMES)))
    if cv2.waitKey(30) == ord('q'):
        break 