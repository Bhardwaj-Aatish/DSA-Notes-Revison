#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int val)
	{
		data= val;
		left= NULL;
		right= NULL;
	}
};
class HBpair{
public:
	bool balance;
	int height;
	// HBpair()
	// {
	// 	balance= true;
	// 	height= 0;
	// }
};
HBpair is_balanced(node* root)
{
	HBpair ans;
	if(root==NULL)
	{
		ans.height= 0;
		ans.balance = true;
		return ans;
	}
	HBpair ls= is_balanced(root->left);
	HBpair rs = is_balanced(root->right);
    ans.height= max(ls.height, rs.height)+1;
    if(ls.balance && rs.balance &&  abs(ls.height- rs.height)<=1)
    {
    	ans.balance= true;
    }
    else
    {
    	ans.balance= false;
    }
    return ans;
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
//	             1                         1
//	           /   \                    /     \
//	          2      3                 2       3 
//           / \    / \               /     
//          4   5  6   7             4 
//                                  /
//                                 5 
// tree 1
// node* root= new node(1);
 //    root->left = new node(2);
 //    root->right= new node(3);
 //    root->left->left= new node(4);
 //    root->left->right= new node(5);
 //    root->right->left =new node(6);
 //    root->right->right= new node(7);
	            // tree2
	node*root= new node(1);
	root->left= new node(2);
	root->right= new node(3);
	root->left->left= new node(4);
	root->left->left->left= new node(5);
    preorder_print(root);
    HBpair res = is_balanced(root);
    if(res.balance)
    {
    	cout<<"true";
    }
    else{
    	cout<<"false";
    }
    return 0;
}