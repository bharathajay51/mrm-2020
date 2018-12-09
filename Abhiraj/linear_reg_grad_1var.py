#using gradient descent in 1 variable
import csv
import numpy as np
import matplotlib.pyplot as plt

def calc_cost(m, xs, ys, th):
       return (1.0/(2*m))*(np.sum((xs.dot(th) - ys)**2))
        

with open('ex1data1.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    x_coors = [float(row[0]) for row in reader]
    csvfile.seek(0)
    y_coors = [float(row[1]) for row in reader]
csvfile.close() 

m = len(x_coors)

#scale features
maximum = np.amax(np.array([x_coors]))
minimum = np.amin(np.array([x_coors]))
mean = np.mean(np.array([x_coors]))
x_coors = ((np.array(x_coors)-np.full(m,mean))/(maximum-minimum)).tolist()

maximum = np.amax(np.array([y_coors]))
minimum = np.amin(np.array([y_coors]))
mean = np.mean(np.array([y_coors]))
y_coors = ((np.array(y_coors)-np.full(m,mean))/(maximum-minimum)).tolist()
#scaling done

X = np.transpose(np.array([np.ones(m), np.array(x_coors)]))
y = np.transpose(np.array([y_coors]))


theta = np.zeros((2,1)) #let
alpha = 0.01
precision = 0.00000001

while True:
    old = calc_cost(m, X, y, theta)
    # print alpha * np.array([[ np.sum((X.dot(theta)-y))/m ], [ np.sum((X.dot(theta)-y)*X[:,1])/m ]])
    theta = theta - (alpha * np.array([[ np.sum((X.dot(theta)-y))/m ], [ np.sum((X.dot(theta)-y)*np.transpose(np.array([X[:,1]])))/m ]]))
    print calc_cost(m,X,y,theta)
    print theta
    if (abs(old - calc_cost(m,X,y,theta))/old)*100 < precision:
        break

plt.plot(x_coors, y_coors, 'r.')
plt.plot(x_coors, X.dot(theta), 'b')
plt.show()
