import numpy as np
import cv2

cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    cv2.imshow('original', frame)
    cv2.imshow('threshold', cv2.adaptiveThreshold(cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY), 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 21, 9))
    if cv2.waitKey(1) == ord('q'):
        cv2.imwrite('sample.png', frame)
        cv2.destroyAllWindows()
        break

cap.release()
