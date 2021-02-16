#include<bits/stdc++.h>
using namespace std;
 
 struct node
 {
     int data;
     node* left;
     node* right;
     /* data */
 };
 typedef node* ptr;
 void insert(ptr &l,int dat)
{
    if(l==NULL)
    {
        l=new node;
        l->left=NULL;
        l->right=NULL;
        l->data=dat;
    }
    else if(dat<l->data)
    {
        insert(l->left,dat);
    }
    else 
    {
        insert(l->right,dat);
    }
    
} 
void inorder_recursive (ptr &l)
{
    if(l==NULL)
    return;
    else
    {
    inorder_recursive(l->left);
    cout<<l->data<<" ";
    inorder_recursive(l->right);
    }
    
}
 void inorder(ptr &l)
 {
     stack <ptr> s;
     ptr c=l;
     while (l!=NULL||s.empty()==false)
     {
         while (l!=NULL)
         {
              s.push(l);
             l=l->left;
            
         }    
         l=s.top();
         cout<<l->data<<" ";
         s.pop();
         l=l->right;
     }
     
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
inorder(p1);
 }
