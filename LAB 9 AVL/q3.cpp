#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
};

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxValue(height(y->left), height(y->right)) + 1;
    x->height = maxValue(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxValue(height(x->left), height(x->right)) + 1;
    y->height = maxValue(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + maxValue(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void printBalance(Node* root) {
    if (root == NULL) return;
    cout << "Node " << root->key << " -> Balance Factor: " << getBalance(root) << endl;
    printBalance(root->left);
    printBalance(root->right);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    root = insert(root, 12);

    cout << "Preorder traversal of final AVL tree: ";
    preorder(root);

    cout << "\n\nBalance Factors:\n";
    printBalance(root);

    cout << "\nHeight of tree: " << height(root) << endl;
    return 0;
}
