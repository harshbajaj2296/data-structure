// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class LNode 
{ 
	public: 
	int data; 
	LNode* next; 
	LNode* prev; 
	LNode* left; 
	LNode* right; 

}; 

 
LNode* sortedListToBST(LNode *first,LNode *last) 
{
    if(first==last)
    return first;
    LNode *fast=first;LNode *mid=first->next;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        mid=mid->next;
        fast=fast->next->next;
    } 
    LNode *root=mid->next;
    root->left=sortedListToBST(first,mid);
    root->right=sortedListToBST(mid->next->next,last);
    return root;
}
void push(LNode** head_ref, int new_data) 
{ 
	/* allocate node */
	LNode* new_node = new LNode(); 
	
	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 


	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(LNode *node) 
{ 
	while(node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
LNode* newNode(int data) 
{ 
	LNode* node = new LNode(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

/* A utility function to 
print preorder traversal of BST */
void preOrder(LNode* node) 
{ 
	if (node == NULL) 
		return; 
	cout<<node->data<<" "; 
	preOrder(node->left); 
	preOrder(node->right); 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	LNode* head = NULL; 

	/* Let us create a sorted linked list to test the functions 
	Created linked list will be 1->2->3->4->5->6->7 */
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout<<"Given Linked List "; 
	printList(head); 

	/* Convert List to BST */
	LNode *root = sortedListToBST(head,0); 
	cout<<"\nPreOrder Traversal of constructed BST "; 
	preOrder(root); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
