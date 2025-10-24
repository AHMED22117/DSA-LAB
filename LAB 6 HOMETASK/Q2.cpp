#include <iostream>
#include <stack>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d):data(d),next(NULL){}
};

void display(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    string sites[]={"Google","Facebook","Twitter","LinkedIn","Instagram"};
    Node* head=NULL;
    stack<string> s;
    for(int i=0;i<5;i++){
        Node* n=new Node(sites[i]);
        n->next=head;
        head=n;
        s.push(sites[i]);
    }
    s.pop();
    s.pop();
    head=head->next->next;
    display(head);
}
