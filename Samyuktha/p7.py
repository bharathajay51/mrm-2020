largest=None
smallest=None

while True:
    num=input("Enter a number: ")
    if num=='done':
        break
    try:
        n=float(num)
    except:
        print("Invalid input")
        continue
    if largest is None:
        largest=n
    elif n>largest:
        largest=n
    if smallest is None:
        smallest=n
    elif n<smallest:
        smallest=n
print("Maximum is",largest)
print("Minimum is",smallest)                 
