import numpy as np
import csv


with open('ex1data2.csv', 'r') as csvfile:

    reader = csv.reader(csvfile)
    x = [float(row[0]) for row in reader]
    csvfile.seek(0)
    y = [float(row[2]) for row in reader]
    csvfile.seek(0)
    x1 = [float(row[1]) for row in reader]

csvfile.close()

print(x)
print(y)

m = len(y)

X = np.array([np.ones(m),x,x1])
X = np.transpose(X)
Y = np.transpose(np.array([y]))
print(X)
print(Y)




T = (np.linalg.pinv(np.transpose(X).dot(X)).dot(np.transpose(X))).dot(y)

print("theta 0: ", T[0])
print("theta 1: ", T[1])
print("theta 2: ", T[2])
