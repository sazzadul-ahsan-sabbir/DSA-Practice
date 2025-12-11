#include <iostream>
using namespace std;

class Node {
public:
    long long data;
    Node* next;
    Node(long long val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertHead(long long val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        size++;
    }

    void insertTail(long long val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) 
        return; 

        if (index == 0) {
            Node* todelete = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete todelete;
            size--;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* todelete = temp->next;
        temp->next = todelete->next;
        if (todelete == tail) {
            tail = temp;
        }
        delete todelete;
        size--;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {

    int q;
    cin >> q;
    SinglyLinkedList list;

    for (int i = 0; i < q; i++) {
        int x; long long v;
        cin >> x >> v;

        if (x == 0) {
            list.insertHead(v);
        } else if (x == 1) {
            list.insertTail(v);
        } else if (x == 2) {
            list.deleteAtIndex((int)v);
        }

        list.printList();
    }
}
