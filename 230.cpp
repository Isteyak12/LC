#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int result = -1;
        inOrderTraversal(root, k, result);
        return result;
    }

    TreeNode *create_BST(TreeNode *&root, int data)
    {
        TreeNode *new_node = new TreeNode(data);
        if (root == nullptr)
        {
            root = new_node;
            return root;
        }
        else
        {
            if (root->val > data)
            {
                root->left = create_BST(root->left, data);
            }
            else
            {
                root->right = create_BST(root->right, data);
            }
            return root;
        }
    }

    // Added a public function to display the tree
    void displayTree(TreeNode *root)
    {
        display(root);
        cout << endl;
    }

private:
    void inOrderTraversal(TreeNode *root, int &k, int &result)
    {
        if (root == nullptr)
        {
            return;
        }

        // Traverse left subtree
        inOrderTraversal(root->left, k, result);

        // Process the current node
        k--;
        if (k == 0)
        {
            result = root->val; // Found the kth smallest element
            return;
        }

        // Traverse right subtree
        inOrderTraversal(root->right, k, result);
    }

    void display(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
};

int main()
{
    // Create a sample BST
    TreeNode *root = nullptr;

    Solution solution;
    solution.create_BST(root, 3);
    solution.create_BST(root, 1);
    solution.create_BST(root, 4);
    solution.create_BST(root, 2);

    // Display the created BST
    cout << "BST In-Order Traversal: ";
    solution.displayTree(root);

    int k = 2;
    int result = solution.kthSmallest(root, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
