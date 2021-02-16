#include<iostream>
#include<queue>
using namespace std;

struct a1
{
	int data;
	struct a1*left;
	struct a1*right;
};
typedef struct a1* ptr;

void insert (ptr &l,int dat)
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

void level_order(ptr &l)
{
	queue <ptr> q; 
	q.push(l);
	while(!q.empty())
{
	ptr d=q.front();
	cout<<d->data<<"  "<<endl;
	q.pop();
	if(d->left!=NULL)
	q.push(d->left);
	if(d->right!=NULL)
	q.push(d->right);	
}
}
int main()
{
ptr p1=NULL;
insert(p1,3);
insert(p1,2);
insert(p1,4);
insert(p1,7);
insert(p1,6);
insert(p1,8);
level_order(p1);	

}

