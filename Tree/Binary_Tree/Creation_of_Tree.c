#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* create() {
    int x;
    printf("Enter the value(-1 to indicate no node):");
    if (scanf("%d", &x) != 1 || x == -1) {
        return NULL;
    }

    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = x;

    printf("Enter the left child of %d\n", x);
    newnode->left = create();
    printf("Enter the right child of %d\n", x);
    newnode->right = create();

    return newnode;
}

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Free memory allocated for the tree
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = create();

    printf("Preorder traversal of the constructed tree is:\n");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the constructed tree is:\n");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the constructed tree is:\n");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
