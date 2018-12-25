a=list()
num=input('Enter number of elements in array:')
n=int(num)
print('Enter years into array:')
for i in range(n):
    num1= input()
    a.append(int(num1))

print('Initial array:',a)


for i in range(n):
    if a[i]%4 == 0:
        if a[i]%100 == 0:
            if a[i]%400 == 0:
                a[i]=0

        else:
            a[i]=0

print('Final array:',a)
