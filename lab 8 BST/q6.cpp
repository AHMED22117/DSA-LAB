#include <iostream>
using namespace std;

struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

class InventoryBST {
private:
    Node* root;

    Node* insert(Node* root, int id, int qty) {
        if (root == NULL)
            return new Node(id, qty);

        if (id == root->productID)
            root->quantity = qty; 
        else if (id < root->productID)
            root->left = insert(root->left, id, qty);
        else
            root->right = insert(root->right, id, qty);

        return root;
    }

    
    Node* search(Node* root, int id) {
        if (root == NULL || root->productID == id)
            return root;

        if (id < root->productID)
            return search(root->left, id);
        else
            return search(root->right, id);
    }

    void findMaxQuantity(Node* root, int& maxQty, int& maxID) {
        if (root == NULL)
            return;

        if (root->quantity > maxQty) {
            maxQty = root->quantity;
            maxID = root->productID;
        }

        findMaxQuantity(root->left, maxQty, maxID);
        findMaxQuantity(root->right, maxQty, maxID);
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << "ProductID: " << root->productID
             << ", Quantity: " << root->quantity << endl;
        inorder(root->right);
    }

public:
    InventoryBST() { root = NULL; }

    void insert(int id, int qty) {
        root = insert(root, id, qty);
    }

    void search(int id) {
        Node* result = search(root, id);
        if (result)
            cout << "? Product " << id << " found, Quantity = " << result->quantity << endl;
        else
            cout << "? Product " << id << " not found.\n";
    }

    void display() {
        cout << "Inventory (Inorder by Product ID)"<<endl;
        inorder(root);
        cout<<endl;
    }

    void getHighestStock() {
        if (root == NULL) {
            cout << "Inventory empty!\n";
            return;
        }
        int maxQty = -1, maxID = -1;
        findMaxQuantity(root, maxQty, maxID);
        cout << "\n?? Product with Highest Stock:\n";
        cout << "Product ID: " << maxID << ", Quantity: " << maxQty << endl;
    }
};
int main() {
    InventoryBST inventory;

    inventory.insert(101, 15);
    inventory.insert(105, 50);
    inventory.insert(102, 30);
    inventory.insert(110, 10);
    inventory.insert(108, 40);

    inventory.display();

    inventory.search(105);
    inventory.search(200);

    inventory.getHighestStock();

    return 0;
}
