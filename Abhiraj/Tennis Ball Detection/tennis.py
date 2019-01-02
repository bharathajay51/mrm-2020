import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    key = cv2.waitKey(1)
    if key == ord('q'):
        break
    
    _, frame = cap.read()
    cv2.imshow('frame', frame)



    frame_HSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_green = np.array([29, 86, 6])
    upper_green = np.array([64, 255, 255])
    
    mask = cv2.inRange(frame_HSV, lower_green, upper_green)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5,5)))
    mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (50,50)))

    res = cv2.bitwise_and(frame, frame, mask=mask)  

    _, conts, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    conts = np.array(conts)
    if len(conts) > 0:
        area = np.argmax([cv2.arcLength(c, True) for c in conts])
        (x,y),r = cv2.minEnclosingCircle(conts[area])
        res = cv2.drawContours(res,conts, area, (255,0,0),2)
        res = cv2.circle(res, (int(x),int(y)), int(r), (0,255,0), 3)
        res = cv2.circle(res, (int(x), int(y)), 0, (0,0,255), 9)
    
    cv2.imshow('mask', mask)
    cv2.imshow('result',res)

cv2.destroyAllWindows()
