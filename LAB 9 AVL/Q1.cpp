#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(NULL), right(NULL), height(1) {}
};

// Utility: get height
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility: get balance factor
int getBalance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;   // x becomes new root
    Node* T2 = x->right; // T2 will be reattached

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;  // new root
}

// Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;  // y becomes new root
    Node* T2 = y->left;  // T2 will be reattached

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  // new root
}

// Function to convert a BST to AVL recursively
Node* convertToAVL(Node* root) {
    if (!root) return NULL;

    // Recursively convert subtrees first
    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // If unbalanced, perform appropriate rotation

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;  // balanced node
}
