// Linked List

#include <iostream>
using namespace std;

class Node {
	
	public:
		int data;
		Node *next;
		
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
		
};

void insert(Node * &tail, int data){
	Node * temp = new Node(data);
	tail -> next = temp;
	tail = temp;
}

void print(Node * head){
	Node * temp = head;
	while(temp) {
		if (temp  -> next == NULL) {
			cout << temp -> data << " -> X";
			break;
		} 
		
		cout << temp -> data << " -> ";
		temp = temp -> next;
		
	}
	
	cout << endl;
	
}

int main() {
	
	Node * head = new Node(10);
	Node * tail = head;
	insert(tail, 20);
	insert(tail, 30);
	insert(tail, 40);
	insert(tail, 50);
	insert(tail, 60);
	
	
	print(head);
	return 0;
}