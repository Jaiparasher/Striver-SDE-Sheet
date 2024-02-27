//Recursion

bool isMirrorReflection(TreeNode<int>* node1, TreeNode<int>* node2)
{

    //If both the nodes are NULL, then simply return true.
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }

    //If only one of them is NULL, then simply return false.
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }

    //Return true if the following three condition holds:
    /*
        1. Two nodes must have the same value.
        2. The left subtree of the left tree and right subtree of the right tree must be a mirror reflection of each other.
        3. The right subtree of the left tree and left subtree of the right tree must be a mirror reflection of each other.
    */

    return (node1->data == node2->data)
           && isMirrorReflection(node1->left, node2->right)
           && isMirrorReflection(node1->right, node2->left);
}

bool isSymmetric(TreeNode<int>* root)
{
    //If root is NULL, then simply return true.
    if (root == NULL)
    {
        return true;
    }

    //Check whether the left subtree and the right subtree of the root are mirror image of each other or not.
    return isMirrorReflection(root->left, root->right);
}

//Iterative


bool isSymmetric(TreeNode<int> *root)
{

    //If root is NULL, then simply return true.
    if (root == NULL)
    {
        return true;
    }

    //Create a queue which will contain the nodes of the binary tree.
    queue<TreeNode<int>*> q;

    //Push the root two times to the queue initially.
    q.push(root);
    q.push(root);

    while (!q.empty())
    {

        //Pop two elements from the queue
        TreeNode<int>* node1 = q.front();
        q.pop();

        TreeNode<int>* node2 = q.front();
        q.pop();

        //If both the nodes are NULL, then go back to the previous step.
        if (node1 == NULL && node2 == NULL)
        {
            continue;
        }

        //If only one of them is NULL, then simply return false.
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }

        //If the values of two nodes don't match, then simply return false.
        if (node1->data != node2->data)
        {
            return false;
        }

        //Add the left child of node1, right child of node2, right child of node1 and left child of node2 to the queue in exact order.
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }

    return true;
}