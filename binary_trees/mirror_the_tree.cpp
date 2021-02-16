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
ptr mirror(ptr l)
{
    if(l==NULL)
    return 0;
     mirror(l->left);
     mirror(l->right);
    ptr d= l->left;
    l->left=l->right;
    l->right=d;
    return l;
}
 void preorder (ptr l)
{
 	if(l==NULL)
 	return;	
cout<<l->data<<" ";
preorder(l->left);	    	
preorder(l->right);
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
    preorder(root);
    cout<<endl;
    ptr d =mirror(root);
     preorder(d);
}