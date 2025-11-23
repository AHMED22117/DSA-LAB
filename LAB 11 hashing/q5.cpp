#include <iostream>
using namespace std;

class StudentHashTable {
private:
    static const int size = 15;
    
    struct Record {
        int roll;
        string name;
        bool occupied;
    };

    Record table[size];

    int hashFunction(int roll) {
        return roll % size;
    }

public:
    StudentHashTable() {
        for (int i = 0; i < size; i++) {
            table[i].occupied = false;
        }
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < size; attempt++) {
            int newIndex = (index + attempt * attempt) % size;

            if (!table[newIndex].occupied) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                cout << "Inserted: " << name << " at index " << newIndex << endl;
                return;
            }
        }
        cout << "Table Full! Cannot insert.\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < size; attempt++) {
            int newIndex = (index + attempt * attempt) % size;

            if (table[newIndex].occupied && table[newIndex].roll == roll) {
                cout << "Found: " << table[newIndex].name << endl;
                return;
            }
        }

        cout << "Record not found!\n";
    }
};

int main() {
    StudentHashTable ht;

    ht.InsertRecord(15, "Ali");
    ht.InsertRecord(29, "Sara");
    ht.InsertRecord(44, "John");

    ht.SearchRecord(29);
    ht.SearchRecord(100);
}
