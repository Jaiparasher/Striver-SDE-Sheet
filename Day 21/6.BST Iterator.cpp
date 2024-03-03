class BSTiterator{   
    stack<TreeNode<int>*> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);

    }

    int next()
    {
        TreeNode<int>* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        if(st.empty()) return false;

        return true;
    }

    private:
        void pushAll(TreeNode<int>* root){
            for(;root!=NULL;st.push(root),root = root->left);
        }
};