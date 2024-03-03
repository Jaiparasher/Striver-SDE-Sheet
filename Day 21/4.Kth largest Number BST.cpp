//Inorder Traversal

void inorder(TreeNode<int>* root, vector<int>& inTraversal)
{
	if (root == NULL)
	{
		return;
	}

	// Recurse over left subtree. 
	inorder(root -> left, inTraversal);

    inTraversal.push_back(root -> data);

	// Recurse over right subtree.
	inorder(root -> right, inTraversal);
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	vector <int> inTraversal;

	inorder(root, inTraversal);

	int n = inTraversal.size();

	if (k > n)
	{
		return -1;
	}
	
	return inTraversal[n - k];
}

//Reverse Inorder Traversal

int revInorder(TreeNode<int>* root, int &visCount, int k)
{
	if (root == NULL)
	{
		return -1;
	}
	
	// Recurse over right subtree. 
	int right = revInorder(root -> right, visCount, k);
    
    if (right != -1)
    {
    	return right;
    }

	visCount++;

	if (visCount == k)
	{
		return root -> data;
	}

	// Recurse over left subtree.
	int left = revInorder(root -> left, visCount, k);
    
    return left;
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	int visCount = 0;

	return revInorder(root, visCount, k);
}