/*
    Time complexity: O(n)
    Space complexity: O(w)

    Where ‘n’ is the number of nodes and 'w' is the maximum width of the binary tree.
*/

#include <queue>
vector<int> levelOrder(TreeNode<int> *root)
{

    vector<int> path;

    queue<TreeNode<int> *> q;
    // Push the root into the queue.
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();

        // Add current node to the path.
        path.push_back(cur->data);

        // If left child exists, push it into the queue.
        if (cur->left)
            q.push(cur->left);

        // If right child exists, push it in the queue.
        if (cur->right)
            q.push(cur->right);
    }

    return path;
}
