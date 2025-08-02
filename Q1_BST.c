#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

void printInOrder(struct Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->key);
        printInOrder(root->right);
    }
}

void printPreOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(struct Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->key);
    }
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main()
{
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Print Traversals\n");
        printf("5. Height of BST\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in the BST.\n", value);
                else
                    printf("Value %d not found in the BST.\n", value);
                break;

            case 4:
                printf("Select traversal type:\n");
                printf("1. In-order\n");
                printf("2. Pre-order\n");
                printf("3. Post-order\n");
                printf("Enter your choice: ");
                scanf("%d", &value);
                switch (value) {
                    case 1:
                        printf("In-order Traversal: ");
                        printInOrder(root);
                        break;
                    case 2:
                        printf("Pre-order Traversal: ");
                        printPreOrder(root);
                        break;
                    case 3:
                        printf("Post-order Traversal: ");
                        printPostOrder(root);
                        break;
                    default:
                        printf("Invalid Choice for Traversal.\n");
                }
                printf("\n");
                break;

            case 5:
                printf("Height of BST: %d\n", height(root));
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

