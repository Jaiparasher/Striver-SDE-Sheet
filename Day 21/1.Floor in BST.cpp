//Standard Tree Traversal

int floorInBST(TreeNode<int> * root, int X)
{
    // Base condition
    if(root == NULL)
    {
        return INT_MAX;
    }
  
    // If root -> data is equal to 'X'
    if(root -> val == X)
    {
        return root -> val;
    }
  
    // If root -> data is greater than the 'X'
    if(root -> val > X)
    {
        return floorInBST(root -> left, X);
    }
  
    // Else, the floor may lie in right subtree or may be equal to the root
    int floorValue = floorInBST(root -> right, X);

    return (floorValue <= X) ? floorValue : root -> val;
}

//BST Traversal

// Function that minimum absolute difference of the given node 'X' from BST 
int floorInBST(TreeNode<int> * root, int X)
{
    // Base condition
    if(root == NULL)
    {
        return INT_MAX;
    }
  
    // If root -> data is equal to 'X'
    if(root -> val == X)
    {
        return root -> val;
    }
  
    // If root -> data is greater than the 'X'
    if(root -> val > X)
    {
        return floorInBST(root -> left, X);
    }
  
    // Else, the floor may lie in right subtree or may be equal to the root
    int floorValue = floorInBST(root -> right, X);

    return (floorValue <= X) ? floorValue : root -> val;
}