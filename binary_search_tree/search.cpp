 #include<bits/stdc++.h>
using namespace std;

struct a1
{
	int data;
	struct a1*left;
	struct a1*right;
};
typedef struct a1* ptr;

void  insert (ptr &l,int dat)
{
	if(l==NULL)
	{
	l=new a1;
	l->data=dat;
	l->left=NULL;
	l->right=NULL;
	}
	else if(dat<l->data)
	insert(l->left,dat);
	else 
	insert(l->right,dat);
}
void inorder (ptr &l)
{
	if(l==NULL)
	return;    
	inorder(l->left);
	cout<<l->data<<" ";
	inorder(l->right);		
}
int search(ptr l,int data)
{
    if(l==NULL)
    return 0;
    if(l->data==data)
    return 1;
    else if(l->data>data)
    return search(l->left,data);
    else
    return search(l->right,data);
    
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
//inorder(p1);
cout<<search(p1,6)<<endl;
}