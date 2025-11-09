#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//-----------------------------
// Student class
//-----------------------------
class Student {
public:
    string name;
    int roll;
    int score;

    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }

    void display() const {
        cout << "Name: " << name << ", Roll: " << roll << ", Score: " << score << endl;
    }
};

//-----------------------------
// Node structure for BST
//-----------------------------
struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) {
        data = s;
        left = right = NULL;
    }
};

//-----------------------------
// BST class
//-----------------------------
class BST {
private:
    Node* root;

    // Helper function to insert by name
    Node* insert(Node* root, Student s) {
        if (root == NULL)
            return new Node(s);

        if (s.name < root->data.name)
            root->left = insert(root->left, s);
        else
            root->right = insert(root->right, s);

        return root;
    }

    // Search by name
    bool search(Node* root, string name) {
        if (root == NULL)
            return false;

        if (root->data.name == name)
            return true;
        else if (name < root->data.name)
            return search(root->left, name);
        else
            return search(root->right, name);
    }

    // Delete nodes with score < 10
    Node* deleteLowScorers(Node* root) {
        if (root == NULL)
            return NULL;

        root->left = deleteLowScorers(root->left);
        root->right = deleteLowScorers(root->right);

        if (root->data.score < 10) {
            Node* temp;
            // Case 1: no child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // Case 2: one child
            else if (root->left == NULL) {
                temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: two children (find inorder successor)
            else {
                Node* successor = root->right;
                while (successor->left != NULL)
                    successor = successor->left;
                root->data = successor->data;
                root->right = deleteLowScorers(root->right);
            }
        }
        return root;
    }

    // Find student with max score
    void findMaxScore(Node* root, Student &maxStudent) {
        if (root == NULL)
            return;

        if (root->data.score > maxStudent.score)
            maxStudent = root->data;

        findMaxScore(root->left, maxStudent);
        findMaxScore(root->right, maxStudent);
    }

    // Inorder display (sorted by name)
    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << "Name: " << root->data.name << ", Roll: " << root->data.roll
             << ", Score: " << root->data.score << endl;
        inorder(root->right);
    }

public:
    BST() { root = NULL; }

    void insert(Student s) {
        root = insert(root, s);
    }

    void search(string name) {
        if (search(root, name))
            cout << "? Student " << name << " found in BST.\n";
        else
            cout << "? Student " << name << " not found.\n";
    }

    void deleteLowScorers() {
        root = deleteLowScorers(root);
    }

    void display() {
        cout << "\n--- Students in BST (Inorder by Name) ---\n";
        inorder(root);
        cout << "----------------------------------------\n";
    }

    void displayMaxScoreStudent() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }
        Student maxS = root->data;
        findMaxScore(root, maxS);
        cout << "\n?? Student with Maximum Score:\n";
        maxS.display();
    }
};

//-----------------------------
// MAIN FUNCTION
//-----------------------------
int main() {
    srand(time(0));

    Student arr[10] = {
        {"Ali", 1, 15}, {"Sara", 2, 8}, {"Ahmed", 3, 22}, {"Zain", 4, 5},
        {"Mina", 5, 18}, {"Bilal", 6, 30}, {"Hina", 7, 12}, {"Omar", 8, 9},
        {"Taha", 9, 25}, {"Rida", 10, 17}
    };

    BST tree;

    cout << "\n?? Inserting 7 random students...\n";
    bool used[10] = {false};

    for (int i = 0; i < 7; i++) {
        int idx;
        do {
            idx = rand() % 10;
        } while (used[idx]);
        used[idx] = true;

        tree.insert(arr[idx]);
        cout << "Inserted: " << arr[idx].name << endl;
    }

    tree.display();

    cout << "\n?? Searching for 'Zain' and 'Sara'...\n";
    tree.search("Zain");
    tree.search("Sara");

    cout << "\n??? Deleting students with score < 10...\n";
    tree.deleteLowScorers();
    tree.display();

    tree.displayMaxScoreStudent();

    return 0;
}
