#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, int value) {
    Node* newnode = new Node(value);
    if (head == NULL) {
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_linked_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    vector<int> fre(1005, 0);
    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;
        fre[value]++;
        if (fre[value] == 1) {
            insert_at_tail(head, tail, value);
        }
    }

    print_linked_list(head);

    return 0;
}
