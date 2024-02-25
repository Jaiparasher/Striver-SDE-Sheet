//DFS or Recursion

int heightOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Compute the depth of each subtree
        int depthLeft = heightOfBinaryTree(root -> left);
        int depthRight = heightOfBinaryTree(root -> right);

        // Use the larger one
        if (depthLeft > depthRight)
        {
            return depthLeft + 1;
        }
        else
        {
            return depthRight + 1;
        }
    }
}

//BFS or Level order traversal

int heightOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<TreeNode<int> *> q;
    q.push(root);

    int height = 0;

    while (q.size() > 0)
    {
        int count = q.size();

        for(int i = 0; i < count; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();

            if (node -> left != NULL)
            {
                q.push(node -> left);
            }
            if (node -> right != NULL)
            {
                q.push(node -> right);
            }
        }

        height++;
    }

    return height;
}