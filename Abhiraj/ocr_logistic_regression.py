import numpy as np
import scipy.io as sio
import matplotlib.pyplot as plt

lamb = 3
alpha = 0.1

def sigmoid(z):
    return 1/(1+np.exp(-z))

def h(X, theta, b):
    return sigmoid(np.sum(theta*X, axis=1)[:, np.newaxis] + b)

def cost(X, theta, y, m, b):
    return (-1/m)*(np.sum((1-y)*np.log(1-h(X, theta, b)))+ np.sum(y*np.log(h(X, theta, b)))) + (lamb/(2*m))*(np.sum(theta**2))

def gradient(X, theta, y, m, b):
   gb = (alpha/m)*(np.sum(h(X, theta, b) - y))
   g = (alpha/m)*(np.sum(((h(X, theta, b) - y)*X), axis=0)) + (lamb/m)*theta
   return gb, g

def gradientDescent(X, theta, y, m, b, iter_num): #iter_num just for making the program verbose
    last = cost(X, theta, y, m, b)
    iteration = 10000
    precision = 0.000001
    while True:
        last = cost(X, theta, y, m, b)
        gradb, grad = gradient(X, theta, y, m, b)
        b = b - gradb
        theta = theta - grad
        print last, '\tClassifier: ', iter_num
        if (last - cost(X, theta, y, m, b)) < precision or iteration == 0:
            break
        iteration = iteration - 1    
    return b, theta


# Import data here
matdata = sio.loadmat('ex3data1.mat')
X = matdata['X']
y = matdata['y']

bias = np.zeros((10,1))
theta = np.zeros((10,400))

y[y == 10] = 0 #replace all the 10s by 0 as we i am not using matlab/octave

m = X.shape[0]

#arrange a loop so that the 10 classifiers are trained 
for i in range(10):
    print "Processing %d... " % i
    y_temp = y.copy()
    y_temp[y_temp != i] = 11
    y_temp[y_temp == i] = 1
    y_temp[y_temp == 11] = 0
    bias[i], theta[i] = gradientDescent(X, np.array([theta[i]]), y_temp, m, np.array([bias[i]]), i)


#testing the classifiers
test = 80
inpt = np.random.choice(5000, test, replace=False)
wrong = 0
for i, ele in enumerate(inpt.tolist()):
    plt.subplot(4, 20, i+1)
    plt.axis('off')
    actual = y[ele, 0]
    prediction = np.argmax(h(np.array([X[ele,:]]), theta, bias))
    if actual != prediction:
        wrong = wrong + 1
    plt.title(prediction)
    plt.imshow(np.reshape(X[ele,:], (20,20)).T, cmap='gray')
print '\nTotal: %d\nCorrect: %d\nWrong: %d\nAccuracy: %d\n' % (test, test-wrong, wrong, (float(test-wrong)/test)*100)
plt.show()

# input("Press enter to save the trained model, ctrl-c to exit")
np.save('thetas.npy', theta)
np.save('bias.npy', bias)
