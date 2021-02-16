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
int sum(ptr l,int sum1)
{
    if(l==NULL)
    return 0;
    return(sum1==0||sum(l->left,sum1-l->data)||(sum(l->right,sum1-l->data)));    
    
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
    cout<<sum(root,16);
}