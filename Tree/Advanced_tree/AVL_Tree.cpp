#include <iostream>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
    Node(int val) : data(val), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) { return n ? n->height : 0; }

int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Balancing
    if (balance > 1 && key < root->left->data) return rightRotate(root);
    if (balance < -1 && key > root->right->data) return leftRotate(root);
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "AVL Inorder Traversal: ";
    inorder(root);
    return 0;
}
