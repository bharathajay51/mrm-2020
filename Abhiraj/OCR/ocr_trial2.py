import numpy as np
import matplotlib.pyplot as plt
import cv2

import capture #self made scipt to capture an image

img = cv2.imread('sample.png', 0)
cv2.imshow('grayscale', img)

threshed = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 21, 7)
threshed = cv2.morphologyEx(threshed, cv2.MORPH_OPEN, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3)))
threshed = cv2.dilate(threshed, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (4,4)))
threshed = cv2.erode(threshed, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (2,2)))
threshed = cv2.blur(threshed, (2,2))
cv2.imshow('threshed',threshed)

#OLD CODE###
# edges = cv2.Canny(img, 127, 255)
# filled = cv2.morphologyEx(edges, cv2.MORPH_GRADIENT, cv2.getStructuringElement(cv2.MORPH_CROSS, (5,5)))
# filled = cv2.erode(filled, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3)))
# both = np.vstack((edges, filled))
# cv2.imshow('Canny & filled', both)
#############

filled = threshed
_, contours, _ = cv2.findContours(filled, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
src = cv2.cvtColor(filled, cv2.COLOR_GRAY2RGB)
p = 07 #padding
identify = np.zeros((len(contours), 400)) #characters to identify
for i, cnt in enumerate(contours):
    x, y, w, h = cv2.boundingRect(cnt)
    cv2.rectangle(src, (x,y), (x+w, y+h), (0,255,0), 1)
    roi = filled[y-p:y+h+p,x-p:x+w+p]
    roi_20x20 = cv2.resize(roi, (20,20)).T #the training set had all images transposed
    identify[i] = np.reshape(roi_20x20, (400,))
cv2.imshow('contoured', src)
cv2.waitKey(0)

import predict_digit
predict_digit.predict(identify)


cv2.destroyAllWindows()
