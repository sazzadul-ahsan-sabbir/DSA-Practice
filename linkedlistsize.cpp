#include<bits/stdc++.h>
using namespace std;
class 
{
   struct Node
   {
       int data;
       Node* next;

       Node(int val){
       int data=val;
       next= NULL;
   }
    
};   //funtion to insert a node at the node
void  insert_at_end(Node* &head,int val){
Node* newnode=new Node( val);

if(head==NULL){
    head=newnode;
    return;
}
Node* tmp=newnode;
while (tmp->next!=NULL)
{
   tmp=tmp->next;
}
  tmp->next=newnode;
}
//function print in linked list
void printlinkedlist(Node* &head){
  Node* tmp=head;
  while(tmp!=NULL){
    cout<<tmp->data<< endl;
  }
  tmp=tmp->next;
}

int getsize(Node* &head){
if (int count=0){
Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
}
int main(){
 Node* head = nullptr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert_at_end(head, val);
    }

    // Print the list
   printlinkedlist(head);

    // Print the size
    cout << getsize(head) << endl;

    return 0;
}
}