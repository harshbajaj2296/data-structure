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
ptr min(ptr l)
{
    while(l->left!=NULL)l=l->left;
    return l;
}
ptr deletion(ptr &l,int n)
{
    if(l==NULL)
    return l;
    else if(n<l->data)
    deletion(l->left,n);
    else
    deletion(l->right,n);
    if(l->data==n)
    {
        //CASE:1
        if(l->left==NULL&&l->right==NULL)
        {
            delete l;
            l=NULL;
        }
        //CASE:2
        else if(l->left!=NULL&&l->right==NULL)
        {
            l->data=l->left->data;
            ptr temp =l->left;
            l->left=l->left->left;
            delete temp;
        }
        else if(l->right!=NULL&&l->left==NULL)
        {
            l->data=l->right->data;
            ptr temp =l->right;
            l->right=l->right->right;
            delete temp;
        }
        // CASE:3
        else
        {
            ptr temp=min(l->right);
            int n=temp->data;
            deletion(l,temp->data);
            l->data=n;
        }
    }
    return l;
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
deletion (p1,4);
inorder(p1);
cout<<endl;
}