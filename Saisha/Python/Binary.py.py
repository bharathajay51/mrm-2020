a=list()
num=input('Enter number of elements:')
n=int(num)
print('Enter numbers into array:')
binary=0
place=1
for i in range(n):
    num1= input()
    a.append(int(num1))

for i in range(n):
    binary(a[i])


def binary(n):
    if n>1:
        binary(n/2)
    print(n%2)
