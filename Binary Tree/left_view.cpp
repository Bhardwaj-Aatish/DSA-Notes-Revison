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
void left_view_bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
    	int n= q.size();
    	for(int i =0;i<n;i++)
    	{
    		node* temp = q.front();
    		q.pop();
            // node present at 0th index of queue is the leftmost node of out tree at a particular level 
    		if(i==0)
    		{
    			cout<<temp->data<<endl;
    		}
    		if(temp->left!=NULL)
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

void left_view_dfs_helper(node* root, int level , int &maxlevel)
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
      // for left view we are calling left first 
      // so that when level increase by maxlevel then leftmost node will the one to be printed
      left_view_dfs_helper(root->left, level+1, maxlevel);
      left_view_dfs_helper(root->right, level+1, maxlevel);
}
void left_view_dfs(node* root)
{
	int maxlevel = -1;
	int level =0;
	left_view_dfs_helper(root, level   , maxlevel);
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
    left_view_bfs(root);
    left_view_dfs(root);

}





import React from "react";
import Typewriter from "typewriter-effect";

function Type() {
  return (
    <Typewriter
      options={{
        strings: [
          "Developer",
          "Deep Learning Engineer",
          "MERN Stack Developer",
          "Open Source Contributor",
        ],
        autoStart: true,
        loop: true,
        deleteSpeed: 50,
      }}
    />
  );
}

export default Type;