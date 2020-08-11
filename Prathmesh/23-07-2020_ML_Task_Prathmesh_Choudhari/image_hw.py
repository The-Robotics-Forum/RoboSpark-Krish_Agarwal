import cv2

print(cv2.__version__)   #Prints the version of cv2

color = cv2.imread(r"C:\Users\hp\Desktop\MY_Doc\chayachitra\mobile photos\img.jpg",cv2.IMREAD_COLOR) #Read image in colour mode
#cv2.imshow("color",color) #To print color image

hsv= cv2.cvtColor(color,cv2.COLOR_BGR2HSV)
#cv2.imshow("hsv",hsv)

gray = cv2.cvtColor(color, cv2.COLOR_RGB2GRAY)
cv2.imshow("gray",gray)

print(color) #To print all pixels value

print("colour image shape",color.shape)  #Here we print shape of colour image

print("colour image size",color.size) #Here we print the size of colour image

h,w,c=color.shape #Here we can individualy access the height,width,channels

print(h,w,c) #Here we print the value

color=cv2.resize(color,(300,300))  #Here we resize the image

cv2.imshow("resize",color) #Here we print the resize image



print("gray image shape",gray.shape)  #Here we print shape of gray image

print("gray image size",gray.size) #Here we print size if gray image

h,w=gray.shape #Here we can individualy access the height,width no channels as it is gray image

print(h,w) #Here we print the values

#thresholding
ret,thresh=cv2.threshold(gray,150,255,cv2.THRESH_BINARY)
adaptive_thresh=cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,2)
adaptive_thresh1=cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,5,2)

cv2.imshow('threshold',thresh)
cv2.imshow('Adaptive_mean',adaptive_thresh)
cv2.imshow('Adaptive_gauss' ,adaptive_thresh)



#-------------------------------------------------------------------------



#----------------------------


# Note : -Following two lines have been commented so you can try that by uncommenting it

#  cv2.destroyWindow("color") #Use to destroy particular window

#  l=cv2.waitKey(5000) #Here we have pass time in millisecond

#  print(l) # When we pass time as parameter then it returns -1 as we havn't press any key

k=cv2.waitKey(0)#we use theses till any key is press

print(k)  # It print the Ascii value of the key pressed

cv2.destroyAllWindows() # It destroy all windows