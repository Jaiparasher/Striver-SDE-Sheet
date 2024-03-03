string serializeTree(TreeNode<int> *root)
{
    if(!root) return "";
        
        string s ="";
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode<int>* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->data)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);
           }
        }
    return s;

}

TreeNode<int>* deserializeTree(string &data)
{
    if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode<int> *root = new TreeNode(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode<int> *node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode<int>* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            }
            else {
                TreeNode<int>* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;

}