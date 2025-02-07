
/*Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post  
order traversal (non recursive) and then delete the entire tree. */

#include<iostream>
#include<string.h>
using namespace std;

struct node
{
   char data;
   struct node* left;
   struct node* right;

   node(char val)
   {
    data=val;
    left=nullptr;
    right=nullptr;
   }
};

class stk
{

public:
    node* st[20];
    int top;
    stk(){
        top=-1;
    }
    bool isempty(){
        if(top==-1)
            return 1;
        else 
            return 0;
    }
    void push(node* x){
        top++;
        st[top]=x;
    }
    struct node* pop(){
        if(isempty())
            return nullptr;
        
        return st[top--];
        
    
}
};

struct node* expntree()
{   stk s;
    char prefix[100],curr;
    node* n;
    node* n1;
    node* n2;
    node* n3;
    cout<<"Enter the prefix expresssion:"<<endl;
    cin>>prefix;
    int len=strlen(prefix);
    for (int i =len-1; i>=0; i--)
    {
        curr=prefix[i];
        if(isalpha(curr))
            {
                n=new node(curr);
                s.push(n); 
            }
           
        else
            {
                n1=s.pop();
                n2=s.pop();
                n3=new node(curr);
                n3->left=n1;
                n3->right=n2;
                s.push(n3);
            }
    }
    return s.st[s.top];
    

}

void display(node* root)
{
    if(root==nullptr)
        return;
    
    display(root->left);
    display(root->right);
    cout<<root->data<<" ";
        

}

int main()
{   
    cout<<"*************DSAL PRACTICAL NO 5****************"<<endl;
	cout<<"*************Prefix to Postfix expresssion conversion using binary tree********************"<<endl;
	cout<<"\n________________Prepared by ADITYA THETE(48)_______________\n"<<endl;


    node* root;
    root=expntree();
    cout<<"\n--------------------------------------------------"<<endl;
    cout<<"Postorder Expression is : ";
    display(root);
    cout<<endl;
    cout<<"\n--------------------------------------------------"<<endl;
    return 0;
}

