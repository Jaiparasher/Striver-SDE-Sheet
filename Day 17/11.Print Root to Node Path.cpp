/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
#include<bits/stdc++.h>

void helper(BinaryTreeNode<int> * &root, vector<string>&ans,string prev){
  //base case
  if(!root) return;
  
  prev+=to_string(root->data)+" ";
  
  if(root->left==NULL && root->right==NULL){
    ans.push_back(prev);
    return;
  }

  helper(root->left,ans,prev);
  helper(root->right,ans,prev);
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string>ans;
    helper(root,ans,"");
    return ans;

}