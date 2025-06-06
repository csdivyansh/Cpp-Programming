#include <iostream>
using namespace std;
// Jagged Arrays
/*
| 1 | 2 | 3|
| 4 | 5 | 6 | 7 |
*/

void printArr(int *arr, int size) {
    cout << endl;
    cout << "Array:\n| "; 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " | ";
    }
    cout << endl;
    cout << endl;
}

int main() {
    
    int **arr = new int *[2];
    arr[0] = new int[1];
    printArr(arr)
    return 0;
}