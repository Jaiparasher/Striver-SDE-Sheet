#include <bits/stdc++.h>
class BSTIterator {
    stack<BinaryTreeNode*> st;
    bool reverse = true;

public:
    BSTIterator(BinaryTreeNode* root, bool isReverse) { 
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        BinaryTreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(BinaryTreeNode* root) {
        for (; root != NULL; ){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};

bool pairSumBst(BinaryTreeNode *root, int k)
{
    if(!root) return false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i<j){
        if(i+j == k) return true;
        if(i + j < k ) i = l.next();
        else j = r.next();
    } 
    return false;
}