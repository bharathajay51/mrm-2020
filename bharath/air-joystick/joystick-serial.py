from __future__ import print_function
from imutils.video import VideoStream
import imutils
import time
import serial
import cv2

ser = serial.Serial('COM6',9600,timeout=0)
time.sleep(2)
ser.flush()

# pass coordiates to arduino over serial
def mapObjectPosition (x, y):
    ser.write(str.encode('X'+str(x)))
    ser.write(str.encode('Y'+str(y)))	
    print ("X = {0} and Y =  {1}".format(x, y))
	

print("[INFO] waiting for camera to warmup...")
vs = VideoStream(0).start()
time.sleep(2.0)

# HSV values for the object
colorLower = (157, 51, 124)
colorUpper = (179, 148, 225)


while True:
	frame = vs.read()
	frame = cv2.resize(frame, (512,512))
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)   
	
	cv2.line(frame, (0, 255), (512, 255),(0,255,0), 3)
	cv2.line(frame, (255, 0), (255, 512),(0,255,0), 3)

	# construct a mask for the object color, then perform
	# a series of dilations and erosions to remove any small
	# blobs left in the mask
	mask = cv2.inRange(hsv, colorLower, colorUpper)
	mask = cv2.erode(mask, None, iterations=2)
	mask = cv2.dilate(mask, None, iterations=2)

	cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
		cv2.CHAIN_APPROX_SIMPLE)
	cnts = cnts[0] if imutils.is_cv2() else cnts[1]
	center = None

	# only proceed if at least one contour was found
	if len(cnts) > 0:
		c = max(cnts, key=cv2.contourArea)
		((x, y), radius) = cv2.minEnclosingCircle(c)
		M = cv2.moments(c)
		center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

		if radius > 10:
			# draw the circle and centroid on the frame,
			cv2.circle(frame, (int(x), int(y)), int(radius),
				(0, 255, 255), 2)
			cv2.circle(frame, center, 5, (0, 0, 255), -1)
			
			mapObjectPosition(int(x), int(y))
			

	cv2.imshow("Frame", frame)
	cv2.imshow("Mask", mask)
	
	key = cv2.waitKey(1) & 0xFF
	if key == 27:
            break

print("\n [INFO] Exiting Program and cleanup stuff \n")
cv2.destroyAllWindows()
vs.stop()