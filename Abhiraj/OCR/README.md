# Simple OCR

### Files
-  **ocr\_trial2.py**: Main file that calls other small scripts to process a character. This file extracts the character image from the camera. Run this file to start the camera.

- **capture.py** : This file shows the video stream from the camera and expects the user to press q to capture, the file captured is stored as sample.png in the same directory.

- **predict_digits.py** : this is a python script that uses pre-calculated parameters from a logistic regression classifier for 10 classes.

- **biasl110k.npy, thetasl110k.npy** : These are the pre calculated weights calculated with _l_ambda = 1 and _10k_ iterations for the gradient descent to converge.

The logistic regression classifier that was used to generate these weights exist [here](../ocr_logistic_regression.py) in the upper directory.

- **ocr_demo.mp4** : demo video


_The ocr has an accuracy of around 53% although the same parameters give an accuracy of around 83% on the training set. I am trying to get a better parameter values using other methods for minimization using scipy. Also the prediciton scipt could be swapped easily for another classifier like a neural net due to its modular nature (going to do so after I finish week 5 of Andrew Ng)_
