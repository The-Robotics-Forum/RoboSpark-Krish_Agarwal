import cv2
import numpy as np

img = cv2.imread('Session 2/rose_flower.jpg')

bgrl = np.array([90, 0, 120], np.uint8)
bgrh = np.array([255, 255, 255], np.uint8)

mask = cv2.inRange(img, bgrl, bgrh)

kernal = np.array(([3, 2, 6], [5, 7, 8], [2, 4, 8]), np.uint8)

filter2d = cv2.filter2D(mask, -1, kernal)
pot = cv2.filter2D(mask, -1, kernal)

avg = cv2.blur(mask, (5,5))

gaus_blur = cv2.GaussianBlur(mask, (5,5), 0)

med_blur = cv2.medianBlur(mask, 5)

bi = cv2.bilateralFilter(mask, 5, 111, 111)

pot = cv2.line(pot, (10, 450), (45, 680), (42, 42, 165), 5) # parameters are ( image object, start point, end point, color scheme, thickness)
pot = cv2.line(pot, (210, 450), (165, 680), (42, 42, 165), 5)
pot = cv2.line(pot, (45, 680), (165, 680), (42, 42, 165), 5)


pot = cv2.ellipse(pot, (110, 450), (103, 30), 0, 0, 360, (42, 42, 165), -1)

font = cv2.FONT_HERSHEY_SCRIPT_SIMPLEX

cv2.putText(pot, 'ROSE', (200, 600), font, 3, (80, 0, 220), 5, cv2.LINE_AA)

# DISPLAYING OUTPUT
cv2.imshow('Original', img)
cv2.imshow('Masked', mask)
cv2.imshow('Flower with Pot', pot)
cv2.imshow('Filter 2D', filter2d)
cv2.imshow('Averaging', avg)
cv2.imshow('Gaussian', gaus_blur)
cv2.imshow('Median', med_blur)
cv2.imshow('Bilateral', bi)

#SAVING IMAGES
cv2.imwrite('Mask.jpeg', mask)
cv2.imwrite('Filter2D.jpeg', filter2d)
cv2.imwrite('Averaging.jpeg', avg)
cv2.imwrite('Gaussian.jpeg', gaus_blur)
cv2.imwrite('Median.jpeg', med_blur)
cv2.imwrite('Bilateral.jpeg', bi)
cv2.imwrite("Pot_and_Text.jpeg", pot)

# EXIT CONTROL
cv2.waitKey(0)
cv2.destroyAllWindows()