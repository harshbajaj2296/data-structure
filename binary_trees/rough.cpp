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
int sum(ptr l1,ptr l2)
{
    if(l1==NULL&&l2==NULL)
    return 1;
    if((l1==NULL&&l2!=NULL)||(l1!=NULL&&l2==NULL))
    return 0;
    return(l1->data==l2->data&&sum(l1->left,l2->right)&&sum(l1->right,l2->left));     
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
    cout<<sum(root,root);
}