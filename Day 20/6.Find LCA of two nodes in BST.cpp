//Recursive Approach

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if (root->data < P->data && root->data < Q->data)
    {
        // Moving towards right.
        return LCAinaBST(root->right, P, Q);
    }

    if (root->data > P->data && root->data > Q->data)
    {
        // Moving towards left.
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}

//Iterative Approach

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Initializing 'cur' with root.
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->data > P->data && cur->data > Q->data)
        {
            // Updating 'cur'.
            cur = cur->left;
        }
        else if (cur->data < P->data && cur->data < Q->data)
        {
            // Updating 'cur'.
            cur = cur->right;
        }
        else
        {
            // Returning LCA.
            return cur;
        }
    }
    return NULL;
}