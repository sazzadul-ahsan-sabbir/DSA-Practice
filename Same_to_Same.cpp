#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

bool areSame(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) 
        return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL && temp2 == NULL) 
    return true;
    else 
    return false;
}

int main() {
    Node* head1 = NULL; Node* tail1 = NULL;
    Node* head2 = NULL; Node* tail2 = NULL;

    int val;
    while ( cin >> val && val != -1) {
        insert_at_tail(head1, tail1, val);
    }
    while (cin >> val && val != -1) {
        insert_at_tail(head2, tail2, val);
    }

    if (areSame(head1, head2)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
