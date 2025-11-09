#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = NULL; }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    int countInRange(Node* root, int a, int b) {
        if (root == NULL)
            return 0;

        if (root->data >= a && root->data <= b)
            return 1 + countInRange(root->left, a, b) + countInRange(root->right, a, b);

        else if (root->data < a)
            return countInRange(root->right, a, b);

        else
            return countInRange(root->left, a, b);
    }

public:
    BST() { root = NULL; }

    void insert(int val) { root = insert(root, val); }

    int countInRange(int a, int b) { return countInRange(root, a, b); }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(50);
    tree.insert(1);
    tree.insert(40);
    tree.insert(100);

    int a = 5, b = 45;
    cout << "Count of nodes in range [" << a << ", " << b << "]: "
         << tree.countInRange(a, b) << endl;

    return 0;
}
