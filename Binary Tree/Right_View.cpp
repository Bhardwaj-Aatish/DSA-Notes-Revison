#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data= d;
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
void right_view_bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		for(int  i=0;i<n;i++)
		{
			node* temp = q.front();
			q.pop();
			// node present at n-1 of queue is the rightest node of out tree at a particular level 
			if(i==n-1)
			{
				cout<<temp->data<<endl;
			}
			if(temp->left!= NULL)
			{
				q.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
		}
	}

}
void right_view_dfs_helper(node* root, int level , int &maxlevel)
{
      if(root==NULL)
      {
      	return ;
      }
      // when level increase by maxlevel then print that node and updata maxlevel as level
      if(maxlevel< level)
      {
      	cout<<root->data<<" ";
      	maxlevel= level;
      }
      // for right view we are calling right first 
      // so that when level increase by maxlevel then rightest node will the one to be printed
      right_view_dfs_helper(root->right, level+1, maxlevel);
      right_view_dfs_helper(root->left, level+1, maxlevel);
}
void right_view_dfs(node* root)
{
	int maxlevel = -1;
	int level =0;
	right_view_dfs_helper(root, level   , maxlevel);
}
int main()
{

//             1
//          /    \
//         2      3
//       /  \    /  \
//      4    5  6    7 
//
//
	node* root = new node(1);
	root->left= new node(2);
	root->right= new node(3);
	root->left->left= new node(4);
	root->left->right= new node(5);
	root->right->left= new node(6);
	root->right->right= new node(7);

	print_pre(root);
	cout<<endl;
	right_view_bfs(root);
	right_view_dfs(root);

	return 0;
}