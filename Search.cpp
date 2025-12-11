#include <iostream>
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

int find_index(Node* head, int x) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) return cnt;
        temp = temp->next;
        cnt++;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node* head = NULL;
        Node* tail = NULL;

        int val;
        while (cin >> val && val != -1) {
            insert_at_tail(head, tail, val);
        }

        int x;
        cin >> x;

        cout << find_index(head, x) << endl;
    }

}
