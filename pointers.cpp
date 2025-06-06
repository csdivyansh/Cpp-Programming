#include <iostream>
using namespace std;

int main() {
    
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;
    int ***ptr3 = &ptr2;

    cout << i << endl;
    cout << *ptr << endl;
    cout << **ptr2 << endl;
    cout << ***ptr3 << endl;

    return 0;
}