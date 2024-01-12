#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inOrderTraversal(root, k, result);
        return result;
    }

private:
    void inOrderTraversal(TreeNode* root, int& k, int& result) {
        if (root == nullptr) {
            return;
        }

        // Traverse left subtree
        inOrderTraversal(root->left, k, result);

        // Process the current node
        k--;
        if (k == 0) {
            result = root->val; // Found the kth smallest element
            return;
        }

        // Traverse right subtree
        inOrderTraversal(root->right, k, result);
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution solution;
    int k = 2;
    int result = solution.kthSmallest(root, k);

    if (result != -1) {
        std::cout << "The " << k << "th smallest element is: " << result << std::endl;
    } else {
        std::cout << "Invalid k value or element not found." << std::endl;
    }

    // Clean up memory (free allocated nodes)
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
