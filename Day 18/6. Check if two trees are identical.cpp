bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
         
    // If both are NULL trees, they are identical.       
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    // If any one of the trees is NULL, they are not identical. 
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    // Check if root's data of both the trees is same. 
    // Recursively check if left subtree and right subtree of both trees is identical. 
    // Return true only if all conditions satisfy. 
    
    return (root1->data == root2->data) && 
            identicalTrees(root1->left, root2->left) && 
            identicalTrees(root1->right, root2->right);
    
}