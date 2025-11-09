#include <iostream>
#include <stack>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);
        }

        if (val < root->data)
            root->left = insertNode(root->left, val);
        else if (val > root->data)
            root->right = insertNode(root->right, val);

        return root;
    }

    bool searchNode(Node* root, int val) {
        if (root == NULL)
            return false;
        if (root->data == val)
            return true;
        else if (val < root->data)
            return searchNode(root->left, val);
        else
            return searchNode(root->right, val);
    }

    Node* findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    void deleteNode(Node*& current, int value) {
        if (current == NULL)
            return;

        if (value < current->data)
            deleteNode(current->left, value);
        else if (value > current->data)
            deleteNode(current->right, value);
        else {
            
            if (current->left == NULL && current->right == NULL) {
                delete current;
                current = NULL;
            }
            
            else if (current->left == NULL) {
                Node* temp = current;
                current = current->right;
                delete temp;
            }
            
            else if (current->right == NULL) {
                Node* temp = current;
                current = current->left;
                delete temp;
            }
            
            else {
                Node* temp = findMin(current->right);
                current->data = temp->data;
                deleteNode(current->right, temp->data);
            }
        }
    }

    void BFS(Node* current) {
        if (current == NULL)
            return;

        Node* queue[100];
        int head = 0, tail = 0;
        queue[tail++] = current;

        while (head < tail) {
            Node* node = queue[head++];
            cout << node->data << " ";

            if (node->left != NULL)
                queue[tail++] = node->left;
            if (node->right != NULL)
                queue[tail++] = node->right;
        }
    }
    
    void inorderDFS(Node* root) {
        if (root == NULL)
            return;

        stack<Node*> s;
        Node* current = root;

        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();

            cout << current->data << " ";

            current = current->right;
        }
    }

    void preorderDFS(Node* root) {
        if (root == NULL)
            return;

        stack<Node*> s;
        s.push(root); 

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";

            if (current->right != NULL)
                s.push(current->right);
            if (current->left != NULL)
                s.push(current->left);
        }
    }

    void postorderDFS(Node* root) {
        if (root == NULL)
            return;

        stack<Node*> s;
        Node* current = root;
        Node* lastVisited = NULL;

        while (!s.empty() || current != NULL) {
            if (current != NULL) {
                s.push(current);
                current = current->left;
            } else {
                Node* peekNode = s.top();
                if (peekNode->right != NULL && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    cout << peekNode->data << " ";
                    lastVisited = peekNode;
                    s.pop();
                }
            }
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void search(int val) {
        if (searchNode(root, val))
            cout << "VALUE FOUND\n";
        else
            cout << "VALUE NOT FOUND\n";
    }

    void remove(int val) {
        deleteNode(root, val);
    }

    void bfs() {
        BFS(root);
        cout << endl;
    }

    void inorder() {
        inorderDFS(root);
        cout << endl;
    }

    void preorder() {
        preorderDFS(root);
        cout << endl;
    }

    void postorder() {
        postorderDFS(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "BFS: ";
    tree.bfs();

    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    cout << "\nDeleting 20...\n";
    tree.remove(20);
    cout << "BFS after delete: ";
    tree.bfs();

    tree.search(60);
    tree.search(100);

    return 0;
}
