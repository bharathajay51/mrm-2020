name = input("Enter file:")

handle = open(name)
counts=dict()
for line in fh:
    if line.startswith('From'):

        lst=line.split()
        word=lst[0]
        if word.endswith(':'):

            continue
        w=lst[1]

        counts[w]=counts.get(w,0)+1
bigword=None
bigcount=None
for key,value in counts.items():
    if bigcount is None or value>bigcount:
        bigword=key
        bigcount=value
print(bigword,bigcount)
