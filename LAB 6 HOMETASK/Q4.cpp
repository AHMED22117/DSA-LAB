#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
using namespace std;

// ---------------- Stack Implementation (Linked List) ----------------
class StackNode {
public:
    string data;
    StackNode* next;
    StackNode(string v): data(v), next(NULL) {}
};

class LinkedStack {
    StackNode* topNode;
public:
    LinkedStack(): topNode(NULL) {}
    void push(const string& v) {
        StackNode* n = new StackNode(v);
        n->next = topNode;
        topNode = n;
    }
    string pop() {
        if (!topNode) return "";
        StackNode* t = topNode;
        string v = t->data;
        topNode = topNode->next;
        delete t;
        return v;
    }
    string top() {
        return topNode ? topNode->data : "";
    }
    bool isEmpty() {
        return topNode == NULL;
    }
    void printStackTopToBottom() {
        StackNode* t = topNode;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};
// --------------------------------------------------------------------

int prec(char c) {
    if (c == '^') return 4;
    if (c == '*' || c == '/') return 3;
    if (c == '+' || c == '-') return 2;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

vector<string> tokenize(const string& s) {
    vector<string> out;
    for (size_t i=0;i<s.size();) {
        if (isspace(s[i])) { i++; continue; }
        if (isalpha(s[i])) {
            string t;
            while (i<s.size() && isalpha(s[i])) t.push_back(s[i++]);
            out.push_back(t);
        } else if (isdigit(s[i]) || s[i]=='.') {
            string t;
            while (i<s.size() && (isdigit(s[i]) || s[i]=='.')) t.push_back(s[i++]);
            out.push_back(t);
        } else if (s[i]=='(' || s[i]==')' || isOperator(s[i]) || s[i]=='=') {
            if (s[i]=='(' && !out.empty()) {
                string prev = out.back();
                if (!prev.empty() && (isdigit(prev.back()) || prev.back()=='.' || prev=="x"))
                    out.push_back("*");
            }
            out.push_back(string(1,s[i]));
            i++;
        } else i++;
    }
    return out;
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    vector<string> out;
    vector<string> st;
    for (auto &tk: tokens) {
        if (tk=="(") st.push_back(tk);
        else if (tk==")") {
            while (!st.empty() && st.back()!="(") { out.push_back(st.back()); st.pop_back(); }
            if (!st.empty() && st.back()=="(") st.pop_back();
        } else if (tk.size()==1 && isOperator(tk[0])) {
            while (!st.empty() && st.back()!="(" &&
                   prec(st.back()[0]) >= prec(tk[0])) {
                out.push_back(st.back()); st.pop_back();
            }
            st.push_back(tk);
        } else out.push_back(tk);
    }
    while (!st.empty()) { out.push_back(st.back()); st.pop_back(); }
    return out;
}

double evalPostfix(const vector<string>& post) {
    vector<double> st;
    for (auto &tk: post) {
        if (tk.size()==1 && isOperator(tk[0])) {
            double b = st.back(); st.pop_back();
            double a = st.back(); st.pop_back();
            double r = 0;
            if (tk[0]=='+') r = a + b;
            if (tk[0]=='-') r = a - b;
            if (tk[0]=='*') r = a * b;
            if (tk[0]=='/') r = a / b;
            if (tk[0]=='^') r = pow(a,b);
            st.push_back(r);
        } else st.push_back(stod(tk));
    }
    return st.empty()?0:st.back();
}

int main() {
    string expr = "x=12+13-5(0.5+0.5)+1";
    vector<string> tokens = tokenize(expr);
    vector<string> toksForEval;
    for (auto &t: tokens) {
        if (t=="x" || t=="=") continue;
        toksForEval.push_back(t);
    }
    vector<string> post = infixToPostfix(toksForEval);
    double result = evalPostfix(post);

    LinkedStack finalStack;
    for (auto &t: tokens) finalStack.push(t);
    ostringstream ss; ss << result;
    finalStack.push(ss.str());

    cout << "Stack (top to bottom): ";
    finalStack.printStackTopToBottom();
    return 0;
}
