#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    bool search(Node* root, int val) {
        if (root == NULL)
            return false;

        if (root->data == val)
            return true;
        else if (val < root->data)
            return search(root->left, val);
        else
            return search(root->right, val);
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void printInorder() {
        cout << "BST Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // initial tree
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    tree.printInorder();

    int val;
    cout << "Enter a value to search: ";
    cin >> val;

    if (tree.search(val)) {
        cout << "Value " << val << " found in the tree." << endl;
    } else {
        cout << "Value not found! Inserting " << val << " into the tree..." << endl;
        tree.insert(val);
        cout << "New tree after insertion:" << endl;
        tree.printInorder();
    }

    return 0;
}
