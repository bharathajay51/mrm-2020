#logistic regression regularised in 2 characters
import csv
import numpy as np
import matplotlib.pyplot as plt

def sigmoid(z):
    a = []
    for ele in z:
         a.append(1/(1+pow(np.e, (-1*ele))))
    return np.array(a)

def cal_cost(theta, X, y, m, lamb):
    term1 = (np.transpose(y)).dot(np.log(sigmoid(np.transpose(np.transpose(theta).dot(np.transpose(X))))))
    term2 = (np.ones(m)-np.transpose(y)).dot(np.log(np.ones(m)-sigmoid(np.transpose(np.transpose(theta).dot(np.transpose(X))))))
    return (float(-1)/m)*(term1+term2+lamb*np.sum(theta**2))

def mapFeature(X1, X2):
    degree = 6
    out = np.ones(X1.shape[0])[:,np.newaxis]
    for i in range(1, degree+1):
        for j in range(i+1):
            out = np.hstack((out, np.multiply(np.power(X1, i-j), np.power(X2, j))[:,np.newaxis]))
    return out

with open('ex2data2.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    x1_coors = [float(row[0]) for row in reader]
    csvfile.seek(0)
    x2_coors = [float(row[1]) for row in reader]
    csvfile.seek(0)
    y_coors = [float(row[2]) for row in reader]
csvfile.close()


m = len(x1_coors)
n = 28 #characters

X = np.transpose(np.array([x1_coors, x2_coors]))

X = mapFeature(X[:,0], X[:,1])
y = np.transpose(np.array(y_coors))
# print np.shape(X)
theta = np.transpose(np.zeros(n))
alpha = 0.01
lamb = 1 #lambda value
lambarr = np.full(theta.shape, lamb) #this is a numpy array to batch update theta
lambarr[0] = 0
precision = 0.000001
last = cal_cost(theta, X, y, m, lamb)

print 'Processing...'

while True:
    theta = theta - (alpha/m)*(np.transpose((sigmoid(np.transpose(theta).dot(np.transpose(X))) - np.transpose(y)).dot(X))) - ((alpha/m)*(lambarr*theta)) #modify this equation according to regularization
    if abs(last-cal_cost(theta, X, y, m, lamb)) < precision:
        break
    last = cal_cost(theta, X, y, m, lamb)
    print theta, last

print theta

#to plot the decision boundary come up with a contour on the meshgrid below
for_conX, for_conY = np.meshgrid(np.arange(-1.5, 1.5, 0.1), np.arange(-1.5, 1.5, 0.1))
outfinal = mapFeature(for_conX.flatten(), for_conY.flatten())
for_conZ = sigmoid(np.transpose(theta).dot(np.transpose(outfinal)))
contours = plt.contour(for_conX, for_conY, for_conZ.reshape(for_conX.shape), levels=0.5)
plt.clabel(contours, inline=True)

for i, ele in enumerate(y):
    if ele == 0:
        plt.plot(X[i,1], X[i,2], 'gx')
    else:
        plt.plot(X[i,1], X[i,2], 'k^')

plt.show()

