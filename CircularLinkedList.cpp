#include <iostream>
#include <map>
using namespace std;

class Node{
    public: 
        int data;
        Node *next;
        //constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
        //
        ~Node() {
            int val = this -> data;
            if(next) {
                delete next;
                next = NULL;
            }
            cout << "Memory freed for data: " << val << endl;
        }
};

void insertNode(Node *&tail, int element, int data) {
    Node *newNode = new Node(data);
    if (tail == NULL){
        tail = newNode;
        newNode -> next = newNode;
    } else {
        Node *curr = tail;
        while(curr -> data != element) {
            curr = curr -> next;
        }
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void deleteNode(Node *&tail, int value) {
    if (tail == NULL) {
        cout << "List is Empty" << endl;
        return;
    } else {
        Node *prev = tail;
        Node *curr = prev -> next;
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        if (curr == prev) {
            tail = NULL;
        }
        if (tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
    cout << "Deletion successfull!" << endl;
}

void print(Node* tail){
    cout << "-------------------------------------" << endl;
    Node *temp = tail;
    if (tail == NULL) {
        cout << "List is Empty!";
    }else {
        do{
            cout << "| " << temp -> data << " | ";
            temp = temp -> next;
        } while(tail != temp);
    }
    cout << endl;
}

Node* floydsCycleDetection(Node *&head){
    if(head == NULL){
        return head;
    }

    Node * slow = head;
    Node * fast = head;

    while(fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
        if (fast != NULL){
            fast = fast -> next;
        }
        if (slow == fast){
            return fast;
        }
    }
    return NULL;
}
bool detectLoop(Node *&head){
    if (head == NULL){
        return false;
    }
    map <Node*, bool> visited;
    Node * temp = head;

    while(temp != NULL){
        if (visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node * getStartingNode(Node * head){
    if (head == NULL){
        return NULL;
    }
    Node * fast = floydsCycleDetection(head);
    Node * slow = head;

    while(slow != fast){
        slow = slow-> next;
        fast = fast-> next;
    }

    return slow;
}   
void removeLoop(Node * head){
    Node * startOfLoop = getStartingNode(head);
    Node * temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}
int main() {
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    // deleteNode(tail, 9);
    // print(tail);
    // deleteNode(tail, 7);
    // print(tail);
    // deleteNode(tail, 5);
    // print(tail);


    if(floydsCycleDetection(tail)){
        cout << "Loop is present" << endl;

    }else {
        cout << "Not present" << endl;
    }

    Node * loop = getStartingNode(tail);

    cout << loop -> data << endl;

    removeLoop(tail);
    print(tail);

    cout << "-------------------------------------\n";
    return 0;
}