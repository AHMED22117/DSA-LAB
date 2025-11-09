#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    bool isBSTUtil(Node* root, int minVal, int maxVal) {
        if (root == NULL)
            return true;
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

int main() {
    BST bst;
    bst.root = new Node(40);
    bst.root->left = new Node(10);
    bst.root->right = new Node(60);
    bst.root->right->left = new Node(50);
    bst.root->right->right = new Node(70);

    if (bst.isBST())
        cout << "This tree  a Binary Search Tree." << endl;
    else
        cout << "This tree is NOT a Binary Search Tree." << endl;

    return 0;
}
