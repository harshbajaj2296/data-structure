#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
    node(int n)
    {
        this->data=n;
        left=right=NULL;
    }
};
typedef node* ptr;
int lca(ptr l,int a,int b)
{
	if(l==NULL)
	return 0;
    if(l->data==a||l->data==b)
    return l->data;
    int left=lca(l->left,a,b);
    int right=lca(l->right,a,b);
    if(left&&right)
    return(l->data);
    return(left?left:right);
}    
int main ()
{
    ptr root=NULL;
    root= new node(2);
    root->left = new node(7); 
	root->right = new node(5); 
	root->left->right = new node(6); 
	root->left->right->left = new node(1); 
	root->left->right->right = new node(11); 
	root->right->right = new node(9); 
	root->right->right->left = new node(4);
    int a=4,b=1;
  cout<<lca(root,a,b);
}