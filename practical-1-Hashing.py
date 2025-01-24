print("\n***********DASL PRACTICAL NO: 02 ************\n")
print("********SET OPERATION***********************\n")
n=int(input("Enter the total numbers clients : "))
list=[]
def accept(n): #to accept telephone numbers
	for i in range(0,n):
		x=int(input("Enter the telephone number: "))
		list.append(x)

accept(n)	

print("\n**Note please ensure that the size of Hash greater than total number of elements ** is  \n")
s=int(input("Enter the Size of hash table : "))




def linear(list,s):
		tele=[-1]*s #initialize hash table
		for i in range(0,n):
			a=list[i]%s
			while(tele[a]!=-1):
				a=(a+1)%s
			tele[a]=list[i]
				
			
		print("Hash table for linaer probing :",tele)

def quadratic(list,s):
		tele=[-1]*s #initialize hash table
		for i in range(0,n):
			a=list[i]%s
			j=1
			while(tele[a]!=-1):
				a=(a+(j**2))%s
				j=j+1
			tele[a]=list[i]
				
			
		print("Hash table for Quadratic probing:",tele)
		
def Double(list,s):
		tele=[-1]*s #initialize hash table
		for i in range(0,n):
			a=list[i]%s
			b=list[i]%(s-3)+1
			j=1
			while(tele[a]!=-1):
				a=(a+j*b)%s
				j=j+1
			tele[a]=list[i]
				
			
		print("Hash table for Double Hashing :",tele)

		
			
	
	
print("1:linear\n 2:quadratic\n 3:Double\n 4:Exit\n")

while(True):
	ch=int(input("Enter the choice : "))

	if(ch==1):
		linear(list,s)
	elif(ch==2):
		quadratic(list,s)
	elif(ch==3):
		Double(list,s)
	elif(ch==4):
		print("thank you ! ")
		break
	else:
		print("Invalid choice!")
	
	
	
	
	
	
	
	
