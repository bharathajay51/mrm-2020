#using normal equations (2 characters)
import csv
import numpy as np
import matplotlib.pyplot as plt

with open('ex1data2.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    x1_coors = [float(row[0]) for row in reader]
    csvfile.seek(0)
    x2_coors = [float(row[1]) for row in reader]
    csvfile.seek(0)
    y_coors = [float(row[2]) for row in reader]
csvfile.close()

m = len(x1_coors)
X = np.array([np.ones(m), np.array(x1_coors), np.array(x2_coors)])
X = np.transpose(X)

y = np.transpose(np.array([y_coors]))

theta = (np.linalg.pinv(np.transpose(X).dot(X)).dot(np.transpose(X))).dot(y)
print ("Theta0 = %f\nTheta1 = %f\nTheta2 = %f\n" % (theta[0], theta[1], theta[2]))
