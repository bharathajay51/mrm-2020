from numpy import *
import math
import csv

def h(nemo0,nemo1,x):
    return (nemo0+nemo1*x)

def cost(nemo0,nemo1,ar):
    m = len(ar)
    c = 0.0
    c = 0.0
    for i in range(0,len(ar)):
        c = c + (nemo0 + nemo1*ar[i,0] - ar[i,1])**2
    c = c/(2*m)
    return c

def grad(nemo0,nemo1,ar):
    m = len(ar)
    t1 = 0
    t2 = 0
    for k in range(0,m):
        t1 = t1 + nemo0 + nemo1*ar[k,0]-ar[k,1]
    for j in range(0,m):
        t2 = t2 + (nemo0+nemo1*ar[j,0]-ar[j,1])*ar[j,0]
    
    temp0 = nemo0
    temp1 = nemo1
        
    temp0 = (nemo0-(alpha/m)*t1)
    temp1 = (nemo1-(alpha/m)*t2)

    nemo0 = temp0
    nemo1 = temp1
    return nemo0,nemo1
        
################       MAIN FUNCTION         #####################

ar = genfromtxt("ex1data1.csv", delimiter = ',')
alpha = 0.001
precision = 0.0000000001
nemo0 = 1.0
nemo1 = 1.0
i = 0
print("please wait running....")
while True:
    i = i+1
    if i%10000 == 0:
        print("finding nemo.....")
    old = cost(nemo0,nemo1,ar)
    
    nemo0,nemo1 = grad(nemo0,nemo1,ar)
    
    new = cost(nemo0,nemo1,ar)
    
    if new>old:
        break
print ("Final Values: ")
print ("nemo 0: ",nemo0)
print("nemo 1: ",nemo1)
print("cost: ",new)

