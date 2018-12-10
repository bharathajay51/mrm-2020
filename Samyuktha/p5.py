score=input("Enter the score")
try :
    sc=float(score)
    if sc>=0 and sc<=1:
        if sc<0.6:
            print("F")
        elif sc>=0.6 and sc<0.7:
            print("D")
        elif sc>=0.7 and sc<0.8:
            print("C")
        elif sc>=0.8 and sc<0.9:
            print("B")
        else:
            print("A")
    else:
        print("PLEASE ENTER A VALUE WITHIN RANGE")
        exit()
except :
    print("PLEASE ENTER A VALID INPUT")
    exit()
