#include<iostream>
#include<algorithm>
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
class pair1{
public:
	int height;
	int diameter;
	pair1()
	{
		height= 0;
		diameter= 0;
	}
};
int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh = height(root->left);
	int rh= height(root->right);
	int ans = max(lh, rh) + 1;
	return ans;
}
int diameter_of_tree(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh= height(root->left);
    int rh= height(root->right);
    int op1= lh + rh+1 ;
    // counting below tree diameter as 5 
    // if diameter is 4 then op1= lh + rh would work fine 
    int op2= diameter_of_tree(root->left);
    int op3= diameter_of_tree(root->right);
    int ans = max(op1,max(op2,op3));
    return ans;
}
pair1 optimised_diameter(node* root)
{
	 pair1 p;
	 if(root==NULL)
	 {
	 		p.height= 0;
	 		p.diameter=0;
	 		return p;
	 }
	 pair1 left = optimised_diameter(root->left);
	 pair1 right = optimised_diameter(root->right);
	 int op1= left.height+ right.height +1;
	 int op2 = left.diameter;
	 int op3 = right.diameter;
	 pair1 ans;
	 ans.height= max(left.height,right.height)+1;
	 ans.diameter= max(op1,max(op2,op3));
	 return ans;
}
// another approach without pair
// apna college code
 int fast_diamater(node* root , int* height)
 {
 	if(root==NULL)
 	{
 		*height= 0;
 		return 0;
 	}
 	int lh =0, rh= 0;
 	int op2= fast_diamater(root->left, &lh);
 	int op3= fast_diamater(root->right, &rh);
 	int op1 = lh+ rh+ 1;
 	*height= max(lh, rh)+1;
 	int ans = max(op1,max(op2,op3));
 	return ans;
 }
int main()
{
//	             1
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
    int height=0;
    cout<<diameter_of_tree(root)<<endl;
    // pair1 ans = optimised_diameter(root);
    // cout<<ans.height<<"  "<<ans.diameter<<endl;
    // cout<<fast_diamater(root,&height)<<endl;
    return 0;
}