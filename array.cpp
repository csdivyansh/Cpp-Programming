#include <iostream>
using namespace std;
// Arrays

void SwapAlternate(int arr[], int size) {
    int temp = 0;
    for (int i = 0; i < size; i+=2) {
        if (i + 1 < size){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void Reverse(int arr[], int size){
    int temp = 0;
    for (int i = 0; i < size / 2 ; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp; 
    }
}

bool LinearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;
            break;
        }
    }
    return false;
}

int getSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void PrintArr(int arr[], int size) {
    cout << "Printing the array :";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {

    int x[9] = {1,1,0,0,1,0,1,0};
    PrintArr(x,9);

    return 0;
}
