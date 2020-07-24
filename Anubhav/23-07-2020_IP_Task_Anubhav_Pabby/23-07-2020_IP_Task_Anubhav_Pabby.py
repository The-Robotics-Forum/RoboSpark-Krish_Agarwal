# importing lib
import cv2

# Reading the image
img = cv2.imread(r'text.jpg')
cv2.imshow('original image',img)

# converting to HSV
HSV_img = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
cv2.imshow('HSV format image',HSV_img)

# resizing the image
img1 = cv2.resize(img, (300,300))
cv2.imshow('resized orginal image',img1)

#Printing the image
print("shape of the original image ", img.shape)
print("Size of the original image ", img.size)
print("shape of the original image ", img1.shape)
print("Size of the original image ", img1.size)

# image conversion
grey = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow('GRAY format image',grey)

#Thresholding
ret,thresh1=cv2.threshold(grey,185,255,cv2.THRESH_BINARY)
cv2.imshow("thresh1",thresh1)

ret,thresh2=cv2.threshold(grey,185,255,cv2.THRESH_BINARY_INV)
cv2.imshow("thresh2",thresh2)

ret,thresh3=cv2.threshold(grey,185,255,cv2.THRESH_OTSU)
cv2.imshow("thresh3",thresh3)

ret,thresh4=cv2.threshold(grey,185,255,cv2.THRESH_TOZERO)
cv2.imshow("thresh4",thresh4)

#Saving the images
cv2.imwrite('HSV_img.jpg', HSV_img)
cv2.imwrite('img1.jpg', img1)
cv2.imwrite('grey.jpg', grey)
cv2.imwrite('thresh1.jpg', thresh1)
cv2.imwrite('thresh2.jpg', thresh2)
cv2.imwrite('thresh3.jpg', thresh3)
cv2.imwrite('thresh4.jpg', thresh4)
cv2.waitKey()
cv2.destroyAllWindows()
