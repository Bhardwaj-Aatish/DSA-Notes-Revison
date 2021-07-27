#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data; 
	node* left;
	node* right;
	node(int val)
	{
		data= val;
		left = NULL;
		right= NULL;
	}
};
void print_kth_level(node* root, int level)
{
	if(root== NULL)
	{
		return;
	}
	if(level==1)
	{
		cout<<root->data<<" ";
		return;
	}
	print_kth_level(root->left,level-1);
	print_kth_level(root->right, level-1);

}
int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh= height(root->left);
	int rh= height(root->right);
	int ans = max( lh, rh)+1;
	return ans;
}
void print_all_level( node* root)
{
	if(root==NULL)
	{
		return ;
	}
	int h = height(root);
	for(int i =1;i<=h;i++)
	{
		print_kth_level(root,i);
		cout<<endl;
	}
}
void bfs(node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<node* > q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			cout<<" khatam"<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			node* f= q.front();
			cout<<f->data<<" ";
			q.pop();
			if(f->left!=NULL)
			{
			q.push(f->left);
			}
			if(f->right!=NULL)
			{
			q.push(f->right);
			}
		}
	}

}
int main()
{
	//	          1
//	           /   \
//	          2      3
//           / \    / \
//          4   5  6   7
// 
	node* root= new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left =new node(6);
    root->right->right= new node(7);
    // print_kth_level(root,3);
    // print_all_level(root);
    bfs(root);



    return 0;
}