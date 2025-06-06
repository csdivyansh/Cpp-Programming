#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node * prev;

        //Constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

void insertAtTail(Node * &tail, int data){
    Node * newNode = new Node(data);

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void print(Node* &head){
    if (head == NULL) {
        cout << "-------------------------------------" << endl;
        cout << "Empty list" << endl;
        return;
    }

    Node *temp = head;
    cout << "-------------------------------------" << endl;
    while(temp) {
        cout << "| " << temp -> data << " | ";
        temp = temp -> next;
    }
    cout << endl;
}

void reverseDLL(Node * &head, Node * &tail) {
    tail = head;
    if (head == NULL || head -> next == NULL){
        cout << "-------------------------------------" << endl;
        cout << "Empty List" << endl;
        cout << "-------------------------------------" << endl;

    }

    Node * curr = head;
    Node * temp = NULL;

    while(curr){
        temp = curr -> prev; 
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }
    head = temp -> prev;
}

int main() {
   
   Node * list = new Node(10);
   Node * head = NULL;
   Node * tail = NULL;
//    print(head);
//    insertAtTail(tail, 20);
//    print(head);
//    insertAtTail(tail, 30);
//    print(head);
//    insertAtTail(tail, 40);
//    print(head);

   reverseDLL(head, tail);
   print(head);
   
   cout << "\n Head points to: " << head -> data << endl;
   cout << "\n Tail points to: " << tail -> data << endl << endl;
   return 0;
}