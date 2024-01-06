import cv2

img = cv2.imread('./static/lenna.jpg')

px = img[100, 90]
print(px)

px_blue = img[100, 90, 0]
print(px_blue)

img[100, 90] = [255, 255, 255]
print(img[100, 90])

# print(img.shape)

height, width, channels = img.shape
print("height:", height, "width:", width, "channels:", channels)

print("dtype:", img.dtype)

print("size:", img.size)

face = img[int(height/2):height, int(width/2):width]
cv2.imshow('face', face)
cv2.waitKey(0)
b, g, r = cv2.split(img)

b = img[:, :, 0]
cv2.imshow('blue', b)
cv2.waitKey(0)

g = img[:, :, 1]
cv2.imshow('green', g)
cv2.waitKey(0)

r = img[:, :, 2]
cv2.imshow('red', r)
cv2.waitKey(0)