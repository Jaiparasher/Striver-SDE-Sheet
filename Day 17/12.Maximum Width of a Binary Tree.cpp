/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0 ;
        }
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long ans=0;
        while(!q.empty()){
            unsigned long long s= q.size();
            unsigned long long mini=INT_MAX,maxi=0;
            for(int i=0; i<s ; i++){
                auto node = q.front();
                unsigned long long idx = node.second;
                q.pop();

                if(i==0){
                    mini=idx;
                }
                if(i==s-1){
                    maxi= idx;
                }
                
                if(node.first->left){
                    
                    q.push({node.first->left,2*idx+1});
                }
                if(node.first->right){
                    q.push({node.first->right,2*idx+2});
                }
            }
            ans =max(ans ,maxi-mini+1);
        }
        return ans;
    }
};