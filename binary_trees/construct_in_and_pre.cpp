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
ptr tree(int in[],int pre[],int start,int end)
{
    static int pre_index=0;
    if(start>end)
    return NULL;
    node* tnode= new node(pre[pre_index++]);
    if(start==end)
    return tnode;
    int index=search(in,start,end,tnode->data);
    tnode->left=tree(in,pre,start,index-1);
    tnode->right=tree(in,pre,index+1,end);
    return tnode;
}
void print(ptr l)
{
    if(l==NULL)
    return;
    print(l->left);
    print(l->right);
    cout<<l->data;
}
int main()
{int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
int pre[] = {1,2,4,8,5,3,6,7}; 
int end=sizeof(in)/sizeof(in[0]);
ptr l=tree(in,pre,0,end-1);
print(l);
}