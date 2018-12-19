sum=0
num=input('Enter value of n:')
n=int(num)

for i in range(1,n+1):
    if i>1:
        for j in range(2,i):
            if i%j==0:
                break
        else:
            sum=sum+i


print('Sum:',sum)
