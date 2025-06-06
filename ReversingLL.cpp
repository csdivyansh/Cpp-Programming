#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        //constructor()
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

Node * reverse(Node * &head){
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    
    Node * newHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}

void print(Node* head){
    cout << "----------------------------------------" << endl;
    Node *temp = head;
    while(temp) {
        cout << "| " << temp -> data << " | ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int data) {
    
    Node * temp = tail;
    Node * newNode = new Node(data);
    temp -> next = newNode;
    tail = newNode;

}

int main() {
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 20);
    print(head);
    insertAtTail(tail, 30);
    print(head);
    insertAtTail(tail, 40);
    print(head);
    insertAtTail(tail, 50);
    print(head);
    insertAtTail(tail, 60);
    print(head);
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;
    cout << "After Reversing: " << endl;
    Node * newhead = reverse(head);
    print(newhead);
    cout << "----------------------------------------" << endl;
    return 0;
}