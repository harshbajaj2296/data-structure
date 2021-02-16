// C++ program to find maximum and 
// minimum in a Binary Tree 
#include<bits/stdc++.h> 
#include<iostream> 
using namespace std; 

// A tree node 
struct Node 
{ 
	int data; 
	Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = NULL; 
		right = NULL; 
	} 
}; 
int findMax(Node* l)
{
	if(l==NULL)
	{
		return INT_MIN;
	}
	int dat =l->data;
	int a=findMax(l->left);
	int b=findMax(l->right);
	if(a>dat)
	dat=a;
	if(b>dat)
	dat=b;
	return(dat);

}
int find_max_iterative(Node*l)
{
	queue<Node*> q;
	q.push(l);
	int max=INT_MIN;
	while (!q.empty())
	{
		Node* d=q.front();
		q.pop();
		if(d->data>max)
		max=d->data;
		if(d->left!=NULL)
		q.push(d->left);
		if(d->right!=NULL)
		q.push(d->right);
	}
	return max;
}
int main() 
{ 
	//Node*NewRoot = NULL; 
	Node *root = new Node(2); 
	root->left = new Node(7); 
	root->right = new Node(5); 
	root->left->right = new Node(6); 
	root->left->right->left = new Node(1); 
	root->left->right->right = new Node(11); 
	root->right->right = new Node(9); 
	root->right->right->left = new Node(4); 

	cout << "Maximum element is "
		<< find_max_iterative(root) << endl; 

	return 0; 
} 

