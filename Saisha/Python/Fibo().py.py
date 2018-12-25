def fibo(num):
    a=0
    b=1
    if(num==1):
        print('0')
    elif(num==2):
        print('1')
    else:
        for i in range(2,n):
            c=a+b
            a=b
            b=c
        print(c)


num=input('Enter value of n:')
n=int(num)
x=fibo(n)
