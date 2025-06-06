#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int *arr;
        int size;

    public:
        Stack(int size){
            this->size = size;
            arr = new int[size];
            this-> top = -1;
        }

        void push(int data){
            if (size - top++ > 1){
                arr[top] = data;
            } else {
                cout << "Stack Overflow" << endl;
            }
        }

        void pop(){
            if (top != -1) {
                top--;
                cout << "Element Popped!" << endl;
            } else {
                cout << "Stack Underflow" << endl;
            }

        }

        bool isEmpty(){
            if (top == -1){ return true; }
            else {return false;}
        }

        int peek(){
            if (top == -1){
                cout << "Stack is Empty!" << endl;
                return -1;
            }
            return arr[top];
        }
};

int main(){

    Stack st(5);

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    

    return 0;
}