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

    // Count total number of nodes
    int countNodes(Node* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Inorder traversal to find the median
    void findMedianUtil(Node* root, int& count, int n, int& currCount, double& median, Node*& prev) {
        if (root == NULL)
            return;

        findMedianUtil(root->left, count, n, currCount, median, prev);

        currCount++;

        // If odd number of nodes -> middle node
        if (n % 2 == 1 && currCount == (n + 1) / 2)
            median = root->data;

        // If even number of nodes -> average of middle two
        else if (n % 2 == 0 && (currCount == n / 2 || currCount == n / 2 + 1)) {
            if (currCount == n / 2)
                prev = root;
            else
                median = (prev->data + root->data) / 2.0;
        }

        findMedianUtil(root->right, count, n, currCount, median, prev);
    }

public:
    BST() { root = NULL; }

    void insert(int val) { root = insert(root, val); }

    double findMedian() {
        if (root == NULL)
            return 0;

        int n = countNodes(root); // total nodes
        int currCount = 0;
        double median = 0;
        Node* prev = NULL;

        findMedianUtil(root, n, n, currCount, median, prev);
        return median;
    }
};

int main() {
    BST tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "Median of BST: " << tree.findMedian() << endl;
    return 0;
}
