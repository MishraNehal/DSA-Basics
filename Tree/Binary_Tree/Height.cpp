#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Height of Tree: " << height(root);
    return 0;
}
