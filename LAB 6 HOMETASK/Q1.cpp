#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> todo;
    todo.push("Meeting");
    todo.push("Emails");
    todo.push("Workout");
    if(!todo.empty()) cout << todo.top() << endl;
    todo.pop();
    cout << todo.size() << endl;
}
