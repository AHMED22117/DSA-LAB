#include <iostream>
using namespace std;

struct Pair {
    int a, b;
    bool used;
};

int hashFunction(int x, int size) {
    return x % size;
}

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a fixed-size hash table (simple array of Pair)
    const int TABLE_SIZE = 100; 
    Pair hashTable[TABLE_SIZE];

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].used = false;

    bool found = false;

    // Check all unique pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            int index = hashFunction(sum, TABLE_SIZE);

            // If entry exists ? check if it forms a valid distinct pair
            if (hashTable[index].used) {
                int a = hashTable[index].a;
                int b = hashTable[index].b;

                // Ensure all numbers are distinct
                if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                    cout << "Pair 1: (" << a << ", " << b << ")\n";
                    cout << "Pair 2: (" << arr[i] << ", " << arr[j] << ")\n";
                    found = true;
                    return 0;  
                }
            } 
            else {
                // Insert new pair
                hashTable[index].a = arr[i];
                hashTable[index].b = arr[j];
                hashTable[index].used = true;
            }
        }
    }

    if (!found)
        cout << "No pairs found\n";

    return 0;
}
