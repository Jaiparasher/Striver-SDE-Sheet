//Using Recursion 

TreeNode<int> *flattenBinaryTreeHelper(TreeNode<int> *currentNode, TreeNode<int> *lastNode)
{
    if (currentNode == NULL)
    {
        // Base Condition.
        return lastNode;
    }

    if (lastNode != NULL)
    {
        // Set currentNode as the right child of the lastNode.
        lastNode->right = currentNode;
    }

    // Store the left and right child of the currentNode in temporary variables.
    TreeNode<int> *left = currentNode->left;
    TreeNode<int> *right = currentNode->right;

    // Set the left and right pointers of currentNode to NULL.
    currentNode->left = currentNode->right = NULL;

    TreeNode<int> *newLastNode = flattenBinaryTreeHelper(left, currentNode);

    newLastNode = flattenBinaryTreeHelper(right, newLastNode);

    return newLastNode;
}

void flattenBinaryTree(TreeNode<int> *root)
{
    flattenBinaryTreeHelper(root, NULL);
}

//Using Stack

void flattenBinaryTree(TreeNode<int> *root)
{
    stack<TreeNode<int> *> stk;

    while (root != NULL || !stk.empty())
    {
        if (root->right != NULL)
        {
            stk.push(root->right);
        }

        if (root->left != NULL)
        {
            // Make the left child as the new right child of the node.
            root->right = root->left;
            root->left = NULL;
        }
        else if (!stk.empty())
        {
            // Pop the top node from the stack.
            // Make it the right child of the current node.
            root->right = stk.top();
            stk.pop();
        }

        // Set the right child of the node as the current node.
        root = root->right;
    }
}

//Optimized Approach

TreeNode<int> *flattenBinaryTreeHelper(TreeNode<int> *currentNode, TreeNode<int> *lastNode)
{
    if (currentNode == NULL)
    {
        // Base Condition.
        return lastNode;
    }

    if (lastNode != NULL)
    {
        // Set currentNode as the right child of the lastNode.
        lastNode->right = currentNode;
    }

    // Store the left and right child of the currentNode in temporary variables.
    TreeNode<int> *left = currentNode->left;
    TreeNode<int> *right = currentNode->right;

    // Set the left and right pointers of currentNode to NULL.
    currentNode->left = currentNode->right = NULL;

    TreeNode<int> *newLastNode = flattenBinaryTreeHelper(left, currentNode);

    newLastNode = flattenBinaryTreeHelper(right, newLastNode);

    return newLastNode;
}

void flattenBinaryTree(TreeNode<int> *root)
{
    flattenBinaryTreeHelper(root, NULL);
}