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
int symmetry(ptr l1,ptr l2)
{
    if(l1==NULL&&l2==NULL)
    return 1;
        if((l1==NULL&&l2!=NULL)||(l2==NULL&&l1!=NULL)||(l1->data!=l2->data))
        return 0;
        int b=symmetry(l1->left,l2->left);
        if(b==1)
        return(symmetry(l1->right,l2->right));
        else
        return 0;
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
    ptr root1=NULL;
    root1= new node(2);
    root1->left = new node(7); 
	root1->right = new node(5); 
	root1->left->right = new node(6); 
	root1->left->right->left = new node(1); 
	root1->left->right->right = new node(11); 
	root1->right->right = new node(9); 
	root1->right->right->left = new node(4);
    cout<<symmetry(root,root1);
}