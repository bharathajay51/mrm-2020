hours=input("Enter hours:")
h=float(hours)
rph=input("Enter rate per hour:")
r=float(rph)

def computepay(h,r):
    return (h-40)/2

if(h<=40):
    pay=h*r
else:
    p=computepay(h,r)
    pay1=45*r
    pay2=p*r
    pay=pay1+pay2


print(pay)
