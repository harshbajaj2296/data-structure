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
 int height(ptr l, int n,int b)
 {
     if(l==NULL)
     return 0;
     if(n==l->data)
        return true;
         
         bool left=height(l->left,n,b);
         if(left==false)
         right= height(l->right,n,b);
         if(left>right)
         return (left+1);
         else
         return(right+1); 
         cout<<float(1/2);
     }
 }
 void height_it(ptr l)
 {
     queue<ptr> q;
     int count=0;
     bool b= false;
     q.push(l);
     int height=0;
   
     while (b!=true)
     { 
         count=q.size();
         if(count==0)
         b=true;
         height++;
         while(count>0)
         {
         ptr d=q.front();
         q.pop();
         if(d->left!=NULL)
         q.push(d->left);
         if(d->right!=NULL)
         q.push(d->right);
         count--;
         }
     }
     cout<<height-1<<"it";
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
    // height_it(root);
    cout<<height(root,7,false);
}