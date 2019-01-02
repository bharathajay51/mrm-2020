#trying to use scipy optimize here
import numpy as np
import scipy.io as sio
import matplotlib.pyplot as plt
from scipy.optimize import minimize

lamb = 2

def sigmoid(z):
    return 1/(1+np.exp(-z))

def h(X, theta):
    return sigmoid(np.sum(theta*X, axis=1)[:, np.newaxis])

def cost(theta, X, y):
    co = (-1./m)*(np.sum((1-y)*np.log(1-h(X, theta))) + np.sum(y*np.log(h(X, theta)))) + (float(lamb)/(2*m))*(np.sum(theta[1:]**2))
    if np.isnan(co.ravel()[0]):
        return np.inf
    else:
        return co.ravel()[0]

def grad(theta, X, y):
    g = (1./m)*(X.T.dot(h(X, theta)-y)) + (float(lamb)/m)*np.vstack(([[0]], theta[1:][:,np.newaxis]))
    return g.flatten()

######## LOAD DATA ########
X = sio.loadmat('ex3data1.mat')['X']
y = sio.loadmat('ex3data1.mat')['y']

X = np.hstack((np.ones((5000, 1)), X))

y[y == 10] = 0 #replace all the 10s by 0 as we i am not using matlab/octave

theta = np.zeros((10, 401))

m = X.shape[0]
###########################

#arrange a loop so that the 10 classifiers are trained 
for i in range(10):
    print "Processing %d... " % i
    y_temp = y.copy()
    y_temp[y_temp != i] = 11
    y_temp[y_temp == i] = 1
    y_temp[y_temp == 11] = 0
    theta[i] = minimize(cost, np.array(theta[i]), args=(X, y_temp), method='BFGS',jac=grad, options={'disp':True, 'gtol':1e-6}).x
    

#testing the classifiers
test = 80
inpt = np.random.choice(5000, test, replace=False)
wrong = 0
for i, ele in enumerate(inpt.tolist()):
    plt.subplot(4, 20, i+1)
    plt.axis('off')
    actual = y[ele, 0]
    prediction = np.argmax(h(np.array([X[ele,:]]), theta))
    if actual != prediction:
        wrong = wrong + 1
    plt.title(prediction)
    plt.imshow(np.reshape(X[ele,1:], (20,20)).T, cmap='gray')
print '\nTotal: %d\nCorrect: %d\nWrong: %d\nAccuracy: %d\n' % (test, test-wrong, wrong, (float(test-wrong)/test)*100)
plt.show()

# input("Press enter to save the trained model, ctrl-c to exit")
np.save('thetasscio.npy', theta)
