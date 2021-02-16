#include<bits/stdc++.h>
using namespace std;
 struct node
 {
     int data;
     node* left;
     node* right;
     node* sibling;
     node(int n)
     {
         this->data=n;
         left=right=sibling=0;
     }
 };
 typedef node* ptr;
 ptr nextsib(ptr l)
 {
     if(l==NULL)
     return 0;
     if(l->left!=NULL)
     l->left->sibling=l->right;
     if(l->right!=NULL)
     l->right->sibling=l->sibling?l->sibling->left:NULL;
     nextsib(l->left);
     nextsib(l->right);
     return l;
 }
 void level_order(ptr &l)
{
	queue <ptr> q; 
	q.push(l);
	while(!q.empty())
{
	ptr d=q.front();
	q.pop();
	if(d->left!=NULL)
    {
	q.push(d->left);
    d->left->sibling=d->right;	
    }
	if(d->right!=NULL)
	{
        q.push(d->right);
        d->right->sibling=d->sibling?d->sibling->left:NULL;
    }
}
    cout<<l->left->right->left->sibling->data<<"sib";

}
void preorder (ptr l)
{
	if(l==NULL)
	return;
	    
	if(l->sibling!=NULL)
	    	cout<<l->sibling->data<<" ->";
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
    level_order(root);
    preorder(root);
    //ptr temp=nextsib(root);
    //cout<<temp->left->right->left->sibling->data<<"sib";
    //preorder(temp);
    //cout<<height(temp);
}