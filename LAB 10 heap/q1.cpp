#include <iostream>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;

public:
    MaxHeap() { size = 0; }

    void swapVal(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insert(int val) {
        arr[++size] = val;
        int i = size;
        while (i > 1 && arr[i / 2] < arr[i]) {
            swapVal(arr[i], arr[i / 2]);
            i /= 2;
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= size && arr[left] > arr[largest])
            largest = left;
        if (right <= size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swapVal(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void updatekey(int i, int newval) {
        if (i < 1 || i > size) {
            cout << "Invalid index!\n";
            return;
        }

        int oldval = arr[i];
        arr[i] = newval;

        if (newval > oldval) {
            
            while (i > 1 && arr[i / 2] < arr[i]) {
                swapVal(arr[i], arr[i / 2]);
                i /= 2;
            }
        } else {

            heapifyDown(i);
        }
    }


    void delete_element(int i) {
        if (i < 1 || i > size) {
            cout << "Invalid index!\n";
            return;
        }

        cout << "Deleting element: " << arr[i] << endl;

        arr[i] = arr[size--]; 
        heapifyDown(i);
    }


    void display() {
        cout << "Heap: ";
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    int values[] = {8, 7, 6, 5, 4};


    for (int i = 0; i < 5; i++)
        h.insert(values[i]);

    cout << "Initial Max Heap:\n";
    h.display();

    cout << "\nUpdating index 3 to value 10:\n";
    h.updatekey(3, 10);
    h.display();

    cout << "\nDeleting element at index 2:\n";
    h.delete_element(2);
    h.display();

    return 0;
}
