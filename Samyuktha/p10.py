
fname = input("Enter file name: ")
fh = open(fname)
r=0
s=0
for line in fh:
    if line.startswith("X-DSPAM-Confidence:") :
        r=r+1
        pos=line.find(':')
        number=line[pos+1:]
        num=number.strip()
        n=float(num)
        s=s+n
print('Average spam confidence:',s/r)
