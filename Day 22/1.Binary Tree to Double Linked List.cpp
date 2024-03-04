//Recursive - 1 O(N^2)


BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {

    // Base case.
    if(root == NULL)
    {
        return root;
    }

    if(root->left != NULL)
    {
        BinaryTreeNode<int>* left = BTtoDLL(root->left);

        // Inorder predecessor.
        while(left->right != NULL)
        {
            left = left->right;
        }

        left->right = root;
        root->left = left;
    }

    if(root->right != NULL)
    {
        BinaryTreeNode<int>* right = BTtoDLL(root->right);

        // Inorder successor.
        while(right->left != NULL)
        {
            right = right->left;
        }

        right->left = root;
        root->right = right;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}


//Recursive - 2 O(N)

void findHead(BinaryTreeNode<int> *root, BinaryTreeNode<int> **head, BinaryTreeNode<int> **prev) {
    
    // Base case.
    if(root == NULL)
    {
        return ;
    }

    findHead(root->left, head, prev);

    if(*prev == NULL)
    {
        *head = root;
    }
    else
    {
        root->left = *prev;
        (*prev)->right = root;
    }

    *prev = root;

    findHead(root->right, head, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev = NULL;
    findHead(root, &head, &prev);

    return head;
}