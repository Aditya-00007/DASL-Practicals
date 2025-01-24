
set1=[] #first set
set2=[] #second set
set3=[] #intersection set
set4=[] #union set
set5=[] #diffrence set


def insert():
    print(" 1:set1 \n 2:set2\n")
    st=int(input("Enter the choice: "))
    n=int(input("Enter the Size of the Set: "))
    for i in range(0,n):
        x = int(input("Enter the Element: "))
        if st == 1:
            set1.append(x)
        elif st == 2:
            set2.append(x)
        else:
            print("Invalid choice!")

def display():
    print(" 1:set1 \n 2:set2\n")
    st=int(input("Enter the choice: "))
    if (st == 1):
        print("Set1 =", set1,"\n")
    elif (st == 2):
        print("Set2 =", set2,"\n")
    else:
        print("Invalid choice!")
        
def rem():
    print(" 1:set1 \n 2:set2\n")
    st=int(input("Enter the choice: "))
    z=int(input("Enter the Element to Delete: "))
    if (st == 1):
        if(z not in set1):
            print("element z not found")
        else:
            set1.remove(z)
    elif (st == 2):
        if(z not in set2):
            print("element z not found")
        else:
            set2.remove(z)
    else:
        print("Invalid choice!")

	
def size():
    print(" 1:set1 \n 2:set2\n")
    st=int(input("Enter the choice: "))
    if (st == 1):
        print("Size of Set1 =", len(set1))
    elif (st == 2):
        print("Size of Set2 =", len(set2))
    else:
        print("Invalid choice!")
        
def intrst():
    for i in set1:
        if(i in set2):
            set3.append(i)
  
    print("Intersection =", set3)

def union():
    for i in set1:
        set4.append(i)
    for j in set2:
        if(j not in set1):
            set4.append(j)

    print("Union =", set4)

def diff():
    print(" 1:set1 - set2 \n 2:set2 - set1\n")
    st = int(input("Enter the choice: "))
    if st == 1:
        set5 = list(set(set1) - set(set2))  
        print("set1 - set2 =", set5)
    elif st == 2:
        set5 = list(set(set2) - set(set1))  
        print("set2 - set1 =", set5)
    else:
        print("Invalid choice!")

def subset():
    set6 = list(set(set1) & set(set2)) 
    if(set6 == set1):
        print("set1 is subset of set2")       
    elif(set6 == set2):
        print("set2 is subset of set1")  
    else:
        print("No set is subset of any")

	
def contain():
    print(" 1:set1 \n 2:set2\n")
    st=int(input("Enter the choice: "))
    z=int(input("Enter the Element to check: "))
    if(st == 1):
        if(z not in set1):
            print("element" ,z," not found")
        else:
            print("element",z,"Contained by set set1")  
    elif(st == 2):
        if(z not in set2):
            print("element",z," not found")
        else:
            print("element ",z," Contained by set set1")
    else:
        print("Invalid choice!")



# main progarm
print("\n***********DASL PRACTICAL NO: 02 ************\n")
print("********SET OPERATION***********************\n")

while(True):
	print(" 1:Insert\n 2:Display\n 3:Remove\n 4:Size\n 5:union\n 6:Intersection \n 7:Diffrence \n 8:Subset \n 9:Contain\n  10:Exit\n")
	ch=int(input("Enter the choice : "))

	if(ch==1):
		insert()
	elif(ch==2):
		display()
	elif(ch==3):
		rem()
	elif(ch==4):
		size()
	elif(ch==5):
		union()
	elif(ch==6):
		intrst()
	elif(ch==7):
		diff()
	elif(ch==8):
		subset()
	elif(ch==9):
		contain()
	elif(ch==10):
		print("thank you ! ")
		break
	else:
		print("Invalid choice!")
