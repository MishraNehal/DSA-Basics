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
    printf("Enter the value (-1 to indicate no node): ");
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
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Level-order traversal (BFS)
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

// Free memory allocated for the tree
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = create();

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
