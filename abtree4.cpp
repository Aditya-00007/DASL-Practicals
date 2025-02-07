/* Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value */

#include<iostream>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;
	
	node(int val)
	{
		data=val;
		left=nullptr;
		right=nullptr;
	}
};


struct node* Insert(struct node* root) {
    int num;
    cout << "Enter the Value of the Node: ";
    cin >> num;
    node* newnode = new node(num);

    if (root == nullptr) {
        return newnode;
    }

    node* curr = root;
    while (true) {
        if (num < curr->data) {
            if (curr->left == nullptr) {
                curr->left = newnode;
                break;
            }
            curr = curr->left;
        } 
        else if (num > curr->data) {
            if (curr->right == nullptr) {
                curr->right = newnode;
                break;
            }
            curr = curr->right;
        } 
        else {  // Duplicate value case
            cout << "Value already exists in the tree!" << endl;
            delete newnode;             
            return root;
        }
    }

    return root;
}

void display(struct node* root)
{
    if(root==nullptr)
    return;
	display(root->left);
    cout<<root->data<<"->";
	display(root->right);
}

int longestPath(node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(longestPath(root->left), longestPath(root->right));
}

void search(struct node* root,int val)
{
    if(root==nullptr)
	{
		cout<<"Not found\n";
		return;
	}
	if(val==root->data)
    	{cout<<"node found!\n";
		return;}
	else if(val<root->data)
		search(root->left,val);
	else if(val>root->data)	
	search(root->right,val);
}
void min(struct node* root)
{  node* curr=root;
    if(root==nullptr)
   {cout<<"Not found\n";
    return;}
	while(curr->left!=nullptr){
		curr=curr->left;
	}
	cout<<"Minimum value:"<<curr->data<<endl;
}

void swap(node* root)
{	if(root==nullptr)
    return;

	node* temp=root->left;
	root->left=root->right;
	root->right=temp;

	swap(root->left);
	swap(root->right);
}

// main progarm
int main(){
struct node* root=nullptr;
cout<<"\n***********DASL PRACTICAL NO: 04 ************\n";
cout<<"\n********BINARY SEARCH TREE OPERATIONS***********************\n";

do{
	cout<<" 1:Insert Node\n 2:Display tree\n 3: Number of nodes in longest path \n 4:Minimum data value  in the tree\n  5:Search a value\n 6:Swap\n 7:Exit\n";
	int ch;
	cout<<"Enter the choice : \n";
	cin>>ch;

	if(ch==1)
		root=Insert(root);
	else if(ch==2)
		{display(root);
		cout<<"NULL"<<endl;}
	else if(ch==3)
		{int total=longestPath(root);
			cout<<"Total number of nodes in longest path is:"<<total<<endl;}
	else if(ch==4)
		min(root);
	else if(ch==5)
		{ int n;
		cout<<"Enter the Node to Search : \n";
		cin>>n;
		search(root,n);}
		
	else if(ch==6)
		swap(root);
	
	else if(ch==7)
		{cout<<"thank you ! \n";
		break;}
	else
		cout<<"Invalid choice!\n";}while(true);
		
		return 0;}

	/*						50
					30				90
				20		40		60		100


		*/
