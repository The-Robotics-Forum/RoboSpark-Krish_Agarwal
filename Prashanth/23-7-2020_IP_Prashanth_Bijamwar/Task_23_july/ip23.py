# Importing cv2
import cv2

# Reading Image
img = cv2.imread('images/text.jpg')

# Converting to Gray Scale
imgGray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

# Converting to HSV
imgHsv = cv2.cvtColor(img, cv2.COLOR_RGB2HSV)

# Resizing Image
imgResize = cv2.resize(img, (300, 300))

# Printing Size and Shape
print(f'Original Image Shape is {img.shape} and Size is {img.size}')
print(f'Resized Image Shape is {img.shape} and Size is {img.size}')

# Simple Thresholding
retB, threshB = cv2.threshold(imgGray, 150, 255, cv2.THRESH_BINARY)
retO, threshO = cv2.threshold(imgGray, 150, 255, cv2.THRESH_OTSU)
retT, threshT = cv2.threshold(imgGray, 150, 255, cv2.THRESH_TOZERO)
retBI, threshBI = cv2.threshold(imgGray, 150, 255, cv2.THRESH_BINARY_INV)
retTI, threshTI = cv2.threshold(imgGray, 150, 255, cv2.THRESH_TOZERO_INV)

# Adaptive Thresholding
adaptive_thresh = cv2.adaptiveThreshold(imgGray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 5, 2)
adaptive_thresh_inv = cv2.adaptiveThreshold(imgGray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY_INV, 5, 2)
adaptive_thresh_gaus = cv2.adaptiveThreshold(imgGray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 2)

# Using imshow()
cv2.imshow('Original Image', img)
cv2.imshow('Gray Scale', imgGray)
cv2.imshow('HSV', imgHsv)
cv2.imshow('Resized Image', imgResize)
cv2.imshow('Binary Thresh', threshB)
cv2.imshow('Otsu Thresh', threshO)
cv2.imshow('Tozero Thresh', threshT)
cv2.imshow('Binary Inv Thresh', threshBI)
cv2.imshow('Tozero Inv Thresh', threshTI)
cv2.imshow('Adaptive Thresh Mean', adaptive_thresh)
cv2.imshow('Adaptive Inv Thresh Mean', adaptive_thresh_inv)
cv2.imshow('Adaptive Thresh Gaus', adaptive_thresh_gaus)

# Using imwrite()
cv2.imwrite("output/gray_scale.jpg", imgGray)
cv2.imwrite("output/hsv.jpg", imgHsv)
cv2.imwrite("output/resized_image.jpg", imgResize)
cv2.imwrite("output/thresh_binary.jpg", threshB)
cv2.imwrite("output/thresh_otsu.jpg", threshO)
cv2.imwrite("output/thresh_tozero.jpg", threshT)
cv2.imwrite("output/thresh_binary_inv.jpg", threshBI)
cv2.imwrite("output/thresh_tozero_inv.jpg", threshTI)
cv2.imwrite("output/adaptive_thresh_mean.jpg", adaptive_thresh)
cv2.imwrite("output/adaptive_thresh_mean_inv.jpg", adaptive_thresh_inv)
cv2.imwrite("output/adaptive_thresh_gaussian.jpg", adaptive_thresh_gaus)

# Initializing Wait key
cv2.waitKey(0)
cv2.destroyAllWindows()