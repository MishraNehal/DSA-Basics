#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->right->left = new Node(60);

    cout << "Inorder before deletion: ";
    inorder(root);
    root = deleteNode(root, 70);
    cout << "\nInorder after deletion: ";
    inorder(root);
    return 0;
}
