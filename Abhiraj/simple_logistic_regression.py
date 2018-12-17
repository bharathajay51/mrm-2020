# simple logistic regression in 2 variables without regularization
import csv
import numpy as np
import matplotlib.pyplot as plt

def sigmoid(z):
    a = []
    for ele in z:
         a.append(1/(1+pow(np.e, (-1*ele))))
    return np.array(a)

def cal_cost(theta, X, y, m):
    term1 = (np.transpose(y)).dot(np.log(sigmoid(np.transpose(np.transpose(theta).dot(np.transpose(X))))))
    term2 = (np.ones(m)-np.transpose(y)).dot(np.log(np.ones(m)-sigmoid(np.transpose(np.transpose(theta).dot(np.transpose(X))))))
    return (float(-1)/m)*(term1+term2)

with open('ex2data1.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    x1_coors = [float(row[0]) for row in reader]
    csvfile.seek(0)
    x2_coors = [float(row[1]) for row in reader]
    csvfile.seek(0)
    y_coors = [float(row[2]) for row in reader]
csvfile.close()

m = len(x1_coors) #number of training sets
n = 2 #number of characters

#normalize the dataset
mean = np.mean(x1_coors)
x1_coors = ((np.array(x1_coors) - np.full(m, mean)) / (np.amax(x1_coors) - np.amin(x1_coors))).tolist()
mean = np.mean(x2_coors)
x2_coors = ((np.array(x2_coors) - np.full(m, mean)) / (np.amax(x2_coors) - np.amin(x2_coors))).tolist()


X = np.transpose(np.array([np.ones(m), x1_coors, x2_coors]))
y = np.transpose(np.array(y_coors))

# plt.subplot(211)
#plot the data
for i, ele in enumerate(y):
    if ele == 0:
        plt.plot(X[i,1], X[i,2], 'gx')
    else:
        plt.plot(X[i,1], X[i,2], 'k^')


theta = np.transpose(np.zeros(n+1)) #let

alpha = 0.01
precision = 0.000001
last = cal_cost(theta, X, y, m)

print 'Processing...' #a verbose feedback

while True:
    theta = theta - (alpha/m)*(np.transpose((sigmoid(np.transpose(theta).dot(np.transpose(X))) - np.transpose(y)).dot(X)))
    if abs(last-cal_cost(theta, X, y, m)) < precision:
        break
    last = cal_cost(theta, X, y, m)
    print theta, last


# plt.subplot(212)
# print X[:,0:2]

plt.plot(X[:,1], np.transpose(theta[0:2]).dot(np.transpose(X[:,0:2]))/(-1*theta[2]), 'b')
plt.show()
