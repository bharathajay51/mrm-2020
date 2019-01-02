fname = input("Enter file name: ")
fh = open(fname)
lst = list()

for line in fh:
    if line.startswith('From'):
        count=count+1
        lst=line.split()
        word=lst[0]
        if word.endswith(':'):
            c=c+1
            continue
        print(lst[1])
print('There were',count-c,'lines in the file with From as the first word')            
