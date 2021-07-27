#include<iostream>
using namespace std;
class node{
public:
	int data; 
	node* left;
	node* right;
	node(int val)
	{
		data = val;
		left= NULL;
		right= NULL;
	}
};

void print_pre(node* root)
{
	if(root==NULL)
    {
    	return;
    }
    cout<<root->data<<" ";
    print_pre(root->left);
    print_pre(root->right);
}
int count(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int c1= count(root->left);
	int c2= count(root->right);
	return(1+ c1 + c2);
}
int sum(node* root)
{
	if(root== NULL)
	{
		return 0;
	}
	int s1= sum(root->left);
	int s2 = sum(root->right);
	int d= root->data;
	return(d+ s1+ s2);
}
int main()
{
    node* root= new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left =new node(6);
    root->right->right= new node(7);

    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;
    print_pre(root);
    return 0;
}