#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) { return n ? n->height : 0; }

void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->key);
    inorder(root->right, arr);
}

int findKthSmallest(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    return (k > 0 && k <= arr.size()) ? arr[k-1] : -1;
}

int findKthLargest(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    return (k > 0 && k <= n) ? arr[n-k] : -1;
}

void printHeights(Node* root) {
    cout << "Left height = " << height(root->left)
         << ", Right height = " << height(root->right) << endl;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    cout << "3rd smallest: " << findKthSmallest(root, 3) << endl;
    cout << "2nd largest: " << findKthLargest(root, 2) << endl;
    printHeights(root);
}
