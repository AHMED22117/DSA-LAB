#include <iostream>
using namespace std;

class ArrayQueue {
    int *arr;
    int capacity;
    int frontIdx;
    int sizeVal;
public:
    ArrayQueue(int cap): capacity(cap) {
        arr = new int[cap];
        frontIdx = 0;
        sizeVal = 0;
    }
    ~ArrayQueue() { delete[] arr; }

    bool enqueue(int v) {
        if (sizeVal == capacity) return false;
        int idx = (frontIdx + sizeVal) % capacity;
        arr[idx] = v;
        sizeVal++;
        return true;
    }

    int dequeue() {
        if (sizeVal == 0) return -1;
        int v = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        sizeVal--;
        return v;
    }

    bool isEmpty() { return sizeVal == 0; }

    void display() {
        if (sizeVal == 0) { cout << "Empty Queue\n"; return; }
        for (int i = 0; i < sizeVal; i++)
            cout << arr[(frontIdx + i) % capacity] << " ";
        cout << endl;
    }
};

int main() {
    int ids[] = {13,7,4,1,6,8,10};
    ArrayQueue q(20);
    for (int i = 0; i < 7; i++) q.enqueue(ids[i]);

    cout << "Initial Queue: ";
    q.display();

    cout << "Processing customers:\n";
    while (!q.isEmpty()) {
        int served = q.dequeue();
        cout << "Served: " << served << endl;
    }
    return 0;
}
