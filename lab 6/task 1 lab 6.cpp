#include <iostream>
using namespace std;

class Stack {
    char arr[100];  
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top < 99) {
            arr[++top] = c;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack Underflow\n";
            return '\0'; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string str = "BORROWROB";
    Stack stack;

    for (int i=0;i<9;i++) {
        stack.push(str[i]);
    }

    string reversed = "";
    while (!stack.isEmpty()) {
        reversed += stack.pop();
    }

    if (str == reversed) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is NOT a palindrome." << endl;
    }

    return 0;
}