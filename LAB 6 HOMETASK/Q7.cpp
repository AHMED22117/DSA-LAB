    #include <iostream>
#include <string>
using namespace std;

class PatronQueue {
    string *arr;
    int capacity;
    int frontIdx;
    int sizeVal;
public:
    PatronQueue(int cap): capacity(cap) {
        arr = new string[cap];
        frontIdx = 0;
        sizeVal = 0;
    }
    ~PatronQueue() { delete[] arr; }

    bool enqueue(const string& name) {
        if (sizeVal == capacity) return false;
        int idx = (frontIdx + sizeVal) % capacity;
        arr[idx] = name;
        sizeVal++;
        return true;
    }

    string dequeue() {
        if (sizeVal == 0) return "";
        string v = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        sizeVal--;
        return v;
    }

    bool isEmpty() { return sizeVal == 0; }

    void display() {
        if (sizeVal == 0) { cout << "No patrons in queue.\n"; return; }
        cout << "Current queue: ";
        for (int i = 0; i < sizeVal; i++)
            cout << arr[(frontIdx + i) % capacity] << " ";
        cout << endl;
    }
};

int main() {
    PatronQueue q(50);
    q.enqueue("Alice");
    q.enqueue("Bob");
    q.enqueue("Carol");

    q.display();

    q.enqueue("Dave");
    cout << "\nAfter Dave joins:\n";
    q.display();

    cout << "\nProcessing transaction for: " << q.dequeue() << endl;
    q.display();

    cout << "\nProcessing transaction for: " << q.dequeue() << endl;
    q.display();

    return 0;
}
