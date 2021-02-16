#include<bits/stdc++.h>
using namespace std;
struct node
{
 int data;
 node* left;
 node*right;
 node(int data)
 {
     this->data=data;
     left=right=NULL;
 }
};
typedef node* ptr;
int search(int in[],int start,int end,int n)
{int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==n)
        break;
    }
        return i;
}
ptr tree(int in[],int post[],int start,int end)
{
    static int post_index=end;
    if(start>end)
    return NULL;
    node* tnode= new node(post[post_index--]);
    if(start==end)
    return tnode;
    int index=search(in,start,end,tnode->data);
    tnode->right=tree(in,post,index+1,end);
    tnode->left=tree(in,post,start,index-1);
    return tnode;
}
void print(ptr l)
{
    if(l==NULL)
    return;
    cout<<l->data;
    print(l->left);
    print(l->right);
}
int main()
{int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
int post[] = {8, 4, 5, 2, 6, 7, 3, 1}; 
int end=sizeof(in)/sizeof(in[0]);
ptr l=tree(in,post,0,end-1);
print(l);
}