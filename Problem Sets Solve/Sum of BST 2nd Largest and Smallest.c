#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with the given value.
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST.
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the 2nd smallest element in the BST.
void findSecondSmallest(struct TreeNode* root, int* count, int* result) {
    if (root == NULL || *count >= 2) {
        return;
    }

    findSecondSmallest(root->left, count, result);

    (*count)++;

    if (*count == 2) {
        *result = root->val;
        return;
    }

    findSecondSmallest(root->right, count, result);
}

// Function to find the 2nd largest element in the BST.
void findSecondLargest(struct TreeNode* root, int* count, int* result) {
    if (root == NULL || *count >= 2) {
        return;
    }

    findSecondLargest(root->right, count, result);

    (*count)++;

    if (*count == 2) {
        *result = root->val;
        return;
    }

    findSecondLargest(root->left, count, result);
}

// Function to calculate the sum of the 2nd smallest and 2nd largest elements in the BST.
int sumOfSecondLargestAndSecondSmallest(struct TreeNode* root) {
    int secondSmallest = -1;
    int secondLargest = -1;

    int count = 0;
    findSecondSmallest(root, &count, &secondSmallest);

    count = 0;
    findSecondLargest(root, &count, &secondLargest);

    return secondSmallest + secondLargest;
}

// Function to free the memory allocated for the BST.
void freeBST(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

// Example usage
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    int result = sumOfSecondLargestAndSecondSmallest(root);

    printf("Sum of the 2nd smallest and 2nd largest elements: %d\n", result);

    // Free the allocated memory
    freeBST(root);

    return 0;
}
