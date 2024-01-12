    TreeNode* create_BST(TreeNode *&root, int data)
    {
        TreeNode *new_node = new TreeNode(data);
        if (root = nullptr)
        {
            root = new_node;
            return root;
        }
        else
        {
            TreeNode *curr = root;
            if (curr->val > data)
            {
                create_BST(curr->left, data);
            }
            else
            {
                // curr->val=data;
                create_BST(curr->right, data);
            }
        }
    }