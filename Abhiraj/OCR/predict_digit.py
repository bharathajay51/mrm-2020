import numpy as np

import matplotlib.pyplot as plt
import scipy.io as sio

def sigmoid(z):
    return 1/(1+np.exp(-z))

def h(X, theta, b):
    return sigmoid(np.sum(theta*X, axis=1)[:, np.newaxis] + b)


bias = np.load('biasl110k.npy')
theta = np.load('thetasl110k.npy')

def predict(inpt):
    inpt = (inpt-np.mean(inpt, axis=1)[:,np.newaxis])/255
    # print inpt.tolist()
    num_cases = inpt.shape[0] 
    for i, case in enumerate(inpt):
        plt.subplot(1, num_cases, i+1)
        plt.axis('off')
        prediction = np.argmax(h(np.array([case]), theta, bias))
        plt.title(prediction)
        plt.imshow(np.reshape(case, (20,20)).T, cmap='gray')

    plt.show()
