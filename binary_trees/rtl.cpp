#include<bits/stdc++.h>
using namespace std;
     struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

typedef TreeNode* ptr;
 vector<vector<int>>vec;
 int c=0;
 queue<int> q;
vector<vector<int> > pathSum(TreeNode* A, int B) {
    if(A!=NULL)
    {
    q.push(A->val);
    B=B-A->val;
    if(A->left==NULL&&A->right==NULL)
   { 
      if(B==0)
      {
          while(!q.empty())
          {
          vec[c].push_back(q.front());
          q.pop();
          }
          c++;
      }
   }
    pathSum(A->left,B);
    pathSum(A->right,B);
    }
    return vec;
    
}


int main ()
{
    ptr root=NULL;
    root= new TreeNode(2);
    root->left = new TreeNode(7); 
	root->right = new TreeNode(5); 
	root->left->right = new TreeNode(6); 
	root->left->right->left = new TreeNode(1); 
	root->left->right->right = new TreeNode(11); 
	root->right->right = new TreeNode(9); 
	root->right->right->left = new TreeNode(4);
    vector<vector<int>> vec;
    vec=pathSum(root,26);
    for(int it:vec[0])
    cout<<it;
}