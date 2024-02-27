/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)

    Where 'N' is the number of nodes in the given binary tree.
*/

// Constructs the subtree and returns the root node.
TreeNode<int> *constructTree(int inStart, int inEnd, int &pIndex, vector<int> &inorder, vector<int> &preorder)
{
    if (inStart > inEnd)
    {
        // Subtree is empty.
        return NULL;
    }

    // Get root node value from preorder sequence.
    int rootNode = preorder[pIndex];

    // Increment the index denoting the first element of preorder traversal.
    pIndex = pIndex + 1;

    // Create the root node with "rootNode" value.
    TreeNode<int> *root = new TreeNode<int>(rootNode);

    if (inStart == inEnd)
    {
        // There is a single node in the given subtree.
        return root;
    }
    else
    {
        // Get the index of root node from the inorder sequence.
        int inIndex;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (rootNode == inorder[i])
            {
                // Root node value found.
                inIndex = i;
                break;
            }
        }

        // Recur for the left subtree.
        TreeNode<int> *leftChild = constructTree(inStart, inIndex - 1, pIndex, inorder, preorder);

        // Recur for the right subtree.
        TreeNode<int> *rightChild = constructTree(inIndex + 1, inEnd, pIndex, inorder, preorder);

        // Link the left and right child to the root node.
        root->left = leftChild;
        root->right = rightChild;

        return root;
    }
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{

    // Index of the first element of the preorder sequence
    int pIndex = 0;

    return constructTree(0, inorder.size() - 1, pIndex, inorder, preorder);
}