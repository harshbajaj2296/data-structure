#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;

node(int data)
{
    this->data=data;
    left= NULL;
    right=NULL;
}
};
typedef node* ptr;
int search(ptr l,int s)
{ int temp, temp1,value;
    if (l==NULL)
    return 0;
    else
    {
        if(l->data==s)
        return 1;
        else
        {
          temp = search(l->left,s);
          if(temp==1)
          return 1;
          else
         return search(l->right,s);
        }
    }
}
int search_trial_method(ptr l,int s)
{ int temp, temp1,value;cout<<"0";
    if (l==NULL)
    return 0;
    else
     return(l->data==s||search_trial_method(l->left,s)||search_trial_method(l->right,s));
}
 int main()
 {
     ptr root = new node(2); 
	root->left = new node(15); 
    root->left->left = new node(16); 
	root->right = new node(7); 
	root->left->right = new node(6); 
	root->left->right->left = new node(8); 
	root->left->right->right = new node(11); 
	root->right->right = new node(9); 
	root->right->right->left = new node(4); 
     int temp= search(root,16);
     //cout<<temp;
     if(temp==1)
     cout<<" found";
     else
     {
         cout<<" not found";
     }
       
 } 

