name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
lst=list()
lst1=list()
lst2=list()
counts=dict()


for line in handle:
    if line.startswith('From'):

        lst=line.split()
        word=lst[0]
        if word.endswith(':'):

            continue
        lst1=lst[5].split(':')
        w=lst1[0]

        counts[w]=counts.get(w,0)+1

for key,val in counts.items():
    newtup=(key,val)
    lst2.append(newtup)
lst2=sorted(lst2)
for key,val in lst2:
    print(key,val)
                
