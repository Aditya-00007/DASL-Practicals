/* A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.*/

#include<iostream>
using namespace std;


struct node{
	string data;
	node* child[10];
	
	
	node(string val)
	{
		data=val;
		for (int i = 0; i < 10; i++)
		{
			child[i]=nullptr;
		}
	}
};

struct node* create(int depth=0)
{
	string name;
	if(depth==0)
		cout<<"Enter the name of the BOOK:"<<endl;
	else if(depth==1)
		cout<<"Enter the name of the Chapter:"<<endl;
	else if(depth==2)
		cout<<"Enter the name of the topic:"<<endl;
	else
		cout<<"Enter the name of the Subtopic:"<<endl;
	cin>>name;
	node* newnode=new node(name);
	int no;
	cout<<"Enter the number of the childs:"<<endl;
	cin>>no;
	for (int i = 0; i < no; i++)
	{
		newnode->child[i]=create(depth+1);
	}
	return newnode;
}

void display(struct node* root,int depth=0)
{
	if(root==nullptr)
		return;
	for (int i = 0; i < depth; i++)
	{
		cout<<"    ";
		
	}
	if(depth==0)
		cout<<"******************Book**************"<<endl;
	
	cout <<"|--" << root->data << endl;
	for (int i = 0; i < 10; i++)
	{
		display(root->child[i],depth+1);
		
	}
	
}

int main()
{ 	cout<<"\n***********DASL PRACTICAL NO: 03 ************\n";
	cout<<"\n********TREE OPERATION***********************\n";
	node* root;
do{
	cout<<"\n 1:Insert\n 2:Display\n3:Exit\n";
	int ch;
	cout<<"\nEnter the choice : \n";
	cin>>ch;

	if(ch==1)
		root=create();
	else if(ch==2)
		display(root);
	else if(ch==3){
		cout<<"\n Thank you\n";
		break;}
	else
		cout<<"Invalid choice!"<<endl;}while(true);

	return 0;
}