avg=0
x=0
count=0
array=[]
fname = input("Enter file name: ")
fh = open(fname)
for line in fh:
    line=line.strip()
    if not line.startswith("X-DSPAM-Confidence:"):
        continue
    else:
        index=line.find(':')
        line1=line[index+1:]
        f=float(line1)
        x=x+f
        count=count+1

avg=x/count
print('Average spam confidence:',avg)  
