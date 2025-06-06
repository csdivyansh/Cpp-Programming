#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node *prev;
        Node *next;
        //constructor
        Node(int data) {
            this -> prev = NULL;
            this -> data = data;
            this -> next = NULL;
        }
        ~Node() {
            int val = this -> data;
            if(next) {
                delete next;
                next = NULL;
            }
            cout << "Memory freed for data: " << val << endl;
        }
};

int getLength(Node* &head) {
    Node *temp = head;
    int len = 0;
    while(temp) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node*&head, Node*&tail, int data){
    Node *temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node*&head, Node* &tail, int data){
    Node *temp = new Node(data);
    if (tail == NULL) {
        tail = temp;
        head = temp;
        return;
    }
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node*&head, Node* &tail,int position, int data){
    if (position == 1){
        insertAtHead(head, tail, data);
        return;
    } else if (position == getLength(head) + 1){
        insertAtTail(head, tail, data);
        return;
    } else {
        Node *nodeToInsert = new Node(data);
        Node *temp = head;
        int count = 1;
        while(count++ < position - 1){
            temp = temp -> next;
        }
        nodeToInsert -> next = temp -> next;
        temp -> next -> prev = nodeToInsert;
        temp -> next = nodeToInsert;
        nodeToInsert -> prev = temp;       
    }
}

void deleteNode(Node*&head, Node*&tail, int position) {
    Node *temp = head;
    if (position == 1) {
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    } else {

        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while(count++ < position) {
            prev = curr;
            curr = curr -> next;
        }
        if (curr -> next == NULL){
            curr -> prev -> next = NULL;
            tail = curr -> prev;
            curr -> prev = NULL;
            delete curr;
        } else{
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
    cout << "Node Deleted!" << endl;
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

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    insertAtHead(head, tail, 8);
    print(head);
    insertAtHead(head, tail, 7);
    print(head);
    insertAtHead(head, tail, 6);
    print(head);

    insertAtTail(head, tail, 20);
    print(head);

    insertAtPosition(head, tail, 1, 100);
    print(head);

    insertAtPosition(head, tail, 5, 9);
    print(head);
    insertAtPosition(head, tail, 7, 101);
    print(head);

    deleteNode(head, tail, 1);
    print(head);
    deleteNode(head, tail, 3);
    print(head);
    deleteNode(head, tail, getLength(head));
    print(head);

    cout << "\n Length of List: " << getLength(head) << endl;
    cout << "\n Head: " << head -> data << endl;
    cout << "\n Tail: " << tail -> data << endl << endl;
    return 0;
}