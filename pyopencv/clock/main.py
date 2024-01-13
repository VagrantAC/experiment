import cv2
import math
import numpy as np
import datetime

side_len = 512
margin = 5
radius = int(side_len / 2) - margin


def drawCircle(img: np.ndarray[np.uint8]):
    cv2.circle(img, (256, 256), radius, (0, 0, 0), thickness=margin)


def drawLine(img: np.ndarray[np.uint8]):
    for i in range(0, 60):
        angle = i * 6 * np.pi / 180
        x = int(math.cos(angle) * radius)
        y = int(math.sin(angle) * radius)

        if i % 5 == 0:
            cv2.line(
                img,
                (int(x * 0.9 + 256), int(y * 0.9 + 256)),
                (x + 256, y + 256),
                (0, 0, 0),
                thickness=5,
            )
        else:
            cv2.line(
                img,
                (int(x * 0.95 + 256), int(y * 0.95 + 256)),
                (x + 256, y + 256),
                (0, 0, 0),
                thickness=2,
            )


img = np.zeros((side_len, side_len, 3), np.uint8)
img[:] = (255, 255, 255)

drawCircle(img)
drawLine(img)

while True:
    temp = np.copy(img)
    now_time = datetime.datetime.now()
    hour, minute, second = now_time.hour, now_time.minute, now_time.second
    minute += second / 60
    hour += minute / 60

    sec_angle = (second - 15) * 6 * np.pi / 180
    sec_x = 256 + int(math.cos(sec_angle) * 256 * 0.96)
    sec_y = 256 + int(math.sin(sec_angle) * 256 * 0.96)
    cv2.line(temp, (256, 256), (sec_x, sec_y), (203, 222, 166), 2)

    min_angle = (minute - 15) * 6 * np.pi / 180
    min_x = 256 + int(math.cos(min_angle) * 256 * 0.85)
    min_y = 256 + int(math.sin(min_angle) * 256 * 0.85)
    cv2.line(temp, (256, 256), (min_x, min_y), (186, 199, 137), 8)

    hour_angle = (hour - 15) * 30 * np.pi / 180
    hour_x = 256 + int(math.cos(hour_angle) * 256 * 0.75)
    hour_y = 256 + int(math.sin(hour_angle) * 256 * 0.75)
    cv2.line(temp, (256, 256), (hour_x, hour_y), (169, 198, 26), 15)

    font = cv2.FONT_HERSHEY_SIMPLEX
    time_str = now_time.strftime("%d/%m/%Y")
    cv2.putText(img, time_str, (150, 300), font, 1, (0, 0, 0), 2)

    cv2.imshow("clocking", temp)
    if cv2.waitKey(1) == 27:
        break
