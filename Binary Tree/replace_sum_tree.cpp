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
void preorder_print(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder_print(root->left);
	preorder_print(root->right);
}
int replacesum(node* root)
{
	if(root==NULL)
	{
	   return 0;	
	}
	int ls= replacesum(root->left);
	int rs= replacesum(root->right);
	root->data= root->data + ls+ rs;
	return root->data;
}
int main()
{
//	             1                                28
//	           /   \                            /     \
//	          2      3           =>            11       16
//           / \    / \                      /   \     /  \
//          4   5  6   7                    4     5    6   7 
// 
	node* root= new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left =new node(6);
    root->right->right= new node(7);
    preorder_print(root);
    replacesum(root);
    cout<<endl;  
    preorder_print(root);
    return 0;
}