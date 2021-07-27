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
		left = NULL;
		right= NULL;
	}
};

node* build_my_tree()
{
	int d;
	cin>>d;

	if(d==-1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left= build_my_tree();
	root->right= build_my_tree();
	return root;
}
void preorder_print(node* root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	preorder_print(root->left);
	preorder_print(root->right);
}

void inorder_print(node* root)
{
	if(root==NULL)
	{
		return ;
	}
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
}
void postorder_print(node* root)
{
	if(root==NULL)
	{
		return ;
	}
	postorder_print(root->left);
	postorder_print(root->right);
	cout<<root->data<<" ";
}


int main()
{
  node* root = build_my_tree();
  // preorder_print(root);
  // inorder_print(root);
  postorder_print(root);
}