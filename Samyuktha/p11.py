fname = input("Enter file name: ")
fh = open(fname)
lst = list()
lst1=list()
for line in fh:
    lst=line.split()
    l=len(lst)
    n=range(l)
    for i in n:
        if lst[i] not in lst1:
            lst1.append(lst[i])
lst1.sort()
print(lst1)
