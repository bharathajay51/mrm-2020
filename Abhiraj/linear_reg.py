#using normal equation in 1 variable
import numpy as np
import csv
import matplotlib.pyplot as plt

with open('ex1data1.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    x_coors = [float(row[0]) for row in reader]
    csvfile.seek(0)
    y_coors = [float(row[1]) for row in reader]
csvfile.close()

m = len(x_coors)
X = np.array([np.ones((m)), np.array(x_coors)])
X = np.transpose(X)

y = np.transpose(np.array([y_coors]))
theta = ((np.linalg.pinv(np.transpose(X).dot(X))).dot(np.transpose(X))).dot(y)

plt.plot(x_coors, y_coors, 'r.')
plt.plot(x_coors, X.dot(theta), 'b')
plt.show()
