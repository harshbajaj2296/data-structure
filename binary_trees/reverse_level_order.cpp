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
         left=right=0;
     }
 };
 typedef node* ptr;
 void reverse_level_order(ptr l)
 {
     queue<node*> q;
     stack<node*> s;
     q.push(l);
     while(!q.empty()) 
     {
         ptr d= q.front();
         s.push(d);
         q.pop();
         if (d->left!=NULL)
         q.push(d->left); 
         if (d->right!=NULL)
         q.push(d->right);
     }
     while (!s.empty())
     {
         cout<<s.top()->data;
         s.pop();
     }
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
    reverse_level_order(root);
}