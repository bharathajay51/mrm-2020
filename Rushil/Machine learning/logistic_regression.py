from numpy import *
import numpy as np
import math
import csv

ar = genfromtxt("ex2data1.csv", delimiter = ',')
m = len(ar)
n = len(np.transpose(ar))

def sigmoid(a,b,c,x1,x2):
    
    S = 1/(1+(math.exp((-(a+b*x1+c*x2)))))
    return S


def grad(a,b,c,ar,alpha):

    t1 = a
    t2 = b
    t3 = c
    p = 0.0
    q = 0.0
    r = 0.0
    for i in range(0,m):
        x1 = ar[i,0]/100
        x2 = ar[i,1]/100
        y = ar[i,2]
        p = p + (sigmoid(a,b,c,x1,x2)-y)
        q = q + (sigmoid(a,b,c,x1,x2)-y)*x1
        r = r + (sigmoid(a,b,c,x1,x2)-y)*x2
        
    t1 = a - alpha*p
    t2 = b - alpha*q
    t3 = c - alpha*r

    a = t1
    b = t2
    c = t3
    return a,b,c
def cost(a,b,c,ar):
    m = len(ar)
    J = 0
    for i in range(0,m):
        x1 = ar[i,0]/100
        x2 = ar[i,1]/100
        y = ar[i,2]
        J = J - (1/m)*((y*math.log(sigmoid(a,b,c,x1,x2))+(1-y)*(math.log(1-sigmoid(a,b,c,x1,x2)))))
    #J = J/m
    return J


##############################           MAIN FUNCTION                 ########################################################

alpha = 0.01
a = 0.0
b = 0.0
c = 0.0
test = cost(0,0,0,ar)
print("test: ",test)
while True:
    old = cost(a,b,c,ar)
    a,b,c = grad(a,b,c,ar,alpha)
    #print("a: ",a)
    #print("b: ",b)
    #print("c: ",c)
    new = cost(a,b,c,ar)
    if new>old:
        break
print("final values: ")
print(a)
print(b)
print(c)
print(new)
#print(test)










    
    
