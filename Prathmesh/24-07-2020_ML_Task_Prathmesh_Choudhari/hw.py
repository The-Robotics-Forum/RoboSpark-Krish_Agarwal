import cv2
import numpy as np

#original=cv2.imread(r"C:\Users\Prathmesh\Desktop\hah.jpg")
original = cv2.imread(r'yellow_flower.jpg')
original = cv2.resize(original,(640,400))
bgrl= np.array([90,0,120], np.uint8)
bgrh=np.array([215,255,255],np.uint8)
mask= cv2.inRange(original,bgrl,bgrh)
#kernel=  np.array(([3, 2, 6], [5,7,8],[2,4,8]), np.uint8)
kernel=  np.array(([1,1,1], [1,1,1],[1,1,1]), np.uint8)
blurred = cv2.filter2D(original, -1, kernel)
avg =cv2.blur(original,(5,5))
median = cv2.medianBlur(original,5)
bilateral = cv2.bilateralFilter(original,2,75,75)


#flowerpot=cv2.ellipse(bilateral,(256,256),(100,50),90,0,270,(170,45,0),-1)
flowerpot=cv2.ellipse(bilateral,(300,300),(50,100),90,-90,90,(0,255,255),thickness=5)
flowerpot=cv2.ellipse(flowerpot,(300,350),(50,100),90,135,-135,(51, 51, 255),-1)



#cv2.imshow("original",original)
#cv2.imshow("mask",mask)
#cv2.imshow("blurred",blurred)
#cv2.imshow("Average",avg)
#cv2.imshow("median",median)
#cv2.imshow("bilateral",bilateral)
cv2.imshow("flowerpot",flowerpot)



cv2.waitKey(0)
cv2.destroyAllWindows()