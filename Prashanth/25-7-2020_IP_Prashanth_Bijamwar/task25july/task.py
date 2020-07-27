import cv2
import numpy as np
from time import sleep

# Initializing video capture
cap = cv2.VideoCapture(0)

# Create old frame
ret, frame = cap.read()
oldGray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# Lucas-Kanade Params
lkParams = dict(winSize=(20, 20),
                maxLevel=4,
                criteria=(cv2.TermCriteria_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))


# Select Point Function
def selectObject(event, x, y, flags, params):
    global point, objSelected, oldPoints
    if event == cv2.EVENT_LBUTTONDOWN:
        point = (x, y)
        objSelected = True
        oldPoints = np.array([[x, y]], dtype=np.float32)


# Detect Direction
def detectDirection(old, new):
    if new[0][0] + 1 < old[0][0]:
        dir = 'MOTION TOWARDS LEFT'
    elif new[0][0] - 1 > old[0][0]:
        dir = 'MOTION TOWARDS RIGHT'
    else:
        dir = 'MOTION IS STILL'
    return dir


# Calling Select Object Function
cv2.namedWindow("Frame")
cv2.setMouseCallback("Frame", selectObject)

objSelected = False
point = ()
oldPoints = np.array([[]])

# While Loop
while True:

    # Reading Frames
    ret, frame = cap.read()
    grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # If object selected, use Optical Flow Algorithm to trace selected object motion
    if objSelected is True:
        newPoints, status, error = cv2.calcOpticalFlowPyrLK(oldGray, grayFrame, oldPoints, None, **lkParams)
        oldGray = grayFrame.copy()
        dir = detectDirection(oldPoints, newPoints)
        oldPoints = newPoints
        x, y = newPoints.ravel()
        cv2.circle(frame, (x, y), 5, (0, 255, 0), -1)
        cv2.putText(frame, dir, (200, 450), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)

    # If object not selected, tell user to click on object
    else:
        dir = 'CLICK ON A OBJECT'
        cv2.putText(frame, dir, (200, 450), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)

    # Show Frame
    cv2.imshow("Frame", frame)

    # Adding delay so that the putText() doesn't fluctuate
    sleep(0.1)

    # Initializing Wait Key
    key = cv2.waitKey(1)
    if key == 32:
        break

# Releasing video cap
cap.release()
# Destroying all cv2 windows
cv2.destroyAllWindows()