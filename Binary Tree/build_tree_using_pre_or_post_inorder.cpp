#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int value)
	{
		data = value;
		left= NULL;
		right= NULL;
	}
};
int search(int pre[], int in[], int s, int e ,int curr)
{
	for(int i = s;i<=e;i++)
	{
		if(curr==in[i])
		{
			return i;
		}
	}
	return -1;
}
node* build_pre_in( int pre[], int in[], int s , int e)
{
	static int i =0;
    if(s>e)
    {
    	return NULL;
    }
	int curr = pre[i];
	i++;
	node* root = new node(curr);
	if(s==e)
	{
		return root;
	}
	int pos= search(pre, in, s, e, curr);
	root->left= build_pre_in(pre, in , s, pos-1);
	root->right= build_pre_in(pre, in, pos+1, e);
	return root;
}
int search_pos(int pos[], int in[], int s, int e, int curr)
{
	for(int y= s;y<=e;y++)
	{
		if(in[y]==curr)
		{
			return y;
		}
	}
	return -1;
}
node* build_post_in(int post[], int in[], int s , int e)
{
    static int x = e;
    if(s>e)
    {
    	return NULL;
    }
    int curr= post[x];
    x--;
    node* root = new node(curr);

    int pos = search_pos(post, in, s, e, curr);
    root->right= build_post_in(post, in , pos+1, e);
    root->left= build_post_in(post, in , s, pos-1);
    return root;
}
void print_inorder( node* root)
{
	if(root==NULL)
	{
		return;
	}
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);

}
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
int main()
{
	int pre[]={1,2,3,4,8,5,6,7};
	int in[]={3,2,8,4,1,6,7,5};
	int post[]={3,8,4,2,7,6,5,1};
	int n= sizeof(in)/sizeof(int);
	node* root = build_pre_in(pre, in , 0 , n-1);
	node* root2= build_post_in(post, in , 0 , n-1);
	print_inorder(root);
	cout<<endl;
	print_inorder(root2);

	return 0;
}