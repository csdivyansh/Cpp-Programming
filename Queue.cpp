#include <iostream>
#include <queue>
using namespace std;

class Queue {
    private: 
        int *arr;
        int qfront;
        int rear;
        int size;

public:
    Queue() {
        size = 100;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size){
            cout << "Queue is full!" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear){
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if(qfront == rear){
            return -1;
        }

        return arr[qfront];
    }

    void print() {
        cout << "Queue Contains: " << endl;
        for(int i = 0; i < 5; i++) {
            cout <<"| " << arr[i] << " |";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    int size = 1001;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // cout<< "Size of Queue is:" << q.size() <<endl;

    q.print();
    if(q.isEmpty())
        cout << "Queue is Empty!" << endl;
    else
        cout << "Queue is not Empty!" << endl;

    return 0;
}