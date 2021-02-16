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
        left=right=NULL;
    }
};
typedef node* ptr;
int no_of_nodes(ptr l)
{
    if (l==NULL)
    return 0;
    else
    {
    return(no_of_nodes(l->left)+1+no_of_nodes(l->right));
    }
}
void no_of_nodes_it(ptr l)
{
    queue <ptr> q;
   q.push(l);int c=0;
    while (!q.empty())
    {
        ptr d= q.front();
        c++;
        q.pop();
        if(d->left!=NULL)
        q.push(d->left);
        if(d->right!=NULL)
        q.push(d->right);
    }
    cout<<c;
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
    no_of_nodes_it(root);
}