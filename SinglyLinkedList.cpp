#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        //constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
        //destructor
        ~Node(){
            int value = this -> data;
            if (this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }

        }
        
};
void insertAtHead(Node* & head, int data){
    Node * temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* & tail, int data){
    Node * temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail, int position, int data) {
    //if its first position (head)
    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while(cnt++ < position - 1){
        temp = temp -> next;
    }
    //if its last position
    if (temp -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node *NodeToInsert = new Node(data);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;

}

void deleteNode(int position, Node* &head, Node * &tail){
    cout << "Node deleted!" << endl;
    Node *curr = head;
    if (position == 1){
        head = head -> next;
        curr -> next = NULL;
        delete curr;
        return;
    } else {
        Node* prev = NULL;
        int count = 1;

        while(count++ < position){
            prev = curr;
            curr = curr -> next;
        }
        if (curr -> next == NULL) {
            prev -> next = NULL;
            tail = prev;
            return;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}

void print(Node* &head){
    Node *temp = head;
    while(temp) {
        if (temp -> next == NULL){
            cout << temp -> data << " -> null" << endl;
            return;
        }
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* detectLoopBY_FLOYD_ALGO(Node *&head){
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

Node * getStartingNode(Node * head){
    if (head == NULL){
        return NULL;
    }
    Node * fast = detectLoopBY_FLOYD_ALGO(head);
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

Node* getMiddle(Node* head) {
    Node * slow = head;
    Node * fast = head -> next;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node * merge(Node* left, Node* right){
    if (left == NULL){ return right;}
    if (right == NULL){ return left;}

    Node * ans = new Node(-1);
    Node * temp = ans;
    while(left && right) {
        if (left-> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while (left){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while (right) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    return ans-> next;
        
}

Node* mergeSort(Node *head) {
    if (head == NULL || head -> next == NULL){
        return head;
    }

    Node * mid = getMiddle(head);
    Node * left = head;
    Node * right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node * result = merge(left, right);

    return result;
}


int main() {

    Node *Node1 = new Node(100);

    Node *head = Node1;
    Node *tail = Node1;

    insertAtTail(tail, 18);
    insertAtTail(tail, 15);
    insertAtTail(tail, 120);
    insertAtTail(tail, 20);
    insertAtTail(tail, 17);
    insertAtTail(tail, 6);

    cout << "With sort list: " << endl;
    print(head);
    Node * newHead = mergeSort(head);
    cout << "Without sort list: " << endl;
    print(newHead);
    
    return 0;
}