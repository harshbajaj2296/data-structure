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
void root_to_leaf(ptr l, int a[], int n)
{ if(l==NULL)
    return ;
    a[n]=l->data;
    //n++;
    if (l->left==NULL&&l->right==NULL)
    {//cout<<"n="<<n<<endl;
        for(int i=0;i<=n;i++)
        cout<<a[i]<<"->";
        cout<<endl;
    }  
    root_to_leaf(l->left,a,n+1);
    root_to_leaf(l->right,a,n+1);
}
int root_to_leaf_2(ptr A, int B)
{ 
    if(A==NULL)
    return 0 ;
      B=B-A->data;
   cout<<B<<"  ";
   return((root_to_leaf_2(A->left,B))||root_to_leaf_2(A->right,B)||(A->left==NULL&&A->right==NULL&&B==0));
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
    int a[100];
    queue <int>q;
    root_to_leaf(root,a,0);
    cout<<endl;
   cout<< root_to_leaf_2(root,26);
}