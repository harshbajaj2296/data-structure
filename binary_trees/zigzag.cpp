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
 void zigzag(ptr l)
 {
     stack<int>s;
     queue<ptr> q;
     int count=0;
     q.push(l);
     int curr_state=0; 
     while (true)
     { 
         count=q.size();
         if(count==0)
         break;
         while(count>0)
         {
         ptr d=q.front();
         q.pop();
         if(curr_state==0)
         cout<<d->data<<"->";
         else
        { s.push(d->data);}
         if(d->left!=NULL)
         q.push(d->left);
         if(d->right!=NULL)
         q.push(d->right);
         count--;
         }

         if(curr_state==0)
         curr_state=1;
         else
         {
             curr_state=0;
             while(!s.empty())
             {
                 cout<<s.top()<<"->";
                 s.pop();
             }
         }

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
    zigzag(root);
}