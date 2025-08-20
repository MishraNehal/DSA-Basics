#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        color = RED; // New node is always RED initially
    }
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node* &x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* &z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            Node* grandparent = z->parent->parent;

            if (z->parent == grandparent->left) {
                Node* y = grandparent->right;
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is RED
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    grandparent->color = RED;
                    z = grandparent;
                } else {
                    // Case 2 or 3: Uncle is BLACK
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateRight(grandparent);
                }
            } else {
                Node* y = grandparent->left;
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is RED
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    grandparent->color = RED;
                    z = grandparent;
                } else {
                    // Case 2 or 3: Uncle is BLACK
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateLeft(grandparent);
                }
            }
        }
        root->color = BLACK; // Root is always BLACK
    }

    void inorderHelper(Node* root) {
        if (root == nullptr) return;
        inorderHelper(root->left);
        cout << root->data << (root->color == RED ? "(R) " : "(B) ");
        inorderHelper(root->right);
    }

public:
    RedBlackTree() { root = nullptr; }

    void insert(int data) {
        Node* z = new Node(data);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        fixInsert(z);
    }

    void inorder() {
        cout << "Inorder Traversal (with colors): ";
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);

    rbt.inorder();

    return 0;
}
