#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node* left;
   struct node* right;

   node(int val)
   {
    data=val;
    left=nullptr;
    right=nullptr;
   }
};

struct node* create()
{    int x,ch;
    cout<<"Enter value for node :"<<endl;
    cin>>x;
    node* newnode=new node(x);
    cout<<"Enter choice  for 1:left 2:right node 3:both 4:none "<<endl;
    cin>>ch;
    if (ch==1)
    {
        newnode->left=create();
    }
    else if(ch==2){
        newnode->right=create();
    }
    else if(ch==3){
        newnode->left=create();
        newnode->right=create();
    }
    else
        return newnode;
    //no child
   
    return newnode;
}

void display(struct node* root)
{
    if(root==nullptr)
     return;
    cout<<root->data<<"->";
    display(root->left);
    display(root->right);
    

}
int main()
{
    node* root;
    root=create();
    display(root);


    return 0;
}

