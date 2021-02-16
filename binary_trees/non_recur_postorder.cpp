#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data; 
    node*left;
    node*right;

};
typedef node* ptr;
void insert(ptr &l,int dat)
{
    if(l==NULL)
    {
    l=new node;
    l->right=l->left=NULL;
    l->data=dat;
    }
    else if(dat<l->data)
    {
     insert(l->left,dat);   
    }
    else
    insert(l->right,dat);
}
void recursive_postorder(ptr &l)
{
    if(l==NULL)
    return;
    else
    {
        recursive_postorder(l->left);
       recursive_postorder(l->right);
       cout<<l->data<<" "; 
    }
    
}
void postorder (ptr &l)
{
    stack <ptr> s;
   ptr curr=l;
   ptr d=NULL;
    while (curr!=NULL||s.empty()==false)
    {
        while (curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        
        if(curr->right==NULL||curr->right==d)
        {cout<<curr->data<<" ";
        d=curr;
        curr=NULL;
        s.pop();
        }
        else
        {
           // s.push(curr);
            curr=curr->right;
        }
        
        
     
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
postorder(p1);
}