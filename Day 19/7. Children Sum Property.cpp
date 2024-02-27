//DFS or Recursion

bool isParentSum(Node *root)
{
    // Base case: If the root is NULL or it is a leaf node, it satisfies the Parent Sum property
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }

    // Subtract the values of the left and right child from the current node's value
    if (root->left)
    {
        root->data -= root->left->data;
    }
    if (root->right)
    {
        root->data -= root->right->data;
    }

    // Check if the current node's value is equal to the sum of its children's values
    if (root->data == 0)
    {
        // Recursively check the Parent Sum property for the left and right subtrees
        return isParentSum(root->left) && isParentSum(root->right);
    }

    // If the current node's value is not equal to the sum of its children's values, it does not satisfy the Parent Sum property
    return false;
}

//BFS or Iterative Approach

int isParentSum(Node *root)
{
    // Create a queue to perform level-order traversal of the tree
    queue<Node*> q;
    
    // Push the root node into the queue
    q.push(root);
    
    // Push a NULL node to mark the end of the current level
    q.push(NULL);
    
    // Perform level-order traversal
    while (!q.empty())
    {
        // Get the front node from the queue
        Node* curr = q.front();
        q.pop();
        
        // If the current node is NULL, it indicates the end of the current level
        if (curr == NULL)
        {
            // If the queue is not empty, push another NULL node to mark the end of the next level
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        
        // Calculate the sum of the values of the left and right children
        int childrenSum = 0;
        
        if (curr->left)
        {
            q.push(curr->left);
            childrenSum += curr->left->data;
        }
        
        if (curr->right)
        {
            q.push(curr->right);
            childrenSum += curr->right->data;
        }
        
        // Check if the sum of children's values is not equal to the current node's value
        // and it is not equal to zero (to handle leaf nodes)
        if (childrenSum != curr->data && childrenSum != 0)
            return 0;
    }
    
    // If the traversal completes without finding any violation of the Sum Property, return 1
    return 1;
}