'''
Neural net with 400 neurons in the input layer and 25 neurons in the hidden layer, 
10 on the output layer.
'''
import numpy as np
import matplotlib.pyplot as plt
import scipy.io as sio
from scipy.optimize import minimize

data = sio.loadmat('ex4data1.mat')
y = data['y']
y[y == 10] = 0 #replace 10s by 0s
X = data['X']
X = np.hstack((np.ones((5000,1)), X))

m = X.shape[0]
lamb = 1

# sample_weights = sio.loadmat('ex4weights.mat')
# theta1 = sample_weights['Theta1'] #delete these lines after the forwardfeed works
# theta2 = sample_weights['Theta2']
epsilon = 0.12 # choosen by the formula given in 
theta1 = np.random.rand(25, 401)*2*epsilon - epsilon
theta2 = np.random.rand(10, 26)*2*epsilon - epsilon
thetaVec = np.hstack((theta1.ravel(), theta2.ravel()))

def sigmoid(z):
    return 1./(1+np.exp(-z))

def cost(thetaVec):
    j=0
    t1 = np.reshape(thetaVec[0:(25*401)], (25, 401))
    t2 = np.reshape(thetaVec[(25*401):], (10,26))
    for i, x in enumerate(X):
        dig = y[i]
        # if dig == 0:
        #     dig = 9
        # else:  #these lines were added incase the weights from the course were to be used
        #     dig = dig-1
        y_local = np.zeros(10)
        y_local[dig] = 1
        a1 = sigmoid(x.dot(t1.T))
        a1 = np.hstack((1, a1)) #attach bias
        a2 = sigmoid(a1.dot(t2.T))
        j = j + np.sum((-1./m)*(y_local*np.log(a2) + (1-y_local)*np.log(1-a2))) 

    j =  j + (float(lamb)/(2*m))*(np.sum(t1.ravel()[1:]**2) + np.sum(t2.ravel()[1:]**2)) #add the regularization term
    if np.isnan(j):
        return np.inf
    else:
        return j

def gradient(thetaVec):
    t1 = np.reshape(thetaVec[0:(25*401)], (25, 401))
    t2 = np.reshape(thetaVec[(25*401):], (10,26))
    a1 = sigmoid(X.dot(t1.T))
    a1wo1 = a1.copy().T #a1 without bias
    a1 = np.hstack((np.ones((5000,1)), a1))
    a2 = sigmoid(a1.dot(t2.T))
    y_local = np.zeros((5000,10))
    for i, digit in enumerate(y):
        y_local[i][digit] = 1
    d2 = a2 - y_local # for the last layer
    d1 = t2[:,1:].T.dot(d2.T) * (a1wo1*(1-a1wo1)) # for the 1st and only hidden layer
    # print 'd2', d2.shape, 'd1', d1.shape

    D1 = d1.dot(sigmoid(X))
    D2 = d2.T.dot(a1)
    # print 'D1', D1.shape, 'D2', D2.shape

    tt1 = np.hstack((np.ones((t1.shape[0],1)), t1[:,1:])) #remove the first element of each theta so that it does not add up to the gradient by regularization
    tt2 = np.hstack((np.ones((t2.shape[0],1)), t2[:,1:]))

    g1 = (D1/m+(tt1*lamb)/m)
    g2 = (D2/m+(tt2*lamb)/m)
    # print g1.shape, g2.shape
    return np.hstack((g1.ravel(), g2.ravel()))

# def numGrad(thetaVec):

# print cost(thetaVec), gradient(thetaVec)

thetaVec = minimize(cost, thetaVec, method='L-BFGS-B', jac=gradient, options={'disp':True, 'gtol':1e-6}).x
np.save('weights.npy', thetaVec)

# ###TEST###
# case = np.random.randint(0, 5001, 80)
# inpt = X[0]
# for i in case:
#     inpt = np.vstack((inpt, X[i]))
# num_cases = inpt.shape[0]
# # thetaVec = np.load('weights.npy')
# t1 = np.reshape(thetaVec[0:(25*401)], (25, 401))
# t2 = np.reshape(thetaVec[(25*401):], (10,26))
# a1 = sigmoid(inpt.dot(t1.T))
# a1 = np.hstack((np.ones((a1.shape[0],1)), a1))
# a2 = sigmoid(a1.dot(t2.T))
# for i, case in enumerate(a2):
#     plt.subplot(1, num_cases, i+1)
#     plt.axis('off')
#     prediction = np.argmax(case)
#     plt.title(prediction)
#     plt.imshow(np.reshape(X[i][1:], (20,20)).T, cmap='gray')
# plt.show()
print 'Done\n'
