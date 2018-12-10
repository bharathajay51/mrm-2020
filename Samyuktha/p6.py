hours=input("Enter the number of hours worked")
h=float(hours)
rate=input("Enter the rate per hour")
r=float(rate)

def computepay(hrs,rt):
    if(hrs>40):
        gr_pay=(40*rt)+((hrs-40)*1.5*rt)
    else:
        gr_pay=hrs*rt
    return gr_pay

print(computepay(h,r))            
