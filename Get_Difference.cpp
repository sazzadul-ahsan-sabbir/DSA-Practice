#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insert_at_tail(node*& head, node*& tail, int val) {
    node* newnode = new node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

int maxdifference(node* head) {
    if (head == NULL) return 0;

    int max_val = head->data;
    int min_val = head->data;

    node* temp = head;
    while (temp != NULL) {
        if (temp->data > max_val) max_val = temp->data;
        if (temp->data < min_val) min_val = temp->data;
        temp = temp->next;
    }

    return max_val - min_val;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;

    while (cin >> val && val != -1) {
        insert_at_tail(head, tail, val);
    }


    cout << maxdifference(head) << endl;

}
