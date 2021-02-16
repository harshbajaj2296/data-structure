#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    node (int n)
    {
        this->data=n;
        left=right=NULL;
    }
};
typedef node*ptr;
void insert(ptr &l,int n)
{
    if(l==NULL)
    l=new node(n);
    if(n<l->data)
    insert(l->left,n);
    else if (n>l->data)
    insert(l->right,n);
}
void inorder (ptr &l)
{
	if(l==NULL)
	return;    
	inorder(l->left);
	cout<<l->data<<" ";
	inorder(l->right);		
}
//wrong approach
int check_bst1(ptr l)
{
    if(l==NULL)
    return 1;
    else if((l->left==NULL||l->left->data<l->data)&&(l->right==NULL||l->right->data>l->data))
    return 1;
    else
    return 0;
    return(check_bst1(l->left)&&check_bst1(l->right));

}
//CORRECT APPROACH
int check_bst(ptr l,int min ,int max)
{
    if(l==NULL)
    return 1;
    return(l->data>min&&l->data<max&&check_bst(l->left,min,l->data)&&check_bst(l->right,l->data,max));
}
//EFFECIENT APPROACH
bool check(ptr l,int prev)
{
    if(l==NULL)
    return true;
    if((check(l->left,prev))==false)
    return false;
    if(l->data<prev)
    return false;
    prev=l->data;
    return(check(l->right,prev));
}
int main()
{
ptr p1=NULL;
insert(p1,4);
insert(p1,2);
insert(p1,3);
insert(p1,1);
insert(p1,7);
insert(p1,6);
insert(p1,8);
insert(p1,5);
insert(p1,9);
inorder(p1);
cout<<endl;
//p1->right->data=2;
//p1->left->data=55;
inorder(p1);
cout<<check_bst(p1,INT_MIN,INT_MAX)<<endl;
cout<<check(p1,INT_MIN);

}