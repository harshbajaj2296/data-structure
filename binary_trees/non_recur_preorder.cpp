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
void inorder (ptr l)
{


	if(l==NULL)
	return;
	    
	    	inorder(l->left);
	    	cout<<l->data<<" ";
	    	inorder(l->right);
		
}
void preorder(ptr l)
{
	stack <ptr> s; 
	s.push(l);
	while(!s.empty())
{
	ptr d=s.top();
	cout<<d->data<<"  ";
	s.pop();
    
	if(d->right!=NULL)
	s.push(d->right);	

	if(d->left!=NULL)
	s.push(d->left);
}}
void preorder (ptr &l)
{
	if(l==NULL)
	return;
	    
	
	    	cout<<l->data<<" ";
	    	preorder(l->left);
	    	
	    	preorder(l->right);
	    	
	    	
		
}
void postorder (ptr &l)
{
	if(l==NULL)
	return;
	    
	
	    
	    	postorder(l->left);
	    	
	    	postorder(l->right);
	    		cout<<l->data<<" ";
	    	
		
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
cout<<endl;
preorder(p1);cout<<endl;
postorder(p1);	
}


