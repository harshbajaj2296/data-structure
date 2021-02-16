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
ptr lca(ptr l,int a,int b)
{
    if(l->data>a&&l->data>b)
    return(lca(l->left,a,b));
    else if(l->data<a&&l->data<b)
    return(lca(l->right,a,b));
    else
    return(l);
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
ptr c= lca(p1,9,3);
cout<<c->data;
cout<<endl;
}