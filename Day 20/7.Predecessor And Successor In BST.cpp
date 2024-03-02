//Inorder Traversal

void inorder(TreeNode *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // To store the inorder traversal of the BST.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int predecessor = -1, successor = -1;

    // Finding predecessor.
    for (int i = 0; i < inorderArray.size(); i++)
    {
        if (inorderArray[i] < key)
        {
            predecessor = inorderArray[i];
        }
    }

    // Finding successor.
    for (int i = inorderArray.size() - 1; i >= 0; i--)
    {
        if (inorderArray[i] > key)
        {
            successor = inorderArray[i];
        }
    }

    // We are returning here.
    return {predecessor, successor};
}

//Optimized Approach

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key > temp->data)
        {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key >= temp->data)
        {
            temp = temp->right;
        }
        else
        {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
        }
    }

    return make_pair(predecessor, successor);
}