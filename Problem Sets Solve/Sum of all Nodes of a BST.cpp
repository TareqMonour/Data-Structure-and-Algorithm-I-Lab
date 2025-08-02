#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the summation of a BST's elements
int calculateSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // In-order traversal: Left -> Root -> Right
    int sum = calculateSum(root->left) + root->val + calculateSum(root->right);

    return sum;
}

// Example usage:
int main() {
    // Construct a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    // Calculate the summation of the BST's elements
    int sum = calculateSum(root);

    // Display the result
    std::cout << "Summation of BST's elements: " << sum << std::endl;

    // Remember to free the allocated memory (not shown in this simple example)

    return 0;
}
